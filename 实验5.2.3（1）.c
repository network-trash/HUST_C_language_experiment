#include<stdio.h>
#include<string.h>
#include<math.h>
#define BASE 32 //64位计算机 
void reverse (char a[]);
int main(void)
{
	int x,y,i,j;
	printf("请输入一个数字(小于2的32次方)，将以机内二进制展示\n");
	while(scanf("%d",&x)!=EOF)
	{
		char c[BASE+1];
		c[BASE]='\0';
		if(x>0)
		{
			for(i=0;i<BASE;i++)
			{
				c[i] = '0';
			}
			for(i=0;x>=1;i++)
			{
				y=(x%2);
				c[i]=(y+'0');
				x/=2;
			}
			reverse(c);
			printf("%s",c);
		}
		else if(x<0)
		{
			x=-x;
			x=x^((int)(pow(2,BASE)-1));
			c[BASE-1]='1';
			x++;
			for(i=0;x>=1;i++)
			{
				y=(x%2);
				c[i]=(y+'0');
				x/=2;
			}
			reverse(c);
			printf("%s",c);
		}
		else
		{
			for(i=0;i<BASE;i++)
			{
				c[i] = '0';
			}
			printf("%s",c);
		}
		printf("\n请再次输入，如果想要退出请输入Ctrl+Z\n");
	}
	
	return 0;
}
void reverse (char a[])
{
	int c,j,k;
	for(j=0,k=strlen(a)-1;j<k;j++,k--)
	{
		c=a[j];
		a[j]=a[k];
		a[k]=c;
	}
}
