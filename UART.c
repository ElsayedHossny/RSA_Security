#include "UART.h"
#include <Reg52.h>
char ok_Flag=0;
void UART_Init(){
	TMOD = 0x20;	
	TH1 = 0xFD; 
	SCON = 0x50; 
  IE=0xA0;	
	TR1 = 1;
}

void transmit(char x)
{
		SBUF = x;	
		while(TI == 0);
		TI = 0;
}
char Receive(void)
{
	while(RI ==0);
	RI=0;
	return SBUF;
}



