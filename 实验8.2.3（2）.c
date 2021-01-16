/*
从键盘输入10个单精度浮点数，
以二进制形式存入文件float.dat中。
再从文件中读出这10个单精度浮点数显示在屏幕上。
之后要求将float.dat中的单精度浮点数按字节读出来，
观察写入文件的浮点数字节数据是不是和计算机内存中表示的浮点数字节数据一致。
*/
#include<stdio.h>
#include<stdlib.h>
#define M (sizeof(float))
#define N 1 
int main(void)
{
	int i; 
	float input[N] = {0}, output;
	unsigned char c;
	for(i=0; i<N; i++)
		scanf("%f",&input[i]);
	/*写入文件*/
	FILE *fp;
	fp = fopen("float.dat","wb+");
	fwrite(input,M,N,fp);
	rewind(fp);
	while(fread(&output,sizeof(float),1,fp))
		printf("%f\n",output);
	rewind(fp);
	while(fread(&c,sizeof(unsigned char),1,fp))
		printf("%02X",c);
	return 0;
}
