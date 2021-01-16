#include<stdio.h>
int main()
{
	printf("ÇëÊäÈë×Ö·û\n");
	char c;
	c=getchar();
    while(c!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			c=c+0x20;
			putchar(c);
		}
		else
		putchar(c);
		c=getchar();	
	}	
 	return 0;
}

