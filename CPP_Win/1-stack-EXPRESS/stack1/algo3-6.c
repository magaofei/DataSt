 /*表达式求值（输入、输出和中间结果均只能是0～9） */
 typedef char SElemType;
 #include"c1.h"

Status InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
 }

 Status DestroyStack(SqStack *S)
 { /* 销毁栈S，S不再存在 */
   free((*S).base);
   (*S).base=NULL;
   (*S).top=NULL;
   (*S).stacksize=0;
   return OK;
 }

 Status ClearStack(SqStack *S)
 { /* 把S置为空栈 */
   (*S).top=(*S).base;
   return OK;
 }

 Status StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 }

 int StackLength(SqStack S)
 { /* 返回S的元素个数，即栈的长度 */
   return S.top-S.base;
 }

 Status GetTop(SqStack S,SElemType *e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

 Status Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;/* 指针的两个操作，（&取地址，*取指向的值） */
   return OK;
 }

 Status Pop(SqStack *S,SElemType *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
   if((*S).top==(*S).base)
     return ERROR;
   *e=*--(*S).top;
   return OK;
 }

 Status StackTraverse(SqStack S,Status(*visit)(SElemType))
 { /* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
   /* 一旦visit()失败，则操作失败 */
   while(S.top>S.base)
     visit(*S.base++);
   printf("\n");
   return OK;
 }
 SElemType Precede(SElemType t1,SElemType t2)
 { /* 根据教科书表3.1，判断两符号的优先关系 */
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
 { /* 判断c是否为运算符 */
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

 SElemType EvaluateExpression() /* 算法3.4 */
 { /* 算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈 */
   SqStack OPTR,OPND;
   SElemType a,b,c,x,theta;
   InitStack(&OPTR);
   Push(&OPTR,'#');
  InitStack(&OPND);
   c=getchar();
   GetTop(OPTR,&x);
   while(c!='#'||x!='#')
   {
     if(In(c)) /* 是7种运算符之一 */
       switch(Precede(x,c))
       {
         case'<':Push(&OPTR,c); /* 栈顶元素优先权低 */
                 c=getchar();
                 break;
         case'=':Pop(&OPTR,&x); /* 脱括号并接收下一字符 */
                 c=getchar();
                 break;
         case'>':Pop(&OPTR,&theta); /* 退栈并将运算结果入栈 */
		 Pop(&OPND,&b);
                 Pop(&OPND,&a);
                 Push(&OPND,Operate(a,theta,b));
                 break;
       }
     else if(c>='0'&&c<='9') /* c是操作数 */
     {
       Push(&OPND,c);
       c=getchar();
     }
     else /* c是非法字符 */
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
   printf("请输入算术表达式（中间值及最终结果要在0～9之间），并以#结束\n");
   printf("%c\n",EvaluateExpression());
 }

