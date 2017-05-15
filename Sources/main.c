#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SCI.h"
#include "MessageManager.h"

u8 u8MessageSize;
unsigned char cMainMessage[MESSAGE_MANAGER_MAX_MSG_SIZE];

char array[]={0b01010101};

void main(void) {
  EnableInterrupts;
  /* include your code here */
  MessageManager_Init();
  

  for(;;) {
	  
    __RESET_WATCHDOG();	/* feeds the dog */
    if(MessageManager_IsMessageReady())
    {
    	MessageManager_getMessage(cMainMessage,&u8MessageSize);
    	if(!MessageManager_TxIsBusy())
    	{
    		MessageManager_SendMessage("DONE",4);
    	}
    }
    
  } /* loop forever */
  /* please make sure that you never leave main */
}
