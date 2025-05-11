#include <LPC214X.H>
#define DATA 0xFF
#define SEG (0xFF<<16)
#define I1 (1<<11)
#define I2 (1<<12)
#define I3 (1<<13)
#define I4 (1<<14)
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
void seg(int data);
int main(){
IODIR0|=(DATA|RS|RW|EN);
IODIR0&=~(R1|R2|R3|R4);
IODIR0|=(C1|C2|C3);
IODIR0|=(I1|I2|I3|I4);
IODIR1|=(SEG);
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
	IOSET0|=I1;
	IOCLR0|=I2;
	IOCLR0|=I3;
	IOCLR0|=I4;
	seg(0x06);
	IOSET1|=0x06<<16;
  cmd(0x01);
  print("M1Forw",6);//1
	cmd(0xC0);
	while(IOPIN0&R1);}
	
	if(IOPIN0&R2){
  IOCLR0|=I1;
	IOCLR0|=I2;
	IOCLR0|=I3;
	IOSET0|=I4;
	seg(0x66);
	cmd(0x01);
	print("M2Rev",5);//4
	cmd(0xC0);
	while(IOPIN0&R2);}
	
	if(IOPIN0&R3){
	IOSET0|=I1;
	IOCLR0|=I2;
	IOCLR0|=I3;
	IOSET0|=I4;
	seg(0x07);
  cmd(0x01);
	print("M1ForwM2Rev",11);//7
  cmd(0x0C);
	while(IOPIN0&R3);}
	
	IOCLR0|=C1;IOSET0|=C2;IOCLR0|=C3;
	if(IOPIN0&R1){
	IOCLR0|=I1;
	IOSET0|=I2;
	IOCLR0|=I3;
	IOCLR0|=I4;
	seg(0x5B);
  cmd(0x01);
	print("M1Rev",5);//2
  cmd(0x0C);
	while(IOPIN0&R1);}
	
	if(IOPIN0&R2){
	IOSET0|=I1;
	IOCLR0|=I2;
	IOSET0|=I3;
	IOCLR0|=I4;
	seg(0x6D);
  cmd(0x01);
	print("M1 M2Forw",9);//5
  cmd(0x0C);
	while(IOPIN0&R2);}
	
	if(IOPIN0&R3){
	IOCLR0|=I1;
	IOSET0|=I2;
	IOSET0|=I3;
	IOCLR0|=I4;
	seg(0x7F);
  cmd(0x01);
	print("M1Rev M2Forw",12);//8
  cmd(0x0C);
	while(IOPIN0&R3);}
	
	IOCLR0|=C1;IOCLR0|=C2;IOSET0|=C3;
	if(IOPIN0&R1){
	IOCLR0|=I1;
	IOCLR0|=I2;
	IOSET0|=I3;
	IOCLR0|=I4;
	cmd(0x01);
	seg(0x4F);
	print("M2Forw",6);//3
  cmd(0x0C);
	while(IOPIN0&R1);}
	
	if(IOPIN0&R2){
	IOCLR0|=I1;
	IOSET0|=I2;
	IOCLR0|=I3;
	IOSET0|=I4;
	seg(0x7D);
  cmd(0x01);
	print("M1 M2Rev",8);//6
  cmd(0x0C);
	while(IOPIN0&R2);}
	
	if(IOPIN0&R3){
	IOCLR0|=I1;
	IOCLR0|=I2;
	IOCLR0|=I3;
	IOCLR0|=I4;
  cmd(0x01);
	seg(0x6F);
	print("All Off",7);//9
  cmd(0x0C);
	while(IOPIN0&R3);}}}

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

void seg(int data){
IOCLR1|=0xFF<<16;	
IOSET1|=data<<16;}

void print(char name[], unsigned int a){
unsigned int i;
for (i=0;i<a;i++){
dis(name[i]);}}

void delay(){
unsigned int i;
for(i=0;i<20000;i++);}
