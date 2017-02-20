 /*���ʽ��ֵ�����롢������м�����ֻ����0��9�� */
 typedef char SElemType;
 #include"c1.h"

Status InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* �洢����ʧ�� */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
 }

 Status DestroyStack(SqStack *S)
 { /* ����ջS��S���ٴ��� */
   free((*S).base);
   (*S).base=NULL;
   (*S).top=NULL;
   (*S).stacksize=0;
   return OK;
 }

 Status ClearStack(SqStack *S)
 { /* ��S��Ϊ��ջ */
   (*S).top=(*S).base;
   return OK;
 }

 Status StackEmpty(SqStack S)
 { /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 }

 int StackLength(SqStack S)
 { /* ����S��Ԫ�ظ�������ջ�ĳ��� */
   return S.top-S.base;
 }

 Status GetTop(SqStack S,SElemType *e)
 { /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

 Status Push(SqStack *S,SElemType e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* �洢����ʧ�� */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;/* ָ���������������&ȡ��ַ��*ȡָ���ֵ�� */
   return OK;
 }

 Status Pop(SqStack *S,SElemType *e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if((*S).top==(*S).base)
     return ERROR;
   *e=*--(*S).top;
   return OK;
 }

 Status StackTraverse(SqStack S,Status(*visit)(SElemType))
 { /* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()�� */
   /* һ��visit()ʧ�ܣ������ʧ�� */
   while(S.top>S.base)
     visit(*S.base++);
   printf("\n");
   return OK;
 }
 SElemType Precede(SElemType t1,SElemType t2)
 { /* ���ݽ̿����3.1���ж������ŵ����ȹ�ϵ */
   SElemType f;
   switch(t2)
   {
     case '+':
     case '-':if(t1=='('||t1=='#')
                f='<';
              else
                f='>';
              break;
     case '*':
     case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;

     case '(':if(t1==')')
              {
                printf("ERROR1\n");
                exit(ERROR);
              }
              else
                f='<';
              break;
     case ')':switch(t1)
              {
                case '(':f='=';
                         break;
                case '#':printf("ERROR2\n");
                         exit(ERROR);
                default: f='>';
              }
              break;
     case '#':switch(t1)
              {
                case '#':f='=';
                         break;
                case '(':printf("ERROR3\n");
                         exit(ERROR);
                default: f='>';
              }
   }
   return f;
 }

 Status In(SElemType c)
 { /* �ж�c�Ƿ�Ϊ����� */
   switch(c)
   {
     case'+':
     case'-':
     case'*':
     case'/':
     case'(':
     case')':
     case'#':return TRUE;
     default:return FALSE;
   }
 }

 SElemType Operate(SElemType a,SElemType theta,SElemType b)
 {
   SElemType c;
   a=a-48;
   b=b-48;
   switch(theta)
   {
     case'+':c=a+b+48;
             break;
     case'-':c=a-b+48;
             break;
     case'*':c=a*b+48;
             break;
     case'/':c=a/b+48;
   }
   return c;
 }
/*
SElemType Operate(SElemType a,SElemType theta,SElemType b)
 {
   SElemType c;
   a=a;
   b=b;
   switch(theta)
   {
     case'+':c=a+b;
             break;
     case'-':c=a-b;
             break;
     case'*':c=a*b;
             break;
     case'/':c=a/b;
   }
   return c;
 } */

 SElemType EvaluateExpression() /* �㷨3.4 */
 { /* �������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ */
   SqStack OPTR,OPND;
   SElemType a,b,c,x,theta;
   InitStack(&OPTR);
   Push(&OPTR,'#');
  InitStack(&OPND);
   c=getchar();
   GetTop(OPTR,&x);
   while(c!='#'||x!='#')
   {
     if(In(c)) /* ��7�������֮һ */
       switch(Precede(x,c))
       {
         case'<':Push(&OPTR,c); /* ջ��Ԫ������Ȩ�� */
                 c=getchar();
                 break;
         case'=':Pop(&OPTR,&x); /* �����Ų�������һ�ַ� */
                 c=getchar();
                 break;
         case'>':Pop(&OPTR,&theta); /* ��ջ������������ջ */
		 Pop(&OPND,&b);
                 Pop(&OPND,&a);
                 Push(&OPND,Operate(a,theta,b));
                 break;
       }
     else if(c>='0'&&c<='9') /* c�ǲ����� */
     {
       Push(&OPND,c);
       c=getchar();
     }
     else /* c�ǷǷ��ַ� */
     {
       printf("ERROR4\n");
       exit(ERROR);
     }
     GetTop(OPTR,&x);
   }
   GetTop(OPND,&x);
   return x;
 }

 void main()
 {
   printf("�������������ʽ���м�ֵ�����ս��Ҫ��0��9֮�䣩������#����\n");
   printf("%c\n",EvaluateExpression());
 }

