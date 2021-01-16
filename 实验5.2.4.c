/*编写函数strnins(s,t,n),
其功能是：可将字符数组 t中的字符串插入到字符数组 s中字符串的第n个字符的后面。*/
#include<stdio.h>
void strnins(char s[],char t[],int n);
int main(void)
{
	char t[40],s[40];
	int n;
	printf("请输入两个字符然后再输入你要插入的位置\n"); 
	scanf("%s%s",s,t);
	scanf("%d",&n);
	strnins(s,t,n);
	
	printf("%s",s);
	return 0;
}
void strnins(char s[],char t[],int n)
{
	int i,j,w=0,e=0;
	char a[40];
	while(1)
	{
		if(s[w]<0)
			w+=2,e++;
		else
			w++,e++;
		if(e==n)
			break;
	}
	for(i=w,j=0;s[i]!='\0';i++,j++)
	{
		a[j]=s[i];
	}
	for(i=w,j=0;t[j]!='\0';i++,j++)//i=n时实际上是第n+1个
	{
		s[i]=t[j];
	}
	for(j=0;a[j]!='\0';i++,j++)
	{
		s[i]=a[j];
	}
	s[i]='\0';
}
