#include<stdio.h>
enum{COPY ,DELETE};
int main(void)
{
	char c;
	int state = COPY;
	printf("请输入一段文章，我会将中间的多个空格变成一个,文章请以回车再加Ctrl+Z结尾\n");
	while((c=getchar())!=EOF)
	{
		switch(state)
		{ 
		case COPY : (c==' ') ?  (state=DELETE,putchar(' ')): (putchar(c),state=COPY); break ;    //状态COPY接受到‘ ’时转化为delete模式；否则不变 
		case DELETE : (c==' ') ? state=DELETE : (putchar(c),state=COPY); break ;  //状态DELETE接受到‘ ’时继续，否则输出‘ ’ 
		}
	}
	return 0;
} 
