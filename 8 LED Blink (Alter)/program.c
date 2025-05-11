#include <LPC214X.H>
#define LED 0x000000FF
void delay();
void main(){
	  IO0DIR|=LED;
	  while(1){
		IOCLR0=LED;
		IOSET0|=(0x000000AA);
		delay();
    IOCLR0=LED;
		IOSET0|=(0x00000055);
		delay();}}

void delay(){
unsigned int i;
for(i=0;i<200000;i++);}

