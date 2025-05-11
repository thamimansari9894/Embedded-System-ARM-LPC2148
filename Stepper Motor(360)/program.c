#include <LPC214X.H>
#define Motor (0x0F<<16)
void delay();
unsigned int i;
unsigned char a[10]={0x08,0x0C,0x04,0x06,0x02,0x03,0x01,0x09};
int main(){
while(1){
IODIR0|= Motor;
for(i=0;i<=10;i++){
	IOCLR0|= Motor;
  IOSET0|=a[i]<<16;
  delay();}}}

	void delay(){
	unsigned int i;
	for(i=0;i<200000;i++);}