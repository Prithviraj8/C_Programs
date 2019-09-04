#include<stdio.h>
// #include<conio.h>
#define MAX 20
void printsparse(int[][3]);
void readsparse(int[][3]);
void transpose(int[][3],int[][3]);
void Fast_transpose(int B1[MAX][3],int B2[MAX][3]);
void main()
{
    int b1[MAX][3],b2[MAX][3],m,n,b3[MAX][3],op;
    do
      {
        printf("\n1)Read the First Sparse Matrix");
        printf("\n2)Read the second sparse matrix");
        printf("\n3)Display the first matrix");
        printf("\n4)Display the second matrix");
        printf("\n5)Simple transpose of the first matrix");
        printf("\n6)Fast transpose of the first matrix");
        printf("\n7)Quit");
        printf("\nEnter your choice : ");
        scanf("%d",&op);
        switch(op)
         {
        case 1: readsparse(b1);
                break;
        case 2: readsparse(b2);
                break;
        case 3: printsparse(b1);
                break;
        case 4: printsparse(b2);
                break;
        case 5: transpose(b1,b3);printsparse(b3);
                break;
        case 6: Fast_transpose(b1,b3);printsparse(b3);
                break;
         }
     }while(op!=6);
}
void readsparse(int b[MAX][3])
{
    int i,t,m,n;


}
void printsparse(int b[MAX][3])
{
    int i,n;
    n=b[0][2];
    printf("\nrows = %d\tcolumns = %d",b[0][0],b[0][1]);
    printf("\n");
    for(i=1;i<=n;i++)
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
}
void transpose(int b1[][3],int b2[][3])
{
    int i,j,k,n;
    b2[0][0]=b1[0][1];
    b2[0][1]=b1[0][0];
    b2[0][2]=b1[0][2];
    k=1;
    n=b1[0][2];
    for(i=0;i<b1[0][1];i++)
        for(j=1;j<=n;j++)

        if(i== b1[j][1])
        {
            b2[k][0]=i;
            b2[k][1]=b1[j][0];
            b2[k][2]=b1[j][2];
            k++;
        }
}

void Fast_transpose(int B1[MAX][3],int B2[MAX][3])
{
    int m,n,t,i,col_num,temp;
    int total[MAX],index[MAX];
    m=B1[0][0];n=B1[0][1];t=B1[0][2];
    B2[0][0]=n;B2[0][1]=m;B2[0][2]=t;
    for(i=0;i<n;i++)
        total[i]=0;
    for(i=1;i<=t;i++)
    {
        col_num=B1[i][1];
        total[col_num]++;
    }
    index[0]=1;
    for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];

    for(i=1;i<=t;i++)
    {
        col_num=B1[i][1];
        temp=index[col_num];
        index[col_num]++;
        B2[temp][0]=B1[i][1];
        B2[temp][1]=B1[i][0];
        B2[temp][2]=B1[i][2];
    }
}
