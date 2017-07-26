#ifndef Save
#define Save
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Save
 *****************************************************************************/

// Definition of the instance struct:
struct Save_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_Reader;
uint16_t id_Writer;
// Variables for the current instance state
int Save_EESave_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Save_handle_empty_event(struct Save_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Save_EESave_OnEntry(int state, struct Save_Instance *_instance);
void Save_handle_Reader_readbyte(struct Save_Instance *_instance, uint8_t id);
void Save_handle_Writer_writebyte(struct Save_Instance *_instance, uint8_t id, uint8_t val);
// Declaration of callbacks for incoming messages:
void register_Save_send_Reader_byteread_listener(void (*_listener)(struct Save_Instance *, uint8_t));
void register_external_Save_send_Reader_byteread_listener(void (*_listener)(struct Save_Instance *, uint8_t));
void register_Save_send_Writer_bytewrite_listener(void (*_listener)(struct Save_Instance *));
void register_external_Save_send_Writer_bytewrite_listener(void (*_listener)(struct Save_Instance *));

// Definition of the states:
#define SAVE_EESAVE_STATE 0
#define SAVE_EESAVE_IDLE_STATE 1



#endif