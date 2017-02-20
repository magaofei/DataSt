#include "c4-1.h"
/*basic operator*/
Status StrAssign(SString T,char *chars)
 { /* ����һ����ֵ����chars�Ĵ�T */
   int i;
   if(strlen(chars)>MAXSTRLEN)
     return ERROR;
   else
   {
     T[0]=strlen(chars);
     for(i=1;i<=T[0];i++)
       T[i]=*(chars+i-1);
     return OK;
   }
 }

 Status StrCopy(SString T,SString S)
 { /* �ɴ�S���Ƶô�T */
   int i;
   for(i=0;i<=S[0];i++)
     T[i]=S[i];
   return OK;
 }

 Status StrEmpty(SString S)
 { /* ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
   if(S[0]==0)
     return TRUE;
   else
     return FALSE;
 }

 int StrCompare(SString S,SString T)
 { /* ��ʼ����: ��S��T���� */
   /* �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
   int i;
   for(i=1;i<=S[0]&&i<=T[0];++i)
     if(S[i]!=T[i])
       return S[i]-T[i];
   return S[0]-T[0];
 }

 int StrLength(SString S)
 { /* ���ش���Ԫ�ظ��� */
   return S[0];
 }

 Status ClearString(SString S)
 { /* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
   S[0]=0;/* ���Ϊ�� */
   return OK;
 }

 Status Concat(SString T,SString S1,SString S2) 
 { /* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
   int i;
   if(S1[0]+S2[0]<=MAXSTRLEN)
   { /* δ�ض� */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=S2[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=S1[0]+S2[0];
     return TRUE;
   }
   else
   { /* �ض�S2 */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=MAXSTRLEN-S1[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=MAXSTRLEN;
     return FALSE;
   }
 }

 Status SubString(SString Sub,SString S,int pos,int len)
 { /* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ����㷨4.3 */
   int i;
   if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
     return ERROR;
   for(i=1;i<=len;i++)
     Sub[i]=S[pos+i-1];
   Sub[0]=len;
   return OK;
 }

 int Index(SString S,SString T,int pos)
 { /* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,����ֵΪ0�� */
   /* ����,T�ǿ�,1��pos��StrLength(S)���㷨4.5 */
   int i,j;
   if(1<=pos&&pos<=S[0])
   {
     i=pos;
     j=1;
     while(i<=S[0]&&j<=T[0])
       if(S[i]==T[j]) /* �����ȽϺ���ַ� */
       {
         ++i;
         ++j;
       }
       else /* ָ��������¿�ʼƥ�� */
       {
         i=i-j+2;
         j=1;
       }
     if(j>T[0])
       return i-T[0];
     else
       return 0;
   }
   else
     return 0;
 }

 Status StrInsert(SString S,int pos,SString T)
 { /* ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
   /* �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
   int i;
   if(pos<1||pos>S[0]+1)
     return ERROR;
   if(S[0]+T[0]<=MAXSTRLEN)
   { /* ��ȫ���� */
     for(i=S[0];i>=pos;i--)
       S[i+T[0]]=S[i];
     for(i=pos;i<pos+T[0];i++)
       S[i]=T[i-pos+1];
     S[0]=S[0]+T[0];
     return TRUE;
   }
   else
   { /* ���ֲ��� */
     for(i=MAXSTRLEN;i<=pos;i--)
       S[i]=S[i-T[0]];
     for(i=pos;i<pos+T[0];i++)
       S[i]=T[i-pos+1];
     S[0]=MAXSTRLEN;
     return FALSE;
   }
 }

 Status StrDelete(SString S,int pos,int len)
 { /* ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
   /* �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
   int i;
   if(pos<1||pos>S[0]-len+1||len<0)
     return ERROR;
   for(i=pos+len;i<=S[0];i++)
     S[i-len]=S[i];
   S[0]-=len;
   return OK;
 }

 Status Replace(SString S,SString T,SString V)
 { /* ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
   /* �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
   int i=1; /* �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
   if(StrEmpty(T)) /* T�ǿմ� */
     return ERROR;
   do
   {
     i=Index(S,T,i); /* ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
     if(i) /* ��S�д��ڴ�T */
     {
       StrDelete(S,i,StrLength(T)); /* ɾ���ô�T */
       StrInsert(S,i,V); /* ��ԭ��T��λ�ò��봮V */
       i+=StrLength(V); /* �ڲ���Ĵ�V����������Ҵ�T */
     }
   }while(i);
   return OK;
 }

 void StrPrint(SString T)
 { /* ����ַ���T����� */
   int i;
   for(i=1;i<=T[0];i++)
     printf("%c",T[i]);
   printf("\n");
 }
void main()
 {
   int i,j;
   Status k;
   char s,c[MAXSTRLEN+1];
   SString t,s1,s2;
   printf("�����봮s1: ");
   gets(c);
   k=StrAssign(s1,c);
   if(!k)
   {
     printf("��������MAXSTRLEN(=%d)\n",MAXSTRLEN);
     exit(0);
   }
    printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");
   scanf("%d,%d",&i,&j);
   k=SubString(s2,s1,i,j);
   if(k)
   {
     printf("�Ӵ�s2Ϊ: ");
     StrPrint(s2);
   }
   if(s2[1]=='4' && s2[2]=='1') 
	   printf("�����ڵ�ʡ��Ϊ:����ʡ");
 /*  printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
   StrCopy(s2,s1);
   printf("����s1���ɵĴ�Ϊ: ");
   StrPrint(s2);
   printf("�����봮s2: ");
   gets(c);
   k=StrAssign(s2,c);
   if(!k)
   {
     printf("��������MAXSTRLEN(%d)\n",MAXSTRLEN);
     exit(0);
   }
   i=StrCompare(s1,s2);
   if(i<0)
     s='<';
   else if(i==0)
     s='=';
   else
     s='>';
   printf("��s1%c��s2\n",s);
   k=Concat(t,s1,s2);
   printf("��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
   StrPrint(t);
   if(k==FALSE)
     printf("��t�нض�\n");
   ClearString(s1);
   printf("��Ϊ�մ���,��s1Ϊ: ");
   StrPrint(s1);
   printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
   printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");
   scanf("%d,%d",&i,&j);
   k=SubString(s2,t,i,j);
   if(k)
   {
     printf("�Ӵ�s2Ϊ: ");
     StrPrint(s2);
   }
   printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: ");
   scanf("%d,%d",&i,&j);
   StrDelete(t,i,j);
   printf("ɾ����Ĵ�tΪ: ");
   StrPrint(t);
   i=StrLength(s2)/2;
   StrInsert(s2,i,t);
   printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n",i);
   StrPrint(s2);
   i=Index(s2,t,1);
   printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n",i);
   SubString(t,s2,1,1);
   printf("��tΪ��");
   StrPrint(t);
   Concat(s1,t,t);
   printf("��s1Ϊ��");
   StrPrint(s1);
   Replace(s2,t,s1);
   printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
   StrPrint(s2);*/
 }