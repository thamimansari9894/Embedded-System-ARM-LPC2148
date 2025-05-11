#include <LPC214X.H>
void delay();

void main(){
	IO0DIR|=(1<<10);
	while(1){
		IOSET0|=(1<<10);
		delay();
		IOCLR0|=(1<<10);
		delay();}}

		void delay(){
			unsigned int i;
			for(i=0;i<30000;i++);}

