#include <stdio.h>

struct student{
    int roll;
    char name[15],div;

};

typedef struct student stud;

void accept(stud s[50],int n){
    // stud s[n];
    int i;
    for(i = 0;i < n; i++){
        printf("\nEnter your name:\n ");
        scanf("%s",&s[i].name);
        printf("\nEnter roll number \n");
        scanf("%d",&s[i].roll);
        printf("\nEnter your division\n");
        scanf("%s",&s[i].div);

    }
}

void display(stud s[50],int n)
{
int i;
             for(i=0; i<n; i++)
              {

                printf("rollno=%d\t",s[i].roll);
                printf("name=%s\t",s[i].name);
                printf("div=%c\n", s[i].div);

              }
}

void linearSearch(stud s[50], int n){
    int i,key;
    // stud s[50];
    printf("\nEnter the roll number you want \n");
    scanf("%d",&key);
    for(i = 0;i < n;i++){
        if(s[i].roll == key){
            printf("\nThe student database is found and the details are: \n");
            printf("\nName is : %s\n",s[i].name);
        }else{
            printf("Data not found");
        }
    }
}

void binarySearch(stud s[50], int n){
    int i,l = 0,h = n-1,mid,key;
    mid = (l + h)/2;
    // stud s[50];

    printf("\nMid is \n%d",mid);
    printf("\nEnter the roll number you want to find\n");
    scanf("%d",&key);
    printf("\nThe roll number being found is \n%d",key);

    if(key == s[mid].roll){
      printf("\nStudent data is found as follows:  %s\n",s[mid].name);
    }else if(key < mid){
      for (i = 0 ;i < mid-1;i++) {

        if(key == s[i].roll){
          printf("\nStudent data is found as follows:  %s\n",s[i].name,"%d\n",s[i].roll,"%c\n",s[i].div,"\n");

        }else{
            for(i = mid + 1;i < n;i++){
              if(key == s[i].roll){
                printf("\nStudent data is found as follows:  %s\n",s[i].name,"%d\n",s[i].roll,"%c\n",s[i].div,"\n");

              }else{
                printf("\nStudent data not found.\n");
              }
            }
        }

      }

    }

}

void insertionSort(stud s[50],int n)
{
int i,j;
 for(i=1;i<n;i++)
   {
      stud temp=s[i];
      j=i-1;

while(s[j].roll > temp.roll && j>=0)
  {
   s[j+1]=s[j];
   j--;
  }
  s[j+1]=temp;
 }
}

int main()
{
    stud s[50];
    int n;
    printf("\nEnter the number of student database to be created\n");
    scanf("%d",&n);
    accept(s,n);
    linearSearch(s,n);
    binarySearch(s,n);
    insertionSort(s,n);
    display(s,n);

    return 0;
}
