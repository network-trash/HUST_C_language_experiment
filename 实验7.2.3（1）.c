/*
设计一个字段结构struct bits，
它将一个8位无符号字节从最低位向最高位声明为8个字段，
各字段依次为bit0, bit1, …, bit7，且bit0的优先级最高。
同时设计8个函数，将8个函数的名字存入一个函数指针数组p_fun。
如果bit0为1，调用p_fun[0]指向的函数。
如果struct bits中有多位为1，
则根据优先级从高到低依次调用函数指针数组p_fun中相应元素指向的函数。
8个函数中的第0个函数可以设计为：
void f0( int n)
{
	printf(“the function %d is called!\n”,n);
}
*/
#include<stdio.h>
void f0(int n){printf("the function %d is called!\n",n);} 
void f1(int n){printf("the function %d is called!\n",n);}
void f2(int n){printf("the function %d is called!\n",n);}
void f3(int n){printf("the function %d is called!\n",n);}
void f4(int n){printf("the function %d is called!\n",n);}
void f5(int n){printf("the function %d is called!\n",n);}
void f6(int n){printf("the function %d is called!\n",n);}
void f7(int n){printf("the function %d is called!\n",n);}

struct bits{
	unsigned short int bit0 : 1; 
	unsigned short int bit1 : 1; 
	unsigned short int bit2 : 1; 
	unsigned short int bit3 : 1; 
	unsigned short int bit4 : 1; 
	unsigned short int bit5 : 1; 
	unsigned short int bit6 : 1; 
	unsigned short int bit7 : 1; 
};
union byte{
	char c;
	struct bits bits_0;
};
int main(void)
{
	void (*pf[8]) (int) = {f0,f1,f2,f3,f4,f5,f6,f7};
	union byte byte_0 = {0};
	printf("请输入一个字符，我会根据ASCLL码调度函数\n");
	byte_0.c = getchar();
	if(byte_0.bits_0.bit0) 
		pf[0](0);
	if(byte_0.bits_0.bit1)
		pf[1](1);
	if(byte_0.bits_0.bit2)
		pf[2](2);
	if(byte_0.bits_0.bit3)
		pf[3](3);
	if(byte_0.bits_0.bit4)
		pf[4](4);
	if(byte_0.bits_0.bit5)
		pf[5](5);
	if(byte_0.bits_0.bit6)
		pf[6](6);
	if(byte_0.bits_0.bit7)
		pf[7](7);
	return 0;
}
