#include <stdio.h>
int main()
{ 
	int i, x, k, j, flag1 = 0 ,flag2 = 0 ,flag3 = 0;
	printf("本程序求纯粹合数\n"); 
	for (j=100;j<1000;j++)
	{
		x=j;
		for (i=2,k=(x>>1);i<=k;i++) 
			if (!(x%i))
			{
				flag1 = 1;
				break;
			}
		if (0 == flag1)
			continue;
		else 			
		{
			x=j/10;
			for (i=2,k=(x>>1);i<=k;i++) 
				if (!(x%i))
				{
					flag2 = 1;
					break;
				}
			if (0 == flag2) 
				continue;
			else
			{
				x=j/100;
				for (i=2,k=(x>>1);i<=k;i++) 
					if (!(x%i))
					{
						flag3 = 1;
						break;
					}
				if (0 == flag3) 
					continue;
			}
			
		}
	if((flag1==1)&&(flag2==1)&&(flag3==1))
	{
		printf("%6d",j);
		flag1 =0;
		flag2 =0;
		flag3 =0;
	}
	}
return 0;
}
