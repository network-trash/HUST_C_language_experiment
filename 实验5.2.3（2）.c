/*思考如何传入一个多维数组*/
//只能输入少于127个人 
#include<stdio.h>
void sort (int b[],int n);  //改变顺序的函数 

 
int main(void)
{
	int n;
	printf("please input the number of your classmate \n");
	scanf("%d",&n);
	
	char a[n][8];
	int b[n];
	printf("请依次输入姓名和成绩，每次输入后请输入回车\n"); 
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		scanf("%d",&b[i]);
	}
	sort(b,n);
	for(i=0;i<n;i++)
	{
		printf("%s",a[i]);
		printf("%5d\n",b[i]);
	}
	
	return 0;
}
void sort (int b[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]<b[j])
			{
				b[i]=b[i]^b[j];
				b[j]=b[i]^b[j];
				b[i]=b[i]^b[j];
			}
			else
				continue;
		}
	}
}

