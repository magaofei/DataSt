 #include<stdio.h>

 #define MAXSIZE 100 /* ??????????????? */
 typedef struct
 {
   int i,j; /* ???��?,???��? */
   int e; /* ???????? */
 }Triple;

 typedef struct
 {
   Triple data[MAXSIZE+1]; /* ???????????,data[0]��?? */
   int mu,nu,tu; /* ????????????????????????? */
 }TSMatrix;

 int CreateSMatrix(TSMatrix *M)
 { /* ??????????M */
   int i,m,n;
   int e;
   int k;
   printf("??????????????,????,???????????");
   scanf("%d,%d,%d",&(*M).mu,&(*M).nu,&(*M).tu);
   (*M).data[0].i=0; /* ????��?????????? */
   for(i=1;i<=(*M).tu;i++)
   {
     do
     {
       printf("??????????????%d????????????????(1??%d),??(1??%d),??????",i,(*M).mu,(*M).nu);
       scanf("%d,%d,%d",&m,&n,&e);
       k=0;
       if(m<1||m>(*M).mu||n<1||n>(*M).nu) /* ?��??��?????�� */
         k=1;
       if(m<(*M).data[i-1].i||m==(*M).data[i-1].i&&n<=(*M).data[i-1].j) /* ?��??��?????��? */
         k=1;
     }while(k);
     (*M).data[i].i=m;
     (*M).data[i].j=n;
     (*M).data[i].e=e;
   }
   return 1;
 }
 //?????????

  void PrintSMatrix(TSMatrix M)
  {
   int i;
   printf("%d??%d??%d??????????\n",M.mu,M.nu,M.tu);
   printf("??  ??  ????\n");
   for(i=1;i<=M.tu;i++)
     printf("%2d%4d%8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
  }

  //
   int TransposeSMatrix(TSMatrix M,TSMatrix *T)
 { /* ????????M????????T????5.1 */
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
   printf("????????A: ");
   CreateSMatrix(&A);//??????????
  PrintSMatrix(A);//????????????????
TransposeSMatrix(A,&B);
PrintSMatrix(B);
 }