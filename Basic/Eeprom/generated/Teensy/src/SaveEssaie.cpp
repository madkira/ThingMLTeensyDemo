#include "SaveTest.h"
#include "Save.h"
#include "thingml_typedefs.h"
#include "runtime.h"



/*****************************************************************************
 * Definitions for configuration : SaveEssaie
 *****************************************************************************/

//Declaration of instance variables
//Instance saveTest
// Variables for the properties of the instance
struct SaveTest_Instance saveTest_var;
// Variables for the sessions of the instance
//Instance save
// Variables for the properties of the instance
struct Save_Instance save_var;
// Variables for the sessions of the instance


// Enqueue of messages SaveTest::saveact::writebyte
void enqueue_SaveTest_send_saveact_writebyte(struct SaveTest_Instance *_instance, uint8_t id, uint8_t val){
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_saveact >> 8) & 0xFF );
_fifo_enqueue( _instance->id_saveact & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );

// parameter val
union u_val_t {
uint8_t p;
byte bytebuffer[1];
} u_val;
u_val.p = val;
_fifo_enqueue(u_val.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages SaveTest::aquireact::readbyte
void enqueue_SaveTest_send_aquireact_readbyte(struct SaveTest_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_aquireact >> 8) & 0xFF );
_fifo_enqueue( _instance->id_aquireact & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Save::Reader::byteread
void enqueue_Save_send_Reader_byteread(struct Save_Instance *_instance, uint8_t val){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Reader >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Reader & 0xFF );

// parameter val
union u_val_t {
uint8_t p;
byte bytebuffer[1];
} u_val;
u_val.p = val;
_fifo_enqueue(u_val.bytebuffer[0] & 0xFF );
}
}


//New dispatcher for messages
void dispatch_readbyte(uint16_t sender, uint8_t param_id) {
if (sender == saveTest_var.id_aquireact) {
Save_handle_Reader_readbyte(&save_var, param_id);

}

}


//New dispatcher for messages
void dispatch_bytewrite(uint16_t sender) {
if (sender == save_var.id_Writer) {

}

}


//New dispatcher for messages
void dispatch_byteread(uint16_t sender, uint8_t param_val) {
if (sender == save_var.id_Reader) {
SaveTest_handle_aquireact_byteread(&saveTest_var, param_val);

}

}


//New dispatcher for messages
void dispatch_writebyte(uint16_t sender, uint8_t param_id, uint8_t param_val) {
if (sender == saveTest_var.id_saveact) {
Save_handle_Writer_writebyte(&save_var, param_id, param_val);

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
case 2:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_readbyte = 2;
union u_readbyte_id_t {
uint8_t p;
byte bytebuffer[1];
} u_readbyte_id;
u_readbyte_id.bytebuffer[0] = mbuf[mbufi_readbyte + 0];
mbufi_readbyte += 1;
dispatch_readbyte((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_readbyte_id.p /* id */ );
break;
}
case 1:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_writebyte = 2;
union u_writebyte_id_t {
uint8_t p;
byte bytebuffer[1];
} u_writebyte_id;
u_writebyte_id.bytebuffer[0] = mbuf[mbufi_writebyte + 0];
mbufi_writebyte += 1;
union u_writebyte_val_t {
uint8_t p;
byte bytebuffer[1];
} u_writebyte_val;
u_writebyte_val.bytebuffer[0] = mbuf[mbufi_writebyte + 0];
mbufi_writebyte += 1;
dispatch_writebyte((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_writebyte_id.p /* id */ ,
 u_writebyte_val.p /* val */ );
break;
}
case 3:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_byteread = 2;
union u_byteread_val_t {
uint8_t p;
byte bytebuffer[1];
} u_byteread_val;
u_byteread_val.bytebuffer[0] = mbuf[mbufi_byteread + 0];
mbufi_byteread += 1;
dispatch_byteread((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_byteread_val.p /* val */ );
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_SaveEssaie() {
// Initialize connectors
register_SaveTest_send_saveact_writebyte_listener(&enqueue_SaveTest_send_saveact_writebyte);
register_SaveTest_send_aquireact_readbyte_listener(&enqueue_SaveTest_send_aquireact_readbyte);
register_Save_send_Reader_byteread_listener(&enqueue_Save_send_Reader_byteread);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance save
save_var.active = true;
save_var.id_Reader = add_instance( (void*) &save_var);
save_var.id_Writer = add_instance( (void*) &save_var);
save_var.Save_EESave_State = SAVE_EESAVE_IDLE_STATE;

Save_EESave_OnEntry(SAVE_EESAVE_STATE, &save_var);
// Init the ID, state variables and properties for instance saveTest
saveTest_var.active = true;
saveTest_var.id_saveact = add_instance( (void*) &saveTest_var);
saveTest_var.id_aquireact = add_instance( (void*) &saveTest_var);
saveTest_var.SaveTest_TestSaver_State = SAVETEST_TESTSAVER_IDLE_STATE;

SaveTest_TestSaver_OnEntry(SAVETEST_TESTSAVER_STATE, &saveTest_var);
}




int main(){

	initialize_configuration_SaveEssaie();


	while(1) {
	
// Network Listener// End Network Listener


	    processMessageQueue();
	}

}