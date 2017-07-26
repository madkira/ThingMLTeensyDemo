#include "Save.h"
/*****************************************************************************
 * Implementation for type : Save
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Save_EESave_OnExit(int state, struct Save_Instance *_instance);
//Prototypes: Message Sending
void Save_send_Reader_byteread(struct Save_Instance *_instance, uint8_t val);
void Save_send_Writer_bytewrite(struct Save_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Save_EESave_OnEntry(int state, struct Save_Instance *_instance) {
switch(state) {
case SAVE_EESAVE_STATE:{
_instance->Save_EESave_State = SAVE_EESAVE_IDLE_STATE;
Save_EESave_OnEntry(_instance->Save_EESave_State, _instance);
break;
}
case SAVE_EESAVE_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Save_EESave_OnExit(int state, struct Save_Instance *_instance) {
switch(state) {
case SAVE_EESAVE_STATE:{
Save_EESave_OnExit(_instance->Save_EESave_State, _instance);
break;}
case SAVE_EESAVE_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Save_handle_Reader_readbyte(struct Save_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region EESave
uint8_t Save_EESave_State_event_consumed = 0;
if (_instance->Save_EESave_State == SAVE_EESAVE_IDLE_STATE) {
if (Save_EESave_State_event_consumed == 0 && 1) {
Save_send_Reader_byteread(_instance, EEPROM.read(id));
Save_EESave_State_event_consumed = 1;
}
}
//End Region EESave
//End dsregion EESave
//Session list: 
}
void Save_handle_Writer_writebyte(struct Save_Instance *_instance, uint8_t id, uint8_t val) {
if(!(_instance->active)) return;
//Region EESave
uint8_t Save_EESave_State_event_consumed = 0;
if (_instance->Save_EESave_State == SAVE_EESAVE_IDLE_STATE) {
if (Save_EESave_State_event_consumed == 0 && 1) {
EEPROM.update(id,val);
Save_send_Writer_bytewrite(_instance);
Save_EESave_State_event_consumed = 1;
}
}
//End Region EESave
//End dsregion EESave
//Session list: 
}

// Observers for outgoing messages:
void (*external_Save_send_Reader_byteread_listener)(struct Save_Instance *, uint8_t)= 0x0;
void (*Save_send_Reader_byteread_listener)(struct Save_Instance *, uint8_t)= 0x0;
void register_external_Save_send_Reader_byteread_listener(void (*_listener)(struct Save_Instance *, uint8_t)){
external_Save_send_Reader_byteread_listener = _listener;
}
void register_Save_send_Reader_byteread_listener(void (*_listener)(struct Save_Instance *, uint8_t)){
Save_send_Reader_byteread_listener = _listener;
}
void Save_send_Reader_byteread(struct Save_Instance *_instance, uint8_t val){
if (Save_send_Reader_byteread_listener != 0x0) Save_send_Reader_byteread_listener(_instance, val);
if (external_Save_send_Reader_byteread_listener != 0x0) external_Save_send_Reader_byteread_listener(_instance, val);
;
}
void (*external_Save_send_Writer_bytewrite_listener)(struct Save_Instance *)= 0x0;
void (*Save_send_Writer_bytewrite_listener)(struct Save_Instance *)= 0x0;
void register_external_Save_send_Writer_bytewrite_listener(void (*_listener)(struct Save_Instance *)){
external_Save_send_Writer_bytewrite_listener = _listener;
}
void register_Save_send_Writer_bytewrite_listener(void (*_listener)(struct Save_Instance *)){
Save_send_Writer_bytewrite_listener = _listener;
}
void Save_send_Writer_bytewrite(struct Save_Instance *_instance){
if (Save_send_Writer_bytewrite_listener != 0x0) Save_send_Writer_bytewrite_listener(_instance);
if (external_Save_send_Writer_bytewrite_listener != 0x0) external_Save_send_Writer_bytewrite_listener(_instance);
;
}



