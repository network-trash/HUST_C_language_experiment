#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,f,g,h,i,j,x;
	printf("输入正整数x(2<=x<=79)\n");
	for(x=2;x<=79;x++)
	{
		for(a=0;a<10;a++)
		for(b=0;b<10;b++)
		{
			if((b-a)==0)	continue;
			for(c=0;c<10;c++)
			{
				if((c-b)*(c-a)==0) continue;
				for(d=0;d<10;d++)
				{
					if((d-c)*(d-b)*(d-a)==0) continue;
					for(e=0;e<10;e++)
					{
						if((e-d)*(e-c)*(e-b)*(e-a)==0) continue;
						for(f=0;f<10;f++)
						{
							if((f-e)*(f-d)*(f-c)*(f-b)*(f-a)==0) continue;
							for(g=0;g<10;g++)
							{
								if((g-f)*(g-e)*(g-d)*(g-c)*(g-b)*(g-a)==0) continue;
								for(h=0;h<10;h++)
								{
									if((h-g)*(h-f)*(h-e)*(h-d)*(h-c)*(h-b)*(h-a)==0) continue;
									for(i=0;i<10;i++)
									{
										if((i-h)*(i-g)*(i-f)*(i-e)*(i-d)*(i-c)*(i-b)*(i-a)==0) continue;
										for(j=0;j<10;j++)
										{
											if((j-i)*(j-h)*(j-g)*(j-f)*(j-e)*(j-d)*(j-c)*(j-b)*(j-a)==0) continue;
											if((a*10000+b*1000+c*100+d*10+e)==(f*10000+g*1000+h*100+i*10+j)*x)
												printf("%d%d%d%d%d/%d%d%d%d%d=%d\n",a,b,c,d,e,f,g,h,i,j,x);
											
																				
										}
									}
								}
							}
						}
					}
				}		
			}		
		}	
	}
	return 0;
}
