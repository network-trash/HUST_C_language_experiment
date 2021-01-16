#include<stdio.h>
int main()
{
	int x;
	for(x=100;x<1000;x++)
	{
		if(((x*x)%1000)==x)
			printf("%d\n",x); 
		else
			continue;
	}
	
	return 0;
} 
