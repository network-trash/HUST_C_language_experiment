#include<stdio.h>
#define PI 3.14159
int main (void)
{
   int f ;
   int p, k ;
   int newint; 
   double c, r, s ;

/* 任务1 */
   printf("Input Fahrenheit: " ) ;
   scanf("%d",&f);                                             //此行的双引号未用英文的双引号,变量f前未加&符号 
   c = 5.0/9.0*(f-32);                                              //注意优先级问题 
   printf( "\n %d (F) = %.2f (C)\n\n ", f, c ) ;                //此行的双引号未用英文的双引号 

/* 任务2 */
   
   printf("input the radius r:");
   scanf("%lf", &r);
   s=PI*r*r;                                                         
   printf("\nThe acreage is %.2f\n\n",s);                          //不用加 & 符号 

/* 任务3 */
   k = 0xa1b2, p = 0x8432; 
   newint = (p & 0xff00)|(k>>8 & 0x00ff);                                           //newint未定义 
   printf("new int = %#x\n\n",newint);                            
   
   return 0;
}
