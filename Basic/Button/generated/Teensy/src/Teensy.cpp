#include "SoftButton.h"
#include "Button.h"
#include "Communication.h"
#include "Blinker.h"
#include "thingml_typedefs.h"
#include "runtime.h"



/*****************************************************************************
 * Definitions for configuration : Teensy
 *****************************************************************************/

//Declaration of instance variables
//Instance communication
// Variables for the properties of the instance
struct Communication_Instance communication_var;
// Variables for the sessions of the instance
//Instance button
// Variables for the properties of the instance
struct Button_Instance button_var;
// Variables for the sessions of the instance
//Instance blinker
// Variables for the properties of the instance
struct Blinker_Instance blinker_var;
// Variables for the sessions of the instance
//Instance softButton
// Variables for the properties of the instance
struct SoftButton_Instance softButton_var;
// Variables for the sessions of the instance


// Enqueue of messages Communication::Blinker::erreur
void enqueue_Communication_send_Blinker_erreur(struct Communication_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Blinker >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Blinker & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Button::clock::ms25_tic
void enqueue_Button_send_clock_ms25_tic(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_clock >> 8) & 0xFF );
_fifo_enqueue( _instance->id_clock & 0xFF );
}
}
// Enqueue of messages Button::evt::press
void enqueue_Button_send_evt_press(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}
// Enqueue of messages Button::evt::release
void enqueue_Button_send_evt_release(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}
// Enqueue of messages Blinker::evt::blink
void enqueue_Blinker_send_evt_blink(struct Blinker_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}
// Enqueue of messages Blinker::evt::enderreur
void enqueue_Blinker_send_evt_enderreur(struct Blinker_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}
// Enqueue of messages SoftButton::Timer::timer_timeout
void enqueue_SoftButton_send_Timer_timer_timeout(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Timer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Timer & 0xFF );
}
}
// Enqueue of messages SoftButton::SoftButton::long_press
void enqueue_SoftButton_send_SoftButton_long_press(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_SoftButton >> 8) & 0xFF );
_fifo_enqueue( _instance->id_SoftButton & 0xFF );
}
}
// Enqueue of messages SoftButton::SoftButton::double_click
void enqueue_SoftButton_send_SoftButton_double_click(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_SoftButton >> 8) & 0xFF );
_fifo_enqueue( _instance->id_SoftButton & 0xFF );
}
}
// Enqueue of messages SoftButton::SoftButton::click
void enqueue_SoftButton_send_SoftButton_click(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_SoftButton >> 8) & 0xFF );
_fifo_enqueue( _instance->id_SoftButton & 0xFF );
}
}


//New dispatcher for messages
void dispatch_press(uint16_t sender) {
if (sender == button_var.id_evt) {
SoftButton_handle_Button_press(&softButton_var);

}
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_ms25_tic(uint16_t sender) {
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {
Button_handle_clock_ms25_tic(&button_var);

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_long_press(uint16_t sender) {
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_SoftButton) {
Communication_handle_Button_long_press(&communication_var);

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_release(uint16_t sender) {
if (sender == button_var.id_evt) {
SoftButton_handle_Button_release(&softButton_var);

}
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_erreur(uint16_t sender, uint8_t param_id) {
if (sender == communication_var.id_Blinker) {
Blinker_handle_err_erreur(&blinker_var, param_id);

}
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_double_click(uint16_t sender) {
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_SoftButton) {
Communication_handle_Button_double_click(&communication_var);

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_blink(uint16_t sender) {
if (sender == blinker_var.id_evt) {
Blinker_handle_evt_blink(&blinker_var);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender) {
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {
SoftButton_handle_Timer_timer_timeout(&softButton_var);

}

}


//New dispatcher for messages
void dispatch_click(uint16_t sender) {
if (sender == blinker_var.id_evt) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_SoftButton) {

}
if (sender == softButton_var.id_Timer) {

}

}


//New dispatcher for messages
void dispatch_enderreur(uint16_t sender) {
if (sender == blinker_var.id_evt) {
Blinker_handle_evt_enderreur(&blinker_var);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

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
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_press = 2;
dispatch_press((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 2:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_ms25_tic = 2;
dispatch_ms25_tic((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_long_press = 2;
dispatch_long_press((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_release = 2;
dispatch_release((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_erreur = 2;
union u_erreur_id_t {
uint8_t p;
byte bytebuffer[1];
} u_erreur_id;
u_erreur_id.bytebuffer[0] = mbuf[mbufi_erreur + 0];
mbufi_erreur += 1;
dispatch_erreur((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_erreur_id.p /* id */ );
break;
}
case 9:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_double_click = 2;
dispatch_double_click((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_blink = 2;
dispatch_blink((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_timeout = 2;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 10:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_click = 2;
dispatch_click((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_enderreur = 2;
dispatch_enderreur((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_Teensy() {
// Initialize connectors
register_Communication_send_Blinker_erreur_listener(&enqueue_Communication_send_Blinker_erreur);
register_Button_send_clock_ms25_tic_listener(&enqueue_Button_send_clock_ms25_tic);
register_Button_send_evt_press_listener(&enqueue_Button_send_evt_press);
register_Button_send_evt_release_listener(&enqueue_Button_send_evt_release);
register_Blinker_send_evt_blink_listener(&enqueue_Blinker_send_evt_blink);
register_Blinker_send_evt_enderreur_listener(&enqueue_Blinker_send_evt_enderreur);
register_SoftButton_send_Timer_timer_timeout_listener(&enqueue_SoftButton_send_Timer_timer_timeout);
register_SoftButton_send_SoftButton_click_listener(&enqueue_SoftButton_send_SoftButton_click);
register_SoftButton_send_SoftButton_double_click_listener(&enqueue_SoftButton_send_SoftButton_double_click);
register_SoftButton_send_SoftButton_long_press_listener(&enqueue_SoftButton_send_SoftButton_long_press);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance button
button_var.active = true;
button_var.id_clock = add_instance( (void*) &button_var);
button_var.id_evt = add_instance( (void*) &button_var);
button_var.Button_Button_State = BUTTON_BUTTON_RELEASED_STATE;
button_var.Button_PIN_var = 7;

Button_Button_OnEntry(BUTTON_BUTTON_STATE, &button_var);
// Init the ID, state variables and properties for instance softButton
softButton_var.active = true;
softButton_var.id_Button = add_instance( (void*) &softButton_var);
softButton_var.id_Timer = add_instance( (void*) &softButton_var);
softButton_var.id_SoftButton = add_instance( (void*) &softButton_var);
softButton_var.SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE;
softButton_var.SoftButton_long_delay_var = 1000;
softButton_var.SoftButton_double_delay_var = 250;

SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_STATE, &softButton_var);
// Init the ID, state variables and properties for instance blinker
blinker_var.active = true;
blinker_var.id_evt = add_instance( (void*) &blinker_var);
blinker_var.id_err = add_instance( (void*) &blinker_var);
blinker_var.Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_IDLE_STATE;

Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_STATE, &blinker_var);
// Init the ID, state variables and properties for instance communication
communication_var.active = true;
communication_var.id_Blinker = add_instance( (void*) &communication_var);
communication_var.id_Button = add_instance( (void*) &communication_var);
communication_var.Communication_Main_State = COMMUNICATION_MAIN_IDLE_STATE;

Communication_Main_OnEntry(COMMUNICATION_MAIN_STATE, &communication_var);
}




int main(){

	initialize_configuration_Teensy();


	while(1) {
	
// Network Listener// End Network Listener


	    processMessageQueue();
	}

}