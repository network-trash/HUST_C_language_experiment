/*用条件编译方法来编写程序。输入一行英文字符序列，可以任选两种方式之一输出：
一为原文输出；二为变换字母的大小写后输出。例如小写‘a’变成大写‘A’，大写‘D’变成小写‘d’，其他字符不变。
用#define命令控制是否变换字母的大小写。
例如，#define CHANGE 1 则输出变换后的文字，若#define CHANGE 0则原文输出。*/
#include<stdio.h>
#define CHANGE 0 
int main(void)
{
	char c;
	
	if(CHANGE)
		printf("输入一串英文序列，我们将输出变换后的文字\n");
	else
	{
		printf("输入一串英文序列，我们将按照原文输出\n");
	} 
	#if CHANGE
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z')
		{
			c-=0x20;
			putchar(c);
		}
		else if(c>='A'&&c<='Z')
		{
			c+=0x20;
			putchar(c);
		}
		else
		{
			putchar(c);
		}
	}
	#else
	while((c=getchar())!='\n')
	{
		putchar(c);
	}
	#endif
	return 0;
}
