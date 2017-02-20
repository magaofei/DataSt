#include "stdio.h"
#include "stdlib.h"
typedef struct student //typedef 类型名 别名
{
	char name[15];
	int mark;
	struct student *next;
}Node,*node;
main()
{
	int num,i;
	//定义头指针
	node p,p1,head;//定义指针（指针变量）
	head =(node)malloc(sizeof(Node));//为头结点分配内存空间
	if(head==NULL)
	{
	printf("头结点内存分配失败");
	exit(1);
	}
	else
	{
	head->next =NULL;//头节点地址域为空
	}


	//定义单链表中的其他结点
	printf("请输入学生人数：\n");
	scanf("%d",&num);
    printf("请输入%d名学生信息：\n",num);
	for(i=0;i<num;i++)
	{
	p =(node)malloc(sizeof(Node));//为其它结点分配内存空间
	if(head==NULL)
	{
	printf("结点内存分配失败");
	exit(1);
	}
	//结点内存分配成功，给结点数据赋值
	else
	{
	printf("第%d名学生姓名\n",i+1);
	scanf("%s",&p->name);
	printf("第%d名学生成绩\n",i+1);
	scanf("%d",&p->mark);
	//如果是第一个结点，将第一个结点的地址赋值给头指针
	if(head->next==NULL)
	{
	head->next=p;
	p1=p;
	}
	//如果不是第一个结点，将新结点的地址赋值上一个结点的next域
	else
	{
		p1->next=p;
		p1=p;
	}
	}
	
	}
	//最后一个结点的next域为空
	p1->next=NULL;
	//以头结点为起点遍历整个单链表并输出
	p=head->next;
	printf("该单链表中的信息如下：\n");
	while(p!=NULL)
	{
	printf("name:%s\n",p->name);
    printf("mark:%d\n",p->mark);
	p=p->next;
	}
}
