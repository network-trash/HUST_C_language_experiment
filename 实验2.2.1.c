#include <stdio.h>
int main()
{ 
	int i, x, k, flag = 0;
	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n"); 
	while (scanf("%d", &x) !=EOF) 
	{
	for(i=2,k=(x>>1);i<=k;i++) 
		if (!(x%i))                                       //应该加括号！优先级比较高 
		{
			flag = 1;
			break;
		}		
		
		if(flag==1)
		{                                                  //注意条件中的应该是比较符号而不是赋值符号 
			printf("%d是合数\n", x);
			flag=0;
		}                                                  //每次执行完毕以后要重新返回初始状态，要不就没了。 
		else 
			printf("%d不是合数\n", x);
	}
	
	return 0;
}
