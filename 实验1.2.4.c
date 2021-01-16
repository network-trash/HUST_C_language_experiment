#include<stdio.h>
int main()
{
	char a,c1,c2,c3,c4,c5;
	while((scanf("%c",&a))!=EOF)
	{
		if(a!='\n')
		{
			c1=((a&0x15)<<1);
			c2=((a&0x2A)>>1);
			c3=a&0xC0;
			c4=(c3>>6);
		   	c5=((c1|c2)>>(6-c4)|(c1|c2)<<c4);
		   	a=c3|c5;
		   	printf("%c",a);
		}
		else
		printf("\n");
	}
	return 0;
} 
