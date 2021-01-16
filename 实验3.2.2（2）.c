/*实验3-2程序修改替换第(2)题程序：根据公式计算 s*/
#include<stdio.h>
double mulx(double x,int n);
long fac(int n);
double sum(double x,int n);
int main(void)
{
	double x;
	int n;
	printf("Input x and n:");
	scanf("%lf%d",&x,&n);
	printf("The result is %lf:",sum(x,n));
	return 0;	  
}
double sum(double x,int n)
{
	if(n==0)
		return 1;
	else
		return sum(x,n-1)+mulx(x,n)/fac(n);
}
double mulx(double x,int n)
{
	static double z=1.0;
	z*=x;
	return z;
}
long fac(int n)
{
	static long h=1;
	h*=n;               //利用其每次传递的量是从1开始的。 
	return h; 	
}
