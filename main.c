#include"RSA.h"

int main (void)
{
	
	Initalization_System();
  ENTER_P(); 
  ENTER_q();  
  GENERATE_e_AND_d();
	Enter_PlainText_AND_encrypt();
	decryption ();
	while(1);
	return 0;
}