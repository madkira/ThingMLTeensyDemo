#include "Blinker.h"
/*****************************************************************************
 * Implementation for type : Blinker
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Blinker

extern struct Blinker_Instance blinker_var;
IntervalTimer timer;
// END: Code from the c_global annotation Blinker

// Declaration of prototypes:
//Prototypes: State Machine
void Blinker_BlinkerState_OnExit(int state, struct Blinker_Instance *_instance);
//Prototypes: Message Sending
void Blinker_send_basic_blinking(struct Blinker_Instance *_instance);
//Prototypes: Function
void f_Blinker_timer_blinker(struct Blinker_Instance *_instance, uint32_t time);
void callback_blinker();
// Declaration of functions:
// Definition of function timer_blinker
void f_Blinker_timer_blinker(struct Blinker_Instance *_instance, uint32_t time) {
timer.begin(&callback_blinker, time);
}
// Definition of function callback_blinker
void callback_blinker() {
Blinker_send_basic_blinking(&blinker_var);
}

// Sessions functionss:


// On Entry Actions:
void Blinker_BlinkerState_OnEntry(int state, struct Blinker_Instance *_instance) {
switch(state) {
case BLINKER_BLINKERSTATE_STATE:{
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_OFF_STATE;
pinMode(13, OUTPUT);
    				timer = IntervalTimer();
Blinker_BlinkerState_OnEntry(_instance->Blinker_BlinkerState_State, _instance);
break;
}
case BLINKER_BLINKERSTATE_OFF_STATE:{
digitalWriteFast(13, LOW);
f_Blinker_timer_blinker(_instance, 500000);
break;
}
case BLINKER_BLINKERSTATE_ON_STATE:{
digitalWriteFast(13, HIGH);
f_Blinker_timer_blinker(_instance, 3500000);
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
case BLINKER_BLINKERSTATE_OFF_STATE:{
break;}
case BLINKER_BLINKERSTATE_ON_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Blinker_handle_basic_blinking(struct Blinker_Instance *_instance) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
if (_instance->Blinker_BlinkerState_State == BLINKER_BLINKERSTATE_OFF_STATE) {
if (Blinker_BlinkerState_State_event_consumed == 0 && 1) {
Blinker_BlinkerState_OnExit(BLINKER_BLINKERSTATE_OFF_STATE, _instance);
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_ON_STATE;
Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_ON_STATE, _instance);
Blinker_BlinkerState_State_event_consumed = 1;
}
}
else if (_instance->Blinker_BlinkerState_State == BLINKER_BLINKERSTATE_ON_STATE) {
if (Blinker_BlinkerState_State_event_consumed == 0 && 1) {
Blinker_BlinkerState_OnExit(BLINKER_BLINKERSTATE_ON_STATE, _instance);
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_OFF_STATE;
Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_OFF_STATE, _instance);
Blinker_BlinkerState_State_event_consumed = 1;
}
}
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
}

// Observers for outgoing messages:
void (*external_Blinker_send_basic_blinking_listener)(struct Blinker_Instance *)= 0x0;
void (*Blinker_send_basic_blinking_listener)(struct Blinker_Instance *)= 0x0;
void register_external_Blinker_send_basic_blinking_listener(void (*_listener)(struct Blinker_Instance *)){
external_Blinker_send_basic_blinking_listener = _listener;
}
void register_Blinker_send_basic_blinking_listener(void (*_listener)(struct Blinker_Instance *)){
Blinker_send_basic_blinking_listener = _listener;
}
void Blinker_send_basic_blinking(struct Blinker_Instance *_instance){
if (Blinker_send_basic_blinking_listener != 0x0) Blinker_send_basic_blinking_listener(_instance);
if (external_Blinker_send_basic_blinking_listener != 0x0) external_Blinker_send_basic_blinking_listener(_instance);
;
}



