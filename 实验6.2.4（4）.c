#include<stdio.h>
#include<stdlib.h>
#define N 20
void task0 (void){printf("task0 is called!\n");}
void task1 (void){printf("task1 is called!\n");}
void task2 (void){printf("task2 is called!\n");}
void task3 (void){printf("task3 is called!\n");}
void task4 (void){printf("task4 is called!\n");}
void task5 (void){printf("task5 is called!\n");}
void task6 (void){printf("task6 is called!\n");}
void task7 (void){printf("task7 is called!\n");}
void scheduler (void);
void execute (void(*[])(void),int);
int a[N];//存储编号 
int main(void)
{
	scheduler();
	return 0;
}
void scheduler (void)
{
	#ifndef R
	#define R
	int i,flag=0;
	void (*p[8]) (void) = {task0, task1, task2, task3, task4, task5, task6, task7};
	#endif
	
	for(i=0; i<N; i++)
		a[i] = 0;
	do
	{
		printf("请输入你要调用的任务(请输入的任务数在0-7之间)(最多二十个任务)，请以回车结尾\n");
		for(i=0;a[i-1] != '\n'-'0';i++)
		{
			a[i] = getchar() - '0';
		}
		a[i-1] = 0;
		flag = 0;
		for(int q=0; q<i-1; q++)
			if(a[q] < 0 || a[q] > 7)
			{
				printf("你输入了至少一个错误任务请再次输入\n");
				flag = 1;
			}
	}while(flag == 1);
	
	execute(p,i-1);
}
void execute (void(*q[])(void),int n)
{
	int j;
	for(j=0; j<n; j++)
		q[a[j]]();
	printf("是否还要继续，如果要继续那么输入1，如果不继续输入0\n"); 
	scanf("%d",&j);
	getchar();
	if(j)
		scheduler();
}
