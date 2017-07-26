#ifndef Seriala
#define Seriala
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Seriala
 *****************************************************************************/

// Definition of the instance struct:
struct Seriala_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_basic;
// Variables for the current instance state
int Seriala_Message_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Seriala_handle_empty_event(struct Seriala_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Seriala_Message_OnEntry(int state, struct Seriala_Instance *_instance);
void Seriala_handle_basic_erreur(struct Seriala_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define SERIALA_MESSAGE_STATE 0
#define SERIALA_MESSAGE_IDLE_STATE 1



#endif