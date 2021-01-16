#include <stdio.h>
int main( )
{
   int m, n, k, p, i, d;
   printf("input m, n \n");
   scanf("%d%d", &m, &n);
   if (m<n)								
   {
	    m=m^n;
		n=m^n;
		m=m^n;
   }
   k = 0;
   while(m&1==0&&n&1==0)			    
   {
	   m>>=1;			                 	 
	   n>>=1;
	   k++;
   }
   for(p=1,i=0;i<k;i++) 
       p<<=1;			                      
   while((d=m-n)!=n)
   {
	   if(d>n)
	    m = d;
	   else
		{
			m = n,n = d;
        }	
   }
   d *=p;
   printf("the greatest common divisor : %d", d);
   return 0;
}
