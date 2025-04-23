
#include "functions.h"
#include "UART.h"

char binaryNum[16];
void TRANSIMT_TEXT(char * TEXT)
{
	char i=0;
	for ( i = 0; TEXT[i];i++)
	{
		transmit(TEXT[i]);
	}
}


 
void RECEIVED_TWOBYTE (int * Data)
{
	char Received_data[7]={0};
	signed char Digit=0;
	int placed=1;
	char r_data=0;
	r_data=Receive();
	
	while (r_data!=0x0d)
	{
		r_data-='0';
		Received_data[Digit++]=r_data;
		r_data=Receive();
		
	}
	Digit--;
	while(Digit>=0)
	{
		*Data+=Received_data[Digit--]*placed;
		placed*=10;
		
	}
	
}

void TRANSIMT_NUM(unsigned long Num)
{
	char lenght=0,num[10]={0};
		
	while(Num>0)
	{
		num[lenght++]=(Num%10)+'0';
	  Num/=10;
	}
	for (;lenght>=0;lenght--)
	{
		transmit(num[lenght]);
	}
	
}


char decToBinary(unsigned long n)
{
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    return i-1;
}
unsigned long SQR_AND_MULL (int base , unsigned long exp , unsigned long N_Mode)
{
    unsigned long  Rem=base;
	  signed char j=0;
	  char Length=0;
	 
     Length=decToBinary(exp);

     for (j = (Length-1); j >= 0; j--){
        if(binaryNum[j]==0){
            Rem=(Rem*Rem); 
        }else{
            Rem=(Rem*Rem);
            Rem=Rem%N_Mode;
            Rem=(Rem*base);
        }
        Rem=Rem%N_Mode;
     }
     return Rem;
}
 int Generate_RandomNUM(int Boundary)
{
	  static int RAND_NUM=14625;
    unsigned int a = 1664525;
    unsigned int c = 1013904;
 
    
    RAND_NUM = (a * RAND_NUM + c) % Boundary;
		while(RAND_NUM < 2)
		{
			RAND_NUM = (a * RAND_NUM + c) % Boundary;
		}
		
    return RAND_NUM;
}


NUM_t Primarity_Test (unsigned int num)
{
     int random_number=0,Result=0;
	   char Round=0;
     for (Round=0;Round<Securty_Level;Round++)
     {
		
     random_number=Generate_RandomNUM((num-2));
						 
     Result=SQR_AND_MULL(random_number,num-1,num);
			
     if (Result!=1)
     {
         return NOTPRIME;
     }
     }

         return PRIME;
}

int GCD(unsigned long NUM1,int NUM2)
{
    unsigned long TEMP=0;
    if(NUM1 == NUM2)
			{
        return 0;
      }
    while (NUM2 > 0)
			{
        TEMP=NUM1%NUM2;
        NUM1=NUM2;
        NUM2=TEMP;
    }
    return NUM1;
}
char Generate_E (unsigned long PHI_N)
{
	unsigned long e=0;
    for ( e = 3;e <PHI_N;e=e+2)
    {
        if (GCD(PHI_N,e)==1)
        {
            return e;
        }
    }
}

unsigned long MulInverse_EEA(int Key_ENC ,signed long  PHI_N)
{
	
signed long d=0,TEMP=PHI_N; 
unsigned char Arr_R[10];
unsigned char j=0,i=0;	
signed long Arr_Q[10],T0=0,T1=1;
 	
    while (Key_ENC > 1) {
        Arr_R[i]=PHI_N%Key_ENC;
        Arr_Q[i]=PHI_N/Key_ENC;
       
        PHI_N=Key_ENC;
        Key_ENC=Arr_R[i];
			
        i++;
    }
    //////////////////////////////////To Find Multiplicative_inverse/////////////////////////////////////////////
    for( j=0 ; j<i ;j++){
        d= T0 - (Arr_Q[j]*T1);
        T0 =T1;
        T1=d;
    }
    if(d<0){
       d=d+TEMP;
    }else{
       d=d%TEMP;
    }
		
    return d;
}