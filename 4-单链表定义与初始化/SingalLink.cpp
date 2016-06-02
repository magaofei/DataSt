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
	node p,p1,head;//指针
	head =(node)malloc(sizeof(Node));//分配内存空间
	if(!head)
	{
	printf("头节点内存分配失败");
	exit(1);
	}
	else
	{
	head->next =NULL;//头节点地址域为空
	}

}
