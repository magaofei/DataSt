#include "stdio.h"
#include "stdlib.h"
typedef struct student //typedef ������ ����
{
	char name[15];
	int mark;
	struct student *next;
}Node,*node;
main()
{
	int num,i;
	//����ͷָ��
	node p,p1,head;//ָ��
	head =(node)malloc(sizeof(Node));//�����ڴ�ռ�
	if(!head)
	{
	printf("ͷ�ڵ��ڴ����ʧ��");
	exit(1);
	}
	else
	{
	head->next =NULL;//ͷ�ڵ��ַ��Ϊ��
	}

}
