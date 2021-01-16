#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s_data{
	char student_number[12];
	char name[8];
	float score[6];	//第一位是英语，第二位是高等数学，第三位是普通物理，第四位是C语言程序设计 
};
struct d_list{
	struct s_data data;
	struct d_list *prior;
	struct d_list *next;
};
struct s_data input (struct s_data data, int n);
void output (struct d_list *head);
void create_d_list (struct d_list **);
void correct (struct d_list *head);
void free_list (struct d_list *head);
void calculte_average (struct d_list *head);
void super_output(struct d_list *head);
int main(void)
{
	int flag;
	struct d_list *head;
	create_d_list(&head);
	output(head);
	printf("需要修改吗？如果修改请输入1，如果不修改输入0\n");
	scanf("%d",&flag);
	while(flag)
	{
		correct (head);
		printf("还修改吗，如果修改请输入1，如果不修改输入0\n");
		scanf("%d",&flag);
	}
	calculte_average (head);
	super_output(head);
	free_list(head);
	return 0;
}
void create_d_list (struct d_list **headp)
{
	int i=1, j, n;
	printf("请输入班级人数\n");
	scanf("%d",&n);
	struct d_list *head = NULL, *tail;
	head = (struct d_list *)malloc(sizeof(struct d_list));
	head->data = input(head->data,i);
	tail = head;
	while(i<n)
	{
		tail->next = (struct d_list *)malloc(sizeof(struct d_list));
		tail->next->prior = tail;
		tail = tail->next;
		i++;
		tail->data = input(tail->data,i);
	}
	tail->next = NULL;
	*headp = head;
}
struct s_data input (struct s_data data, int n)
{
	printf("请输入第%d个人的信息\n",n);
	printf("学号："); scanf("%s",data.student_number);
	printf("姓名："); scanf("%s",data.name);
	printf("英语成绩："); scanf("%f",&data.score[0]);
	printf("高等数学成绩："); scanf("%f",&data.score[1]);
	printf("普通物理成绩："); scanf("%f",&data.score[2]);
	printf("C语言程序设计成绩："); scanf("%f",&data.score[3]);
	return data;
}
void output (struct d_list *head)
{
	struct d_list *p = head;
	printf("%9s%12s%15s%15s%18s%18s\n","学号","姓名","英语成绩","高等数学成绩","普通物理成绩","C语言程序设计成绩");
	while(p)
	{
		printf("%9s\t",(p->data).student_number); 
		printf("%6s\t\t",(p->data).name);
		for(int i=0; i<4; i++)
			printf("%0.2f\t\t",(p->data).score[i]);
		printf("\n");
		p = p->next;
	}
}
void correct (struct d_list *head)
{
	struct d_list *p = head;
	int flag = 1;//判断是否输错了 
	char name_input[8];
	do
	{
		head = p;
		printf("请输入你要修改的学生姓名\n");
		scanf("%s",name_input);
		while(head)
		{
			
			if(!strcmp(head->data.name, name_input))
			{
				flag--;
				break;
			}
			head = head->next;
		}
		if(flag)
		{
			printf("没有找到这个学生，请问你还要重新输入吗。\n输入1则重新输入，输入2则退出\n");
			scanf("%d",&flag);
			if(flag == 2) break;
		}
	}while(flag);
	if(!flag)
	{
		int flag1,flag2=0;
		do
		{
			printf("请选择修改的数据\n1 学号\n2 姓名\n3 英语成绩\n4 高等数学成绩\n5 普通物理成绩\n6 C语言成绩\n7 退出\n");
			scanf("%d",&flag1);
			switch(flag1)
			{
				case 1 : printf("请输入修改后学号："); scanf("%s",head->data.student_number);break;
				case 2 : printf("请输入修改后姓名："); scanf("%s",head->data.name); break;
				case 3 : printf("请输入修改后英语成绩："); scanf("%f",&head->data.score[0]);break;
				case 4 : printf("请输入修改后高等数学成绩："); scanf("%f",&head->data.score[1]);break;
				case 5 : printf("请输入修改后普通物理成绩："); scanf("%f",&head->data.score[2]);break;
				case 6 : printf("请输入修改后C语言程序设计成绩："); scanf("%f",&head->data.score[3]);break;
				case 7 : flag2++; break;		
			}
		}while(!flag2);
	}
}
void super_output(struct d_list *head)
{
	struct d_list *p = head;
	printf("%9s%12s%15s%15s\n","学号", "姓名", "总成绩", "平均成绩");
	while(p)
	{
		printf("%9s\t",(p->data).student_number); 
		printf("%6s\t\t",(p->data).name);
		for(int i=4; i<6; i++)
			printf("%0.2f\t\t",(p->data).score[i]);
		printf("\n");
		p = p->next;
	}
}
void calculte_average (struct d_list *head)
{
	while(head)
	{
		head->data.score[4] = (head->data.score[0]+head->data.score[1]+head->data.score[2]+head->data.score[3]);
		head->data.score[5]	= (head->data.score[4])/4;
		head = head->next;
	}
}
void free_list (struct d_list *head)
{
	struct d_list *temp; //要设置一个变量暂存一下子 
	while(head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
