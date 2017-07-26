#include "Communication.h"
/*****************************************************************************
 * Implementation for type : Communication
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Communication_Main_OnExit(int state, struct Communication_Instance *_instance);
//Prototypes: Message Sending
void Communication_send_Blinker_erreur(struct Communication_Instance *_instance, uint8_t id);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Communication_Main_OnEntry(int state, struct Communication_Instance *_instance) {
switch(state) {
case COMMUNICATION_MAIN_STATE:{
_instance->Communication_Main_State = COMMUNICATION_MAIN_IDLE_STATE;
Communication_Main_OnEntry(_instance->Communication_Main_State, _instance);
break;
}
case COMMUNICATION_MAIN_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Communication_Main_OnExit(int state, struct Communication_Instance *_instance) {
switch(state) {
case COMMUNICATION_MAIN_STATE:{
Communication_Main_OnExit(_instance->Communication_Main_State, _instance);
break;}
case COMMUNICATION_MAIN_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Communication_handle_Button_long_press(struct Communication_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Communication_Main_State_event_consumed = 0;
if (_instance->Communication_Main_State == COMMUNICATION_MAIN_IDLE_STATE) {
if (Communication_Main_State_event_consumed == 0 && 1) {
Communication_send_Blinker_erreur(_instance, 3);
Communication_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Communication_handle_Button_double_click(struct Communication_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Communication_Main_State_event_consumed = 0;
if (_instance->Communication_Main_State == COMMUNICATION_MAIN_IDLE_STATE) {
if (Communication_Main_State_event_consumed == 0 && 1) {
Communication_send_Blinker_erreur(_instance, 12);
Communication_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}

// Observers for outgoing messages:
void (*external_Communication_send_Blinker_erreur_listener)(struct Communication_Instance *, uint8_t)= 0x0;
void (*Communication_send_Blinker_erreur_listener)(struct Communication_Instance *, uint8_t)= 0x0;
void register_external_Communication_send_Blinker_erreur_listener(void (*_listener)(struct Communication_Instance *, uint8_t)){
external_Communication_send_Blinker_erreur_listener = _listener;
}
void register_Communication_send_Blinker_erreur_listener(void (*_listener)(struct Communication_Instance *, uint8_t)){
Communication_send_Blinker_erreur_listener = _listener;
}
void Communication_send_Blinker_erreur(struct Communication_Instance *_instance, uint8_t id){
if (Communication_send_Blinker_erreur_listener != 0x0) Communication_send_Blinker_erreur_listener(_instance, id);
if (external_Communication_send_Blinker_erreur_listener != 0x0) external_Communication_send_Blinker_erreur_listener(_instance, id);
;
}



