/*实验5-1程序改错与跟踪调试题程序*/
#include<stdio.h>
void strcate(char [],char []);
void strdelc(char [],char );
int main(void)
{
	char a[20]="Language",b[20]="Programming";
	
	printf("%s %s\n", b,a);
	strcate(b,a);	
	printf("%s %s\n",b,a);
	strdelc(b, 'a');	
	printf("%s\n",b);
	
	return 0;
}
void strcate(char t[],char s[])
{
	int i = 0,  j = 0;
	while(t[i++]);
	i--;  //逻辑错误1：注意到最后的值是0以后的值。 
	while((t[i++] = s[j++])!= '\0');//逻辑错误2：越界操作 
}
void strdelc(char s[], char c)
{
	int j,k;
	for(j=k=0; s[j] != '\0'; j++)
		if(s[j] != c)	
			s[k++] = s[j];//结束时未把最后的删除。
	for(;k<=j;k++)//此循环就是用来把后面的值全部复位成0/ 
		s[k] = '\0'; 
}
