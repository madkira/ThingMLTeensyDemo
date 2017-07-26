#include "SaveTest.h"
/*****************************************************************************
 * Implementation for type : SaveTest
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void SaveTest_TestSaver_OnExit(int state, struct SaveTest_Instance *_instance);
//Prototypes: Message Sending
void SaveTest_send_saveact_writebyte(struct SaveTest_Instance *_instance, uint8_t id, uint8_t val);
void SaveTest_send_aquireact_readbyte(struct SaveTest_Instance *_instance, uint8_t id);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void SaveTest_TestSaver_OnEntry(int state, struct SaveTest_Instance *_instance) {
switch(state) {
case SAVETEST_TESTSAVER_STATE:{
_instance->SaveTest_TestSaver_State = SAVETEST_TESTSAVER_IDLE_STATE;
Serial.begin(115200);
SaveTest_TestSaver_OnEntry(_instance->SaveTest_TestSaver_State, _instance);
break;
}
case SAVETEST_TESTSAVER_IDLE_STATE:{
delay(3000);
SaveTest_send_aquireact_readbyte(_instance, 1);
break;
}
default: break;
}
}

// On Exit Actions:
void SaveTest_TestSaver_OnExit(int state, struct SaveTest_Instance *_instance) {
switch(state) {
case SAVETEST_TESTSAVER_STATE:{
SaveTest_TestSaver_OnExit(_instance->SaveTest_TestSaver_State, _instance);
break;}
case SAVETEST_TESTSAVER_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SaveTest_handle_aquireact_byteread(struct SaveTest_Instance *_instance, uint8_t val) {
if(!(_instance->active)) return;
//Region TestSaver
uint8_t SaveTest_TestSaver_State_event_consumed = 0;
if (_instance->SaveTest_TestSaver_State == SAVETEST_TESTSAVER_IDLE_STATE) {
if (SaveTest_TestSaver_State_event_consumed == 0 && 1) {
Serial.println(val);
SaveTest_send_saveact_writebyte(_instance, 1, val + 1);
SaveTest_TestSaver_State_event_consumed = 1;
}
}
//End Region TestSaver
//End dsregion TestSaver
//Session list: 
}

// Observers for outgoing messages:
void (*external_SaveTest_send_saveact_writebyte_listener)(struct SaveTest_Instance *, uint8_t, uint8_t)= 0x0;
void (*SaveTest_send_saveact_writebyte_listener)(struct SaveTest_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_SaveTest_send_saveact_writebyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t, uint8_t)){
external_SaveTest_send_saveact_writebyte_listener = _listener;
}
void register_SaveTest_send_saveact_writebyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t, uint8_t)){
SaveTest_send_saveact_writebyte_listener = _listener;
}
void SaveTest_send_saveact_writebyte(struct SaveTest_Instance *_instance, uint8_t id, uint8_t val){
if (SaveTest_send_saveact_writebyte_listener != 0x0) SaveTest_send_saveact_writebyte_listener(_instance, id, val);
if (external_SaveTest_send_saveact_writebyte_listener != 0x0) external_SaveTest_send_saveact_writebyte_listener(_instance, id, val);
;
}
void (*external_SaveTest_send_aquireact_readbyte_listener)(struct SaveTest_Instance *, uint8_t)= 0x0;
void (*SaveTest_send_aquireact_readbyte_listener)(struct SaveTest_Instance *, uint8_t)= 0x0;
void register_external_SaveTest_send_aquireact_readbyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t)){
external_SaveTest_send_aquireact_readbyte_listener = _listener;
}
void register_SaveTest_send_aquireact_readbyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t)){
SaveTest_send_aquireact_readbyte_listener = _listener;
}
void SaveTest_send_aquireact_readbyte(struct SaveTest_Instance *_instance, uint8_t id){
if (SaveTest_send_aquireact_readbyte_listener != 0x0) SaveTest_send_aquireact_readbyte_listener(_instance, id);
if (external_SaveTest_send_aquireact_readbyte_listener != 0x0) external_SaveTest_send_aquireact_readbyte_listener(_instance, id);
;
}



