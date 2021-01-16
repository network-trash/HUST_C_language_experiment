#include<stdio.h>
char *strcopy(char *, const char *);
int main(void)
{
	char *s1, *s2, *s3; 	//这样的指针无所指，需要给它们开辟一些单元，然后让这些指针指向对应的内存单元 
	char a[20],b[20],c[20];
	s1=a,s2=b,s3=c;
	printf("Input a string:\n");//无须保留这个s2 
	scanf("%s", s2);
	strcopy(s1, s2);
	printf("%s\n", s1);
	printf("Input a string again:\n");//无须保留这个s2 
	scanf("%s", s2);
	s3 = strcopy(s1, s2);
	printf("%s\n", s3);
	return 0;
}

/*将字符串s复制给字符串t，并且返回串t的首地址*/
char * strcopy(char *t, const char *s)
{
	char *p = t; 
	while(*t++ = *s++);//循环结束的时候t的值已经不是首地址了 ，因此我们首先要先存储这个地址 
	return (p);
}
