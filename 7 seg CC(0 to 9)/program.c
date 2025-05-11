#include <LPC214X.H>
 void delay();
 unsigned char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 void main(){
	 PINSEL0=0;
	 IODIR0|=0xFF;
	 while(1){
		 int i;
		 for(i=0;i<=10;i++){
		 IOCLR0|=0xFF;
		 IOSET0=seg[i];
		 delay();}}}
 
void delay(){
unsigned int i;
for(i=0;i<200000;i++);}
