#include <LPC214X.H>
#define DATA 0x000000FF
#define C1 (1<<16)
#define C2 (1<<17)
#define C3 (1<<18)
#define R1 (1<<19)
#define R2 (1<<20)
#define R3 (1<<21)
#define R4 (1<<22)
#define RS (1<<8)
#define RW (1<<9)
#define EN (1<<10)
void print(char name[], unsigned int a);
void cmd(char a);
void dis(int dat);
void delay();
int main(){
IODIR0|=(DATA|RS|RW|EN);
IODIR0&=~(R1|R2|R3|R4);
IODIR0|=(C1|C2|C3);
cmd(0x38);
cmd(0x0C);
cmd(0x10);
cmd(0x06);
cmd(0x80);
cmd(0xC0);
cmd(0x01);

	while(1){
	
  IOSET0|=C1;IOCLR0|=C2;IOCLR0|=C3;
	if(IOPIN0&R1){
	dis('1');
	while(IOPIN0&R1);}
	if(IOPIN0&R2){
	dis('4');
	while(IOPIN0&R2);}
	if(IOPIN0&R3){
	dis('7');
	while(IOPIN0&R3);}
	if(IOPIN0&R4){
	dis('*');
	while(IOPIN0&R4);}
		
	IOCLR0|=C1;IOSET0|=C2;IOCLR0|=C3;
	if(IOPIN0&R1){
	dis('2');
	while(IOPIN0&R1);}
	if(IOPIN0&R2){
	dis('5');
	while(IOPIN0&R2);}
	if(IOPIN0&R3){
	dis('9');
	while(IOPIN0&R3);}
	if(IOPIN0&R4){
	dis('0');
	while(IOPIN0&R4);}
		
	IOCLR0|=C1;IOCLR0|=C2;IOSET0|=C3;
	if(IOPIN0&R1){
	dis('3');
	while(IOPIN0&R1);}
	if(IOPIN0&R2){
	dis('6');
	while(IOPIN0&R2);}
	if(IOPIN0&R3){
	dis('9');
	while(IOPIN0&R3);}
	if(IOPIN0&R4){
	dis('#');
	while(IOPIN0&R4);}}}

	void cmd(char a){
	  IOCLR0=DATA;
    IOSET0=a&DATA;
    IOCLR0=RS;
    IOCLR0=RW;
    IOSET0=EN;
	  delay();
    IOCLR0=EN;}
	
void dis(int dat){
    IOCLR0=DATA;
    IOSET0=dat&DATA;
    IOSET0=RS;
    IOCLR0=RW;
    IOSET0=EN;
	  delay();
    IOCLR0=EN;}

void print(char name[], unsigned int a){
unsigned int i;
for (i=0;i<a;i++){
dis(name[i]);}}

void delay(){
unsigned int i;
for(i=0;i<20000;i++);}