#include "funciones.h"

extern struct sStateTableEntry stateTable[];

int get_event()
{
  EVENT evento;
  char c = getchar();
  switch(c){
    case 'g':
      evento = GO_COMMAND;
      break;
    case 's':
      evento = STOP_COMMAND;
      break;
    case 't':
      evento = TIMER_TIMEOUT;
      break;
    case 'q':
      evento = QUIT;
      break;
    default:
      evento = NO_EVENT;
      break;
  }

  return evento;
}

void luz_roja()
{
  printf("\033[0;31m");
  printf("\rROJO     >");
  printf("\033[0m");
}

void luz_verde()
{
  printf("\033[0;32m");
  printf("\rVERDE    >");
  printf("\033[0m");
}

void luz_amarilla()
{
  printf("\033[0;33m");
  printf("\rAMARILLO >");
  printf("\033[0m");
}

void LightOn(tLight light)
{
  switch(light){
    case kRedLight:
      luz_roja();
      break;
    case kYellowLight:
      luz_amarilla();
      break;
    case kGreenLight:
      luz_verde();
      break;
    default:
      luz_roja();
  }
}

void HandleEventGo(struct sStateTableEntry *currentState)
{
  *currentState = stateTable[currentState->goEvent];
  LightOn(currentState->light);
}

void HandleEventStop(struct sStateTableEntry *currentState)
{
  *currentState = stateTable[currentState->stopEvent];
  LightOn(currentState->light);
}

void HandleEventTimeout(struct sStateTableEntry *currentState)
{
  *currentState = stateTable[currentState->timeoutEvent];
  LightOn(currentState->light);
}

void HandleEventNoEvent(struct sStateTableEntry *currentState)
{
  LightOn(currentState->light);
}