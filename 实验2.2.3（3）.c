#include<stdio.h>
int main()
{
	int x ,y ,i ,j ;                                     //i表示行数；j表示列数 
	printf("请输入行数\n");
	scanf("%d",&y);
	for(i=0;i<=(y-1);i++)                                 //定义行数，从第0行开始 ，从第0列开始 
	{
		for(j=1;j<=(40-2*i);j++)
			putchar(' ');
		for(x=1,j=0;x>=1;x=x*(i-j+1)/j)                       //最后不能让x小于1或者j不能比i大 
		{
			printf("%4d",x);                                 //注意要让前面有三个空格（有一个字母的时候） 
			j++;
		}
		printf("\n");
	}
	return 0;
}
