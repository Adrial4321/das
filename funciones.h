#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>

typedef enum { kRedState = 0, kYellowState = 1, kGreenState = 2 } tState;
typedef enum { kRedLight = 0, kYellowLight, kGreenLight } tLight;
typedef enum {QUIT = 0, STOP_COMMAND, GO_COMMAND, TIMER_TIMEOUT, NO_EVENT} EVENT;

struct sStateTableEntry {
    tLight light;        // all states have associated lights
    tState goEvent;      // state to enter when go event occurs
    tState stopEvent;    // ... when stop event occurs
    tState timeoutEvent; // ... when timeout occurs
};

int get_event();
void HandleEventGo(struct sStateTableEntry *);
void HandleEventStop(struct sStateTableEntry *);
void HandleEventTimeout(struct sStateTableEntry *);
void HandleEventNoEvent(struct sStateTableEntry *);
