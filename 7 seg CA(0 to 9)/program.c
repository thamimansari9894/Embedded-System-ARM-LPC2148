#include <LPC214X.H>
#define SEG (0x7F<<16)
 void delay();
 unsigned char seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
 unsigned int i;
 int main(){
	 IO0DIR|=SEG;
	 while(1){
		 for(i=0;i<10;i++){
		 IO0CLR|=SEG;
		 IO0SET|=(seg[i]<<16);
     delay();}}}
 
void delay(){
unsigned int i;
for(i=0;i<200000;i++);}
