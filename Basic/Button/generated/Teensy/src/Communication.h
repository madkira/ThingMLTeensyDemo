#ifndef Communication
#define Communication
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Communication
 *****************************************************************************/

// Definition of the instance struct:
struct Communication_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_Blinker;
uint16_t id_Button;
// Variables for the current instance state
int Communication_Main_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Communication_handle_empty_event(struct Communication_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Communication_Main_OnEntry(int state, struct Communication_Instance *_instance);
void Communication_handle_Button_long_press(struct Communication_Instance *_instance);
void Communication_handle_Button_double_click(struct Communication_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Communication_send_Blinker_erreur_listener(void (*_listener)(struct Communication_Instance *, uint8_t));
void register_external_Communication_send_Blinker_erreur_listener(void (*_listener)(struct Communication_Instance *, uint8_t));

// Definition of the states:
#define COMMUNICATION_MAIN_STATE 0
#define COMMUNICATION_MAIN_IDLE_STATE 1



#endif