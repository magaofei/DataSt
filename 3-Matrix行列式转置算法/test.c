 #include<stdio.h>

 #define MAXSIZE 100 /* 非零元个数的最大值 */
 typedef struct
 {
   int i,j; /* 行下标,列下标 */
   int e; /* 非零元素值 */
 }Triple;

 typedef struct
 {
   Triple data[MAXSIZE+1]; /* 非零元三元组表,data[0]未用 */
   int mu,nu,tu; /* 矩阵的行数、列数和非零元个数 */
 }TSMatrix;

 int CreateSMatrix(TSMatrix *M)
 { /* 创建稀疏矩阵M */
   int i,m,n;
   int e;
   int k;
   printf("请输入矩阵的行数,列数,非零元素数：");
   scanf("%d,%d,%d",&(*M).mu,&(*M).nu,&(*M).tu);
   (*M).data[0].i=0; /* 为以下比较顺序做准备 */
   for(i=1;i<=(*M).tu;i++)
   {
     do
     {
       printf("请按行序顺序输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值：",i,(*M).mu,(*M).nu);
       scanf("%d,%d,%d",&m,&n,&e);
       k=0;
       if(m<1||m>(*M).mu||n<1||n>(*M).nu) /* 行或列超出范围 */
         k=1;
       if(m<(*M).data[i-1].i||m==(*M).data[i-1].i&&n<=(*M).data[i-1].j) /* 行或列的顺序有错 */
         k=1;
     }while(k);
     (*M).data[i].i=m;
     (*M).data[i].j=n;
     (*M).data[i].e=e;
   }
   return 1;
 }
 //打印稀疏矩阵

  void PrintSMatrix(TSMatrix M)
  {
   int i;
   printf("%d行%d列%d个非零元素。\n",M.mu,M.nu,M.tu);
   printf("行  列  元素值\n");
   for(i=1;i<=M.tu;i++)
     printf("%2d%4d%8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
  }

  //
   int TransposeSMatrix(TSMatrix M,TSMatrix *T)
 { /* 求稀疏矩阵M的转置矩阵T。算法5.1 */
   int p,q,col;
   (*T).mu=M.nu;
   (*T).nu=M.mu;
   (*T).tu=M.tu;
   if((*T).tu)
   {
     q=1;
     for(col=1;col<=M.nu;++col)
       for(p=1;p<=M.tu;++p)
         if(M.data[p].j==col)
         {
           (*T).data[q].i=M.data[p].j;
           (*T).data[q].j=M.data[p].i;
           (*T).data[q].e=M.data[p].e;
           ++q;
         }
   }
   return 1;
 }
void main()
 {
   TSMatrix A;
   TSMatrix B;
   printf("创建矩阵A: ");
   CreateSMatrix(&A);//创建稀疏矩阵
  PrintSMatrix(A);//显示创建好的稀疏矩阵
TransposeSMatrix(A,&B);
PrintSMatrix(B);
 }