#include <LPC214X.H>
#define DATA 0x000000FF
#define RS (1<<8)
#define RW (1<<9)
#define EN (1<<10)
void print(char name[], unsigned int a);
void cmd(char a);
void dis(int dat);
void delay();
int main(){
IODIR0|=(DATA|RS|RW|EN);
cmd(0x38);
cmd(0x0C);
cmd(0x10);
cmd(0x06);
cmd(0x80);
cmd(0xC0);
cmd(0x01);

while(1){
cmd(0x80);
print("Ansari",6);
cmd(0x01);
cmd(0x80);
print("Immortal",8);
cmd(0x01);
cmd(0x80);
print("Monky D Luffy",13);
cmd(0x01);}}



void cmd(char a){
	  IOCLR0=DATA;
    IOSET0=a&DATA;
    IOCLR0=RS;
    IOCLR0=RW;
    IOSET0=EN;
	  delay();
    IOCLR0|=EN;}
void dis(int dat){
    IOCLR0=DATA;
    IOSET0=dat&DATA;
    IOSET0=RS;
    IOCLR0=RW;
    IOSET0=EN;
	  delay();
    IOCLR0=EN;}

void print(char name[], unsigned int a){
int i;
for (i=0;i<a;i++){
dis(name[i]);}}

void delay(){
unsigned int i;
for (i=0;i<20000;i++);}