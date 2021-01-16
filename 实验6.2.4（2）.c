#include<stdio.h>
#define M 20
int x[M][M];//用来存储旋转后的值 
void spin (int *, int, int);
int main(void)
{
	int m,n,flag;
	int a[M][M]={0},i,j;
	do
	{
		for(i=0;i<M;i++)
			for(j=0;j<M;j++)
				a[i][j] = 0, x[i][j] = 0;
		printf("请输入矩阵的行数以及列数(行和列均不超过20)\n");
		scanf("%d%d",&n,&m);
		getchar();
		printf("请输入你的矩阵\n");
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				a[i][j] = getchar();
				getchar();
			}
		spin(a[0],n,m);
	
		for(i=0;i<m;i++) //行数列数颠倒 
		{
			for(j=0;j<n;j++)
				putchar(x[i][j]);
			printf("\n");
		}
		printf("是否继续，如果选择是，那么输入1，如果不再执行，那么输入0\n"); 
		scanf("%d",&flag);
	}while(flag);
	
	return 0;
}
void spin (int *p, int n, int m) //n表示行数，m表示列数 
{
	int i,j;//这个数组有m行，n列 
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			x[m-1-j][i] = *(p+M*i+j);
}
