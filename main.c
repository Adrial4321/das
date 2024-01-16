#include "funciones.h"

// Tabla de eventos
struct sStateTableEntry stateTable[] = {
 { kRedLight, kGreenState, kRedState, kRedState}, // Red
 { kYellowLight, kYellowState, kYellowState, kRedState}, // Yellow
 { kGreenLight, kGreenState, kYellowState, kGreenState}, // Green
};

// Estado actual
struct sStateTableEntry currentState;

// Evento disparado
EVENT evento;

int main(int argc, char const *argv[])
{
  evento=STOP_COMMAND;
  currentState = stateTable[kRedState];

  // Maquina de estados
  while(evento){
    
    switch(evento){
      case STOP_COMMAND:
        HandleEventStop(&currentState);
        break;
      case GO_COMMAND:
        HandleEventGo(&currentState);
        break;
      case TIMER_TIMEOUT:
        HandleEventTimeout(&currentState);
        break;
      case NO_EVENT:
        HandleEventNoEvent(&currentState);
        break;        
      default:
        evento = NO_EVENT;
    }

    /* letra q = SALIR, letra s = STOP_COMMAND, 
       letra t = TIMER_TIMEOUT, letra g = GO_COMMAND*/
    evento = get_event();
  }
}