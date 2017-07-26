#include "Blinker.h"
/*****************************************************************************
 * Implementation for type : Blinker
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Blinker

#define MORSE_UNIT 200000
extern struct Blinker_Instance blinker_var;
IntervalTimer blink_timer;
boolean current_blink = HIGH;

// END: Code from the c_global annotation Blinker

// Declaration of prototypes:
//Prototypes: State Machine
void Blinker_BlinkerState_OnExit(int state, struct Blinker_Instance *_instance);
//Prototypes: Message Sending
void Blinker_send_evt_blink(struct Blinker_Instance *_instance);
void Blinker_send_evt_enderreur(struct Blinker_Instance *_instance);
//Prototypes: Function
void f_Blinker_timer_message(struct Blinker_Instance *_instance, uint32_t time);
void callback_message();
// Declaration of functions:
// Definition of function timer_message
void f_Blinker_timer_message(struct Blinker_Instance *_instance, uint32_t time) {
blink_timer.begin(&callback_message, time*MORSE_UNIT);
}
// Definition of function callback_message
void callback_message() {

		Blinker_send_evt_blink(&blinker_var);
}

// Sessions functionss:


// On Entry Actions:
void Blinker_BlinkerState_OnEntry(int state, struct Blinker_Instance *_instance) {
switch(state) {
case BLINKER_BLINKERSTATE_STATE:{
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_IDLE_STATE;
pinMode(13, OUTPUT);
    				blink_timer = IntervalTimer();
Blinker_BlinkerState_OnEntry(_instance->Blinker_BlinkerState_State, _instance);
break;
}
case BLINKER_BLINKERSTATE_IDLE_STATE:{
digitalWriteFast(13, HIGH);
break;
}
case BLINKER_BLINKERSTATE_ERRBEGIN_STATE:{
digitalWriteFast(13, LOW);
    			current_blink = HIGH;
f_Blinker_timer_message(_instance, 20);
break;
}
case BLINKER_BLINKERSTATE_MESSAGE_STATE:{
digitalWriteFast(13, current_blink);
        		current_blink = (current_blink == HIGH)? LOW : HIGH;
uint8_t val = get_time();
if(val == 0) {
reset();
Blinker_send_evt_enderreur(_instance);

} else {
f_Blinker_timer_message(_instance, val);

}
break;
}
default: break;
}
}

// On Exit Actions:
void Blinker_BlinkerState_OnExit(int state, struct Blinker_Instance *_instance) {
switch(state) {
case BLINKER_BLINKERSTATE_STATE:{
Blinker_BlinkerState_OnExit(_instance->Blinker_BlinkerState_State, _instance);
break;}
case BLINKER_BLINKERSTATE_IDLE_STATE:{
break;}
case BLINKER_BLINKERSTATE_ERRBEGIN_STATE:{
break;}
case BLINKER_BLINKERSTATE_MESSAGE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Blinker_handle_evt_enderreur(struct Blinker_Instance *_instance) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
if (_instance->Blinker_BlinkerState_State == BLINKER_BLINKERSTATE_MESSAGE_STATE) {
if (Blinker_BlinkerState_State_event_consumed == 0 && 1) {
Blinker_BlinkerState_OnExit(BLINKER_BLINKERSTATE_MESSAGE_STATE, _instance);
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_IDLE_STATE;
Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_IDLE_STATE, _instance);
Blinker_BlinkerState_State_event_consumed = 1;
}
}
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
}
void Blinker_handle_evt_blink(struct Blinker_Instance *_instance) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
if (_instance->Blinker_BlinkerState_State == BLINKER_BLINKERSTATE_ERRBEGIN_STATE) {
if (Blinker_BlinkerState_State_event_consumed == 0 && 1) {
Blinker_BlinkerState_OnExit(BLINKER_BLINKERSTATE_ERRBEGIN_STATE, _instance);
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_MESSAGE_STATE;
Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_MESSAGE_STATE, _instance);
Blinker_BlinkerState_State_event_consumed = 1;
}
}
else if (_instance->Blinker_BlinkerState_State == BLINKER_BLINKERSTATE_MESSAGE_STATE) {
if (Blinker_BlinkerState_State_event_consumed == 0 && 1) {
Blinker_BlinkerState_OnExit(BLINKER_BLINKERSTATE_MESSAGE_STATE, _instance);
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_MESSAGE_STATE;
Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_MESSAGE_STATE, _instance);
Blinker_BlinkerState_State_event_consumed = 1;
}
}
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
}
void Blinker_handle_err_erreur(struct Blinker_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
if (_instance->Blinker_BlinkerState_State == BLINKER_BLINKERSTATE_IDLE_STATE) {
if (Blinker_BlinkerState_State_event_consumed == 0 && 1) {
Blinker_BlinkerState_OnExit(BLINKER_BLINKERSTATE_IDLE_STATE, _instance);
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_ERRBEGIN_STATE;
set_code(id);
Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_ERRBEGIN_STATE, _instance);
Blinker_BlinkerState_State_event_consumed = 1;
}
}
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
}

// Observers for outgoing messages:
void (*external_Blinker_send_evt_blink_listener)(struct Blinker_Instance *)= 0x0;
void (*Blinker_send_evt_blink_listener)(struct Blinker_Instance *)= 0x0;
void register_external_Blinker_send_evt_blink_listener(void (*_listener)(struct Blinker_Instance *)){
external_Blinker_send_evt_blink_listener = _listener;
}
void register_Blinker_send_evt_blink_listener(void (*_listener)(struct Blinker_Instance *)){
Blinker_send_evt_blink_listener = _listener;
}
void Blinker_send_evt_blink(struct Blinker_Instance *_instance){
if (Blinker_send_evt_blink_listener != 0x0) Blinker_send_evt_blink_listener(_instance);
if (external_Blinker_send_evt_blink_listener != 0x0) external_Blinker_send_evt_blink_listener(_instance);
;
}
void (*external_Blinker_send_evt_enderreur_listener)(struct Blinker_Instance *)= 0x0;
void (*Blinker_send_evt_enderreur_listener)(struct Blinker_Instance *)= 0x0;
void register_external_Blinker_send_evt_enderreur_listener(void (*_listener)(struct Blinker_Instance *)){
external_Blinker_send_evt_enderreur_listener = _listener;
}
void register_Blinker_send_evt_enderreur_listener(void (*_listener)(struct Blinker_Instance *)){
Blinker_send_evt_enderreur_listener = _listener;
}
void Blinker_send_evt_enderreur(struct Blinker_Instance *_instance){
if (Blinker_send_evt_enderreur_listener != 0x0) Blinker_send_evt_enderreur_listener(_instance);
if (external_Blinker_send_evt_enderreur_listener != 0x0) external_Blinker_send_evt_enderreur_listener(_instance);
;
}



