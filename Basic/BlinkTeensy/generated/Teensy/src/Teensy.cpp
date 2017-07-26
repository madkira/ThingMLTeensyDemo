#include "Blinker.h"
#include "thingml_typedefs.h"
#include "runtime.h"



/*****************************************************************************
 * Definitions for configuration : Teensy
 *****************************************************************************/

//Declaration of instance variables
//Instance blinker
// Variables for the properties of the instance
struct Blinker_Instance blinker_var;
// Variables for the sessions of the instance


// Enqueue of messages Blinker::basic::blinking
void enqueue_Blinker_send_basic_blinking(struct Blinker_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_basic >> 8) & 0xFF );
_fifo_enqueue( _instance->id_basic & 0xFF );
}
}


//New dispatcher for messages
void dispatch_blinking(uint16_t sender) {
if (sender == blinker_var.id_basic) {
Blinker_handle_basic_blinking(&blinker_var);

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 1:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_blinking = 2;
dispatch_blinking((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_Teensy() {
// Initialize connectors
register_Blinker_send_basic_blinking_listener(&enqueue_Blinker_send_basic_blinking);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance blinker
blinker_var.active = true;
blinker_var.id_basic = add_instance( (void*) &blinker_var);
blinker_var.Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_OFF_STATE;

Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_STATE, &blinker_var);
}




int main(){

	initialize_configuration_Teensy();


	while(1) {
	
// Network Listener// End Network Listener


	    processMessageQueue();
	}

}