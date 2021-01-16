/*实验4-2程序修改替换题程序*/ 
#include<stdio.h>
float sum(float x, float y);//语法错误：函数原型未声明 
int max(int x, int y, int z);//语法错误：函数原型未声明 
int main(void)
{
	int a, b, c;
  	float d, e;
  	printf("Input three integers:");
  	scanf("%d %d %d",&a,&b,&c);
  	printf("\nThe maximum of them is %d\n",max(a,b,c));

  	printf("Input two floating point numbers:");
	scanf("%f %f",&d,&e);
	printf("\nThe sum of them is  %f\n",sum(d,e));
	return 0;
}
	
int max(int x, int y, int z)					
{
	int m=z;
	if (x>y)
	{
		if(x>z) m=x;     //逻辑错误：else不知道是哪一个的if了。 
	}
	else
    	if(y>z) m=y;
    return m;
}

float sum(float x, float y)
{
	return x+y;
}
