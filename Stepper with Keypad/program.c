#include <LPC214X.H>
#define Motor (0x0F<<8)
#define C1 (1<<16)
#define C2 (1<<17)
#define C3 (1<<18)
#define R1 (1<<19)
#define R2 (1<<20)
#define R3 (1<<21)
#define R4 (1<<22)
void delay();
void halfwave();
void fullwave();
void wave();
int main(){
IODIR0&=~(R1|R2|R3|R4);
IODIR0|=(C1|C2|C3);
IODIR0|= Motor;

	while(1){
	
  IOSET0|=C1;IOCLR0|=C2;IOCLR0|=C3;
	if(IOPIN0&R1){
	halfwave();}
		
	IOCLR0|=C1;IOSET0|=C2;IOCLR0|=C3;
	if(IOPIN0&R1){
	wave();}
		
	IOCLR0|=C1;IOCLR0|=C2;IOSET0|=C3;
	if(IOPIN0&R1){
	fullwave();}}}

void delay(){
unsigned int i;
for(i=0;i<300000;i++);}

void wave(){
unsigned int i;
unsigned char a[6]={0x00,0x08,0x04,0x02,0x01};
for(i=0;i<=5;i++){
	IOCLR0|= Motor;
  IOSET0|=a[i]<<8;
  delay();}}

void halfwave(){
unsigned int i;
unsigned char a[10]={0x00,0x08,0x0C,0x04,0x06,0x02,0x03,0x01,0x09};
for(i=0;i<=10;i++){
	IOCLR0|= Motor;
  IOSET0|=a[i]<<8;
  delay();}}

void fullwave(){
unsigned int i;
unsigned char a[6]={0x00,0x0C,0x06,0x03,0x09};
for(i=0;i<=5;i++){
	IOCLR0|= Motor;
  IOSET0|=a[i]<<8;
  delay();}}