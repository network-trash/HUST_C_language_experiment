#include<stdio.h>
unsigned long f (unsigned long n);
int main(void)
{
	unsigned long n;
	for(n=1;n<=10000;n++)
	{
		if(f(n))
		{
			int j;
			printf("%lu = 1",n);
			for(j=2;j<n;j++)
			{
				if(n%j==0)
					printf("+%d",j);	
				else
					continue;
			}
			printf("\n");
		}
		else 
			continue;
	}
	return 0;
}
unsigned long f (unsigned long n)
{
	unsigned long i,sum=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
			sum+=i;
		else
			continue;
	}
	if(n==sum)
		return 1;
	else
		return 0;
}
