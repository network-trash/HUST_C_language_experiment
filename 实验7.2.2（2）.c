/*
修改替换create_list函数，将其建成一个后进先出的链表
，后进先出链表的头指针始终指向最后创建的结点（链头），
后建结点指向先建结点，先建结点始终是尾结点。
*/
#include "stdio.h"
#include "stdlib.h"
struct s_list{
	int data; /* 数据域 */
	struct s_list *next; /* 指针域 */ 
};
void create_list (struct s_list **headp,int *p);
void free_list (struct s_list *); //最终要全部释放掉 
int main(void)
{
	struct s_list *head=NULL,*p;
	int s[]={1,2,3,4,5,6,7,8,0}; /* 0为结束标记 */
	create_list(&head,s); /* 创建新链表 */   /////这里也要做出变换 
	p = head; /*遍历指针p指向链头 */
	while(p){
		printf("%d\t",p->data); /* 输出数据域的值 */
		p=p->next; /*遍历指针p指向下一结点 */
	}
	printf("\n");
	free_list(head);
	return 0;
}
void create_list(struct s_list **headp,int *p) //////注意这里会修改头指针，因此要用二维指针 
{
	struct s_list *loc_head=NULL, *tail;
	if(!(*p))	/* 相当于*p==0 */
		;
	else
	{
		loc_head = (struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data = *p++;
		loc_head->next = NULL;//最后一个节点空值 
		tail = loc_head;
		while(*p)
		{	
			loc_head = (struct s_list *)malloc(sizeof(struct s_list));
			loc_head->next = tail;
			tail = loc_head;
			tail->data = *p++;
		}
	}
	*headp = loc_head;
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
