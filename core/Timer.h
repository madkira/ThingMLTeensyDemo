#include "IntervalTimer.h"

#define CLOCKS_NUMBER 4
#define CLOCKS_PERIOD 1000
void initialize_timer();
void start_timer(uint8_t id, uint8_t period, void (*f)(void));
void timer_cancel(uint8_t id);
