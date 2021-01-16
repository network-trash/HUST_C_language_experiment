#include<stdio.h>
#include<math.h>
#define s(a,b,c) ((a+b+c)/2)
#define area(s,a,b,c) pow((s)*(s-a)*(s-b)*(s-c),0.5)  //别忘了判断三角型的条件。 
int main(void)
{
	double s,a,b,c;
	printf("input a,b,c\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	if((a+b>c)&&(a+c>b)&&(b+c>a))
	{
		printf("s=%lf\n",s(a,b,c));
		s=s(a,b,c);
		printf("area=%lf\n",area(s,a,b,c));
	}
	else
		printf("无法构成三角形\n");
	
	return 0;
}
