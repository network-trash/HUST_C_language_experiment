#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s_data{
	char student_number[12];
	char name[8];
	float score[6];	//第一位是英语，第二位是高等数学，第三位是普通物理，第四位是C语言程序设计 
};
struct s_list{
	struct s_data data;
	struct s_list *next;
};
void create_list (struct s_list **headp);
struct s_data input (struct s_data, int);
void output (struct s_list *head);
void calculte_average (struct s_list *head);
void super_output(struct s_list *head);
void free_list (struct s_list *head);
void sort_data (struct s_list *head);
int main(void)
{
	int flag = 0;
	float average; 
	struct s_list *head;
	
	create_list(&head);
	output(head);
	calculte_average (head);
	super_output(head);
	sort_data (head);
	super_output(head);
	free_list(head);
	return 0;
}
void create_list (struct s_list **headp)
{
	int i=1, j, n;
	printf("请输入班级人数\n");
	scanf("%d",&n);
	struct s_list *head = NULL, *tail;
	head = (struct s_list*)malloc(sizeof(struct s_list));
	head->data = input(head->data, i);
	tail = head;
	while(i<n)
	{
		tail->next = (struct s_list*)malloc(sizeof(struct s_list));
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
void output (struct s_list *head)
{
	struct s_list *p = head;
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
void super_output(struct s_list *head)
{
	struct s_list *p = head;
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
void calculte_average (struct s_list *head)
{
	while(head)
	{
		head->data.score[4] = (head->data.score[0]+head->data.score[1]+head->data.score[2]+head->data.score[3]);
		head->data.score[5]	= (head->data.score[4])/4;
		head = head->next;
	}
}
void sort_data (struct s_list *head)
{
	struct s_data *temp = (struct s_data*)malloc(sizeof(struct s_data));
	struct s_list *p1 = head, *p2;
	for(; p1; p1 = p1->next)
		for(p2 = p1->next; p2; p2 = p2->next)
		{
			if(p1->data.score[5] > p2->data.score[5])
			{
				*temp = p1->data;
				p1->data = p2->data;
				p2->data = *temp;
			}	
		}
	free(temp);
}
void free_list (struct s_list *head)
{
	struct s_list *temp;   //要设置一个变量暂存一下子 
	while(head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
