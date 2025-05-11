#include <LPC214X.H>
#define LED 0x000000FF
void delay();
void main(){
	  unsigned int count =0;
	  PINSEL0=0;
	  IO0DIR=LED;
	  while(1){
		IOCLR0=LED;
		IOSET0=count;
		delay();
    count ++;}}

void delay(){
unsigned int i;
for(i=0;i<200000;i++);}

