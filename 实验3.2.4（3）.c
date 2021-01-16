#include<stdio.h>
int pow (int c,int d);  //这个函数是用来计算c的d次方的函数。 
int judge (int a);  //这个函数使用来判断n位数的是不是自幂数的函数 
int c[10];
int o=0;
int main(void)
{
	int n,i=0,t;         //变量i是用来代表一类数，n是表示您所需要的位数 
	printf("请输入一个数字，我将求出这个位数的自幂数\n输入0结束程序\n");
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=pow(10,(n-1));i<pow(10,n);i++)
		{
			if(judge(i))
			{
				o++;
			}
			else
				continue;
		}
		printf("%d位的自幂数是%d个:",n,o);
		for(t=0;t<o;t++)
		{
			printf("%8d",c[t]);
		}
		o=0;
		printf("\n");
		scanf("%d",&n);
	}
}
int judge (int a)
{
	int w=a;
	int n=0;
	for(;a!=0;n++)
	{
		a/=10;
	}
	int j=1,sum=0;
	a=w;             //变量j代表了下一个循环的操作数，变量sum是用来计算各项的和来比较判断是不是自幂数，变量u是为了简化运算的，变量w是为了将初始的a储存的。 
	for(;j<=n;j++)
	{
		sum+=pow(a%10,n);
		a/=10;
	}
	if(w==sum)
	{
		c[o]=w;
		return 1;
	}
	else
		return 0;
}
int pow (int c,int d)
{
	if(d==0)
		return 1;
	else
	{
		int q,w;                    //变量q是为了控制循环次数的变量，变量w是为了控制初值的常数。 
		for(q=1,w=c;q<d;q++)
		{
			c*=w;
		}
		return c;
	}
}
