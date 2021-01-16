#include<stdio.h>
int strlen (const char s[]);
char* strcmp (const char *,const char *);
char* strstr (const char *,const char *);
int main(void)
{
	int choice;
	char a[20],b[20],*result;
	char *(*p[2])(const char *,const char *) = {strcmp, strstr};
	while(1)
	{
		do{
			printf("\t\t1 compare string and input the bigger one.\n");
			printf("\t\t2 search the second string from the first one\n");
			printf("\t\t3 exit.\n");
			printf("\t\tinput a number (1-3) please.\n");
			scanf("%d", &choice);
		}
		while(choice<1 || choice>3);
		if(choice == 3) goto down;
		getchar();
		printf("input the first string please!\n");
		gets(a);
		printf("input the second string please!\n");
		gets(b);
		result = p[choice-1](a, b);
		printf("the result is %s\n", result);
	}
	down:
	return 0;
}
char* strcmp (const char *p,const char *q)
{
	int i = 0;//可以定义标号来让他变得单出口 
	for(; *(p+i) && *(q+i); i++)
	{
		if(*(p+i) > *(q+i))
			return (char*)p;
		else if(*(p+i) < *(q+i))
			return (char*)q;
		else 
			continue;
	}
	if(strlen(p) > strlen(q))
		return (char*)p;
	else
		return (char*)q;
	
}
char* strstr (const char *cs,const char *ct)
{
	int j=0,k;
	for(;cs[j] != '\0';j++)
		if(cs[j]==ct[0])
		{
			k=1;
			while(cs[j+k]==ct[k]&&ct[k]!='\0')
				k++;
			if(k==strlen(ct))
				return (char*)(cs+j);
		}
	return NULL;
}
int strlen (const char s[])
{
	int j=0;
	while(s[j]!='\0')	j++;
	return j;
}
