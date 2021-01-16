/*
一个长整型变量占4个字节，
其中每个字节又分成高4位和低4位。
试从该长整型变量的高字节开始，
依次取出每个字节的高4位和低4位
并以十六进制数字字符的形式进行显示，
要求通过指针取出每字节。
*/
#include<stdio.h>//注意存储结构问题 

int main(void)
{
	int n;
	long x;
	printf("输入1，则进入16进制输入\n输入2，则进入10进制输入\n"); 
	do
	{
		printf("请输入你选择的模式\n");
		scanf("%d",&n);
	}while(n<1||n>2);
	switch(n)
	{
		case 1: printf("请以16进制数输入\n");scanf("%lx",&x);break;
		case 2: printf("请以10进制数输入\n");scanf("%ld",&x);break;
	}
	
	char *p = (char *) &x;
	char up_half,low_half;
	int k;//控制循环次数的参量
	printf("\t\t高四位\t低四位\n");
	for(k=0,p=p+3;k<4;k++,p--)
	{
		low_half=(*p)&0x0f;	//00001111
		if(low_half<10)
			low_half|=0x30;
		else
			low_half+='A'-10;
		up_half=(*p>>4)&0x0f;
		if(up_half<10)
			up_half|=0x30;
		else
			up_half+='A'-10;
		printf("第%d个字节\t",k+1);
		printf("%c\t%c\t\n",up_half,low_half);
	}
	return 0;
}
