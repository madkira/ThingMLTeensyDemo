#ifndef SaveTest
#define SaveTest
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : SaveTest
 *****************************************************************************/

// Definition of the instance struct:
struct SaveTest_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_saveact;
uint16_t id_aquireact;
// Variables for the current instance state
int SaveTest_TestSaver_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int SaveTest_handle_empty_event(struct SaveTest_Instance *_instance);
// Declaration of prototypes outgoing messages :
void SaveTest_TestSaver_OnEntry(int state, struct SaveTest_Instance *_instance);
void SaveTest_handle_aquireact_byteread(struct SaveTest_Instance *_instance, uint8_t val);
// Declaration of callbacks for incoming messages:
void register_SaveTest_send_saveact_writebyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t, uint8_t));
void register_external_SaveTest_send_saveact_writebyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t, uint8_t));
void register_SaveTest_send_aquireact_readbyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t));
void register_external_SaveTest_send_aquireact_readbyte_listener(void (*_listener)(struct SaveTest_Instance *, uint8_t));

// Definition of the states:
#define SAVETEST_TESTSAVER_STATE 0
#define SAVETEST_TESTSAVER_IDLE_STATE 1



#endif