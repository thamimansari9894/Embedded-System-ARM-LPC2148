#include <LPC214X.H>
#define IN1 (1<<16)
#define IN2 (1<<17)
#define IN3 (1<<18)
#define IN4 (1<<19)
void delay();
int main(){
	IODIR0|=(IN1|IN2|IN3|IN4);
while(1){
  IOSET0|=IN1;
  IOSET0|=IN4;
	delay();}}
	
void delay(){
unsigned int i;
for(i=0;i<20000;i++);}
	