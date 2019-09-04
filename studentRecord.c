#include<stdio.h>

struct student{
             int rollno;
             char name[15];
             float per;
             int div;
};

typedef struct student stud;

void accept(stud s[50],int n)
{
 int i;
     for(i=0; i<n; i++)
      {
        printf("**********************************************************\n");
        printf("\nenter your rollno\n");
        scanf("%d",&s[i].rollno);

        printf("\nenter your name\n");
        scanf("%s",s[i].name);

        printf("\nenter your percentage\n");
        scanf("%f", &s[i].per);

        printf("\nEnter your div\n");
        scanf("%d", &s[i].div);
       
       }
}

void display(stud s[50],int n)
{
int i;
             for(i=0; i<n; i++)
              {
                
                printf("rollno=%d\t",s[i].rollno);
                printf("name=%s\t",s[i].name);
                printf("percentage=%f\t",s[i].per);
                printf("div=%d\n", s[i].div);
                
              }
}

void linear_search(stud s[50],int n)
{
    int flag=0;
    int key,i;

printf("enter rollno you want to search\n");
scanf("%d",&key);

for(i=0;i<n;i++)
{
    if(s[i].rollno==key)
    {
        
        printf("rollno=%d\t",s[i].rollno);
        printf("name=%s\t",s[i].name);
        printf("percentage=%f\t",s[i].per);
        printf("div=%d\n", s[i].div);
       
        flag=0;
        break;
    }
    else
    {
        flag=1;
    }
}
if(flag==1)
{
    printf("record not available");
}
}




void binary_search(stud s[50],int n)
{
 int low,high,mid,key;

printf("enter rollno you want to search\n");
scanf("%d",&key);

low=0;
high=n-1;

while(low<=high)
{
 mid=(low+high)/2;

 if(key==s[mid].rollno)
  {
       printf("record found\n");
       
        printf("rollno=%d\t",s[mid].rollno);
        printf("name=%s\t",s[mid].name);
        printf("percentage=%f\t",s[mid].per);
        printf("div=%d\n", s[mid].div);
      
        break;
  }

 else if(key<s[mid].rollno)
 {
  high=mid-1;
 }

 else
 {
  low=mid+1;
 }

 if(low>high)
 {
 printf("Record NOT Available");
 }
}
}



void bubblesort(stud s[50],int n)
{
 int i,j;
  for (i=0; i<n-1;i++)
   {
     for (j=0;j<n-i-1;j++)
      {
        if(s[j].rollno>s[j+1].rollno)
          {
            stud swap=s[j];
            s[j]=s[j+1];
            s[j+1]=swap;
          }

      }
   }


}


void selectionsort(stud s[50],int n)
{
 int i,j;
 for(i=0;i<n-1;i++)
   {

      for(j=i+1;j<n;j++)
        {
          if(s[i].rollno>s[j].rollno)
            {
              stud temp=s[i];
              s[i]=s[j];
              s[j]=temp;
             }
        }
   }

}

void insertionsort(stud s[50],int n)
{
int i,j;
 for(i=0;i<n;i++)
   {
      stud temp=s[i];
      j=i-1;

while(s[j].rollno>temp.rollno && j>=0)
  {
   s[j+1]=s[j];
   j--;
  }
  s[j+1]=temp;
 }
}

void delete(stud s[50], int n)
{
int i,j,tempRoll,tempDiv;
char tempName[15];
float tempPercentage;
	printf("\nWhich record would you like to delete?\n");
	scanf("%d",&j);	
if(j<=n){
       
             for(i=0;i < j-1; i++)
              {
                
                printf("rollno=%d\t",s[i].rollno);
                printf("name=%s\t",s[i].name);
                printf("percentage=%f\t",s[i].per);
                printf("div=%d\n", s[i].div);
                
              }
	}else{
		printf("Enter a record less than the total number of records");
	}	
	//rintf("%d",s)
}

int main()
{
 stud s[50];
 int i,n,e;

    printf("Enter the total no. of students\n");
    scanf("%d",&n);

          accept(s,n);

    printf("*****************Student Info******************\n");
        display(s,n);

printf("\nOPERATIONS:");
printf("\n1.linear search\n");
printf("2.binary search\n");
printf("3.bubble sort\n");
printf("4.insertion sort\n");
printf("5.selection sort\n");
printf("6.Delete \n");
printf("enter your choice\n");
scanf("%d",&e);
printf("\n");

   switch(e)
   {
       case 1:linear_search(s,n);
              break;


       case 2:bubblesort(s,n);
              binary_search(s,n);
              break;

      case 3:bubblesort(s,n);
             display(s,n);

             break;

      case 4:insertionsort(s,n);
             display(s,n);
             break;

      case 5:selectionsort(s,n);
             display(s,n);
             break;
	
      case 6:delete(s,n);
//	     display(s,n);
             break;
		
      default :
     printf("\nEnter valid choice\n");
     break;
}
return 0;
}


