#include <LPC214X.H>
#define LED (0xFF<<8)
void delay();

int main(){
	IODIR0|=LED;
	while(1){
		unsigned int i;
		 IOCLR0|=LED;
     for(i=0x01;i!=0x00;i<<=1){
		 IOSET0|=i<<8;
		 delay();}
		 IOCLR0|=LED;
	   for(i=0x80;i!=0x00;i>>=1){
		 IOSET0|=i<<8;
		 delay();}}}

void delay(){
unsigned int i;
for(i=0;i<20000;i++);}