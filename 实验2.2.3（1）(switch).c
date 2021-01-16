#include<stdio.h>
int main(void)
{
	double wage ,s1=0 ,s2=0 ,s3=0 ,s4=0 ,s5=0;
	printf("请输入您的工资\n");
	scanf("%lf",&wage);
	switch (((int)wage)/1000)
	{
		case 0 : break;
		case 1 : s1=(wage-1000)*0.05; break;
		case 2 : s1=50; s2=(wage-2000)*0.1; break;
		case 3 : s1=50;	s2=100;	s3=(wage-3000)*0.15; break;
		case 4 : s1=50;	s2=100;	s3=150;	s4=(wage-4000)*0.2; break;
		default : s1=50; s2=100; s3=150; s4=200; s5=(wage-5000)*0.25; break;
	}
	printf("您的需要交的税款是%.3f\n",(s1+s2+s3+s4+s5)); 
} 
