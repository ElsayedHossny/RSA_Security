#ifndef functions_H
#define functions_H

#define Securty_Level 5
typedef enum {PRIME , NOTPRIME} NUM_t;
void TRANSIMT_TEXT(char * TEXT);
char RECEIVED_BYTE (void);
void RECEIVED_TWOBYTE (int* Data);
void TRANSIMT_NUM(unsigned long Num);
NUM_t Primarity_Test (unsigned int Num);
char Generate_E (unsigned long PHI_N);
unsigned long MulInverse_EEA(int Key_ENC ,unsigned long  PHI_N);
unsigned long SQR_AND_MULL (int base , unsigned long exp , unsigned long N_Mode);

#endif