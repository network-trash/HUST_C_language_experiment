/*
输入n行文本，每行不超过80个字符，
用字符指针数组指向键盘输入的n行文本，
且n行文本的存储无冗余，
删除每一行中的前置空格（' '）和水平制表符（'\t'）。
要求：将删除一行文本中前置空格和水平制表符的功能定义成函数，
在main函数中输出删除前置空格符的各行。
*/ 
#include<stdio.h>
#include<ctype.h>
#include<string.h>//配合下一个头文件 
#include<malloc.h>//需要使得程序的每一行文本没有冗余 
#define max 80
void delete_tab_formerspace (char**,int);

int main(void)
{
	int n, i;
	printf("请输入您输入文本的行数\n");//如果不可以知道输入了多少行文本，那么就造一个循环去获知有多少个换行符。 
	scanf("%d", &n);
	getchar();//吸收回车键 
	char *str[n],s[max];
	/*读取字符串*/
	for(i=0; i<n; i++)
	{
		printf("请输入第%d行\n",i+1);
		gets(s);
		str[i] = (char *)malloc(strlen(s)+1);
		strcpy(str[i], s);
	}
	delete_tab_formerspace(str,n);
	for(i=0; i<n; i++)
	{
		printf("这是处理后的第%d行\n",i+1);
		puts(*(str+i));
		free(*(str+i));
	}
	return 0;
}
void delete_tab_formerspace (char**p,int n)
{
	char a[n][max]={0};//初始化
	int i, j, k;
	for(i=0; i<n; i++)
	{
		j=0;
		while(isspace(p[i][j])) j++;
		for(k=0; p[i][j] != '\0'; j++,k++)
		{
			a[i][k] = p[i][j];
		}
		a[i][j] = '\0';
	}
	for(i=0; i<n; i++)
		strcpy(p[i],a[i]);
}
