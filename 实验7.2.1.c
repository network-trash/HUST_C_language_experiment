#include<stdio.h> 
/*
		(++p)->x  100
		p++,p->c  'B'
		*p++->t,*p->t 'x'
		*(++p)->t  'x'
		*++p->t   'y'
		++*p->t   'y'
*/
int main(void)
{
	char u[]="UVWXYZ";
	char v[]="xyz";
	struct T{
		int x;
		char c;
		char *t;
	}a[]={{11,'A',u},{100,'B',v}},*p=a;
//	printf("%d\n",(++p)->x);
//	printf("%c\n",(p++,p->c));
//	printf("%c\n",(*p++->t,*p->t));
//	printf("%c\n",*(++p)->t);
//	printf("%c\n",*++p->t);
	printf("%c\n",++*p->t);
	return 0;
}
