/*实验4-1改错与跟踪调试题程序：计算平方差、将换两数*/ 
#include<stdio.h>
#define SUM (a+b)  //逻辑错误1：会引起二义性 
#define DIF (a-b)  //同上 
#define SWAP(a,b)  ((a=a^b),(b=a^b),(a=a^b))  //要有中间量或者使用位运算 
int main() 
{
    int a,b;
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM, SUM*DIF);
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);
    return 0;
}
