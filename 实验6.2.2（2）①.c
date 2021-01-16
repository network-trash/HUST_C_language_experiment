/*
下面源程序通过函数指针和菜单选择来调用库函数实现字符串操作；
串复制strcpy、串连接strcat或串分解strtok。
*/ 
#include<stdio.h>
#include<string.h>
int main (void)
{
	char* (*p)(char*, const char*);
	char a[80], b[80], *result;
	int choice;
	while(1)
	{
		do{
			printf("\t\t1 copy string.\n");
			printf("\t\t2 connect string.\n");
			printf("\t\t3 parse string.\n");
			printf("\t\t4 exit.\n");
			printf("\t\tinput a number (1-4) please.\n");
			scanf("%d", &choice);
		}
		while(choice<1 || choice>4);
		switch(choice)
		{
			case 1:	p = strcpy;	break;
			case 2:	p = strcat;	break;
			case 3:	p = strtok;	break;	//这个地方打错了 //这个函数的作用是将其阻断 
			case 4:	goto down;
		}
		getchar();//将上一次的回车吸收； 
		printf("input the first string please!\n");
		gets(a);
		printf("input the second string please!\n");
		gets(b);
		result = p(a, b);
		printf("the result is %s\n", result);
	}
	down:
	return 0;
}
