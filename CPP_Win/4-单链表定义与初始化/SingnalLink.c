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
	node p,p1,head;//����ָ�루ָ�������
	head =(node)malloc(sizeof(Node));//Ϊͷ�������ڴ�ռ�
	if(head==NULL)
	{
	printf("ͷ����ڴ����ʧ��");
	exit(1);
	}
	else
	{
	head->next =NULL;//ͷ�ڵ��ַ��Ϊ��
	}


	//���嵥�����е��������
	printf("������ѧ��������\n");
	scanf("%d",&num);
    printf("������%d��ѧ����Ϣ��\n",num);
	for(i=0;i<num;i++)
	{
	p =(node)malloc(sizeof(Node));//Ϊ�����������ڴ�ռ�
	if(head==NULL)
	{
	printf("����ڴ����ʧ��");
	exit(1);
	}
	//����ڴ����ɹ�����������ݸ�ֵ
	else
	{
	printf("��%d��ѧ������\n",i+1);
	scanf("%s",&p->name);
	printf("��%d��ѧ���ɼ�\n",i+1);
	scanf("%d",&p->mark);
	//����ǵ�һ����㣬����һ�����ĵ�ַ��ֵ��ͷָ��
	if(head->next==NULL)
	{
	head->next=p;
	p1=p;
	}
	//������ǵ�һ����㣬���½��ĵ�ַ��ֵ��һ������next��
	else
	{
		p1->next=p;
		p1=p;
	}
	}
	
	}
	//���һ������next��Ϊ��
	p1->next=NULL;
	//��ͷ���Ϊ�������������������
	p=head->next;
	printf("�õ������е���Ϣ���£�\n");
	while(p!=NULL)
	{
	printf("name:%s\n",p->name);
    printf("mark:%d\n",p->mark);
	p=p->next;
	}
}
