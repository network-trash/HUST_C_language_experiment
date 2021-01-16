#include<stdio.h>
int main()
{
	unsigned long x,mask;
	while(scanf("%ld",&x)!=EOF)
	{
		mask=0x000000ff;
		printf("%ld.%ld.%ld.%ld\n",(x>>24)&mask,(x>>16)&mask,(x>>8)&mask,x&mask); 
	}
	return 0;
 } 
