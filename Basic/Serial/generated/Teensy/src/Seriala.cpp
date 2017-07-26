#include "Seriala.h"
/*****************************************************************************
 * Implementation for type : Seriala
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Seriala_Message_OnExit(int state, struct Seriala_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Seriala_Message_OnEntry(int state, struct Seriala_Instance *_instance) {
switch(state) {
case SERIALA_MESSAGE_STATE:{
_instance->Seriala_Message_State = SERIALA_MESSAGE_IDLE_STATE;
Serial.begin(115200);
Seriala_Message_OnEntry(_instance->Seriala_Message_State, _instance);
break;
}
case SERIALA_MESSAGE_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Seriala_Message_OnExit(int state, struct Seriala_Instance *_instance) {
switch(state) {
case SERIALA_MESSAGE_STATE:{
Seriala_Message_OnExit(_instance->Seriala_Message_State, _instance);
break;}
case SERIALA_MESSAGE_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Seriala_handle_basic_erreur(struct Seriala_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region Message
uint8_t Seriala_Message_State_event_consumed = 0;
if (_instance->Seriala_Message_State == SERIALA_MESSAGE_IDLE_STATE) {
if (Seriala_Message_State_event_consumed == 0 && 1) {
Serial.println("Error obtain ");Serial.println((int)id);
Seriala_Message_State_event_consumed = 1;
}
}
//End Region Message
//End dsregion Message
//Session list: 
}

// Observers for outgoing messages:



