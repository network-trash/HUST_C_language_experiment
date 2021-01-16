#include<stdio.h>
int main(void)
{
	unsigned short x,m,n;
	printf("请这样操作x的值以十六进制输入，m和n以十进制输入\n并且注意一点m是0到15的整数，n是0到16-m的整数\n下面依次输入，x,m,n\n");
	while(scanf("%hx%hd%hd",&x,&m,&n)!=EOF)
	{
			if (m>=0&&m<=15&&n>=1&&n<(16-m))
		{
			x>>=m;
			x<<=(16-n);
			printf("ans=%#x\n",x);	
		}   
 		
		else   
		printf("输入错误!\n"); 
	}
	
	
		return 0;
}

	
