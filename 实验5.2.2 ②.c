#include<stdio.h>
#define M 10 
#define N 3
int main(void)
{
	int a[M], b[M];	
	int i, j, k;
	int q;
	for(i = 0; i < M; i++)
		a[i] = i + 1;
	for(i = M, j = 0; i > 1; i--)
	{
		for(k = 1; k <= N; k++)			/* 1至N报数 */
		{
			if(!(a[j]))  //此步骤用来控制跳过a数组中的空元素 
			{
				if(j < M-1)
				{
					j++;//这一步是向下进行一步 
					k--;//这一步是用来把k返回原来那个值 
					continue;
				}
				else
				{
					j=0;
					k--;
					continue;
				}
			}
			if(++j > M-1 )
			{
				j = 0;
			}
		}
		if(j)
			b[M-i] = a[j-1];
		else
		{
			for(q=M;!a[q-1];q--);//找到最后一个不是空元素的集合 
			b[M-i] = a[q-1];
		}
		if(j)
			a[j-1]='\0';
		else
			a[q-1]='\0';
	}
	
	for(i = 0;i < M-1; i++)		/* 按次序输出出圈人的编号 */
		printf("%6d",b[i]);
	for(i=0;i < M-1;i++)
	{
		if(a[i])
		printf("\n%6d", a[i]);
	}
	
	return 0;
}
