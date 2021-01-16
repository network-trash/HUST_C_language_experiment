/*
编写一个程序replace，采用命令行方式，
用给定的字符串替换指定文件中的目标字符串，
并显示输出替换的个数。例如，命令行：
replace filename.txt you they
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char* argv[])
{//如何重新打开stdout 
	int i=0;
	if(argc != 4)
	{
		printf("Arguments error!\n");exit(-1);
	}
	freopen(argv[1],"r+",stdin);
	freopen("C:\\Users\\dell\\Desktop\\实验8\\实验8.2.3(1)测试文件夹\\temp.txt","w+",stdout);
	char a[20];
	
	while(scanf("%s",a) != EOF)
	{
		if(strcmp(a,argv[2])==0)
		{
			printf("%s",argv[3]);
			putchar(' ');
			i++;
		}
		else
		{
			printf("%s",a);
			putchar(' ');
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	remove(argv[1]);
	rename("C:\\Users\\dell\\Desktop\\实验8\\实验8.2.3(1)测试文件夹\\temp.txt",argv[1]);
	freopen("CON","w",stdout); 
	printf("\n替换的个数有%d个",i);
	return 0;
}
