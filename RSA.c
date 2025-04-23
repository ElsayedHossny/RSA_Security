#include"UART.h"
#include"functions.h"
#include"RSA.h"

int  p =0;
int  q =0;
unsigned long  n =0;
unsigned long  phi_n=0;
char e=0;
unsigned long  d=0;
int PT=0;
int CT=0;
void Initalization_System()
{
	UART_Init();
}

void ENTER_P(void)
{
	NUM_t  CheckPrimarity;
	TRANSIMT_TEXT("Please Enter First Prime Number :");
  RECEIVED_TWOBYTE(&p);
	CheckPrimarity=Primarity_Test(p);
	while (CheckPrimarity == NOTPRIME)
	{
		TRANSIMT_TEXT("THIS IS NOT PRIME REENTER PRIME ONE :");
		p=0;
		RECEIVED_TWOBYTE(&p);
		CheckPrimarity=Primarity_Test(p);
	}
	
}



void ENTER_q(void)
{
	NUM_t  CheckPrimarity;
	TRANSIMT_TEXT("Please Enter Second Prime Number :");
	RECEIVED_TWOBYTE(&q);
	CheckPrimarity=Primarity_Test(q);
	while (CheckPrimarity == NOTPRIME)
	{
		TRANSIMT_TEXT("THIS IS NOT PRIME REENTER PRIME ONE :");
		q=0;
		RECEIVED_TWOBYTE(&q);
		CheckPrimarity=Primarity_Test(q);
	}

}


void GENERATE_e_AND_d(void)
{
	n=p*q;
	phi_n=(p-1)*(q-1);
	e=Generate_E(phi_n);
	
	d=MulInverse_EEA(e,phi_n);
	TRANSIMT_TEXT("Your Bublic KEY : (");
	TRANSIMT_NUM(n);
	transmit(',');
	TRANSIMT_NUM(e);
	transmit(')');
}


void Enter_PlainText_AND_encrypt(void)
{
	transmit(0x0d);
	TRANSIMT_TEXT("ENTER PLAIN TEXT :");
	RECEIVED_TWOBYTE(&PT);
	CT=SQR_AND_MULL(PT,e,n);
	TRANSIMT_TEXT("YOUR CIPHER TEXT :");
	TRANSIMT_NUM(CT);
}

void decryption (void)
{
	transmit(0x0d);
	TRANSIMT_TEXT("ENTER CIPHER TEXT :");
	CT=0;
	RECEIVED_TWOBYTE(&CT);
	PT=SQR_AND_MULL(CT,d,n);
	TRANSIMT_TEXT("YOUR PLAIN TEXT :");
	TRANSIMT_NUM(PT);
}



