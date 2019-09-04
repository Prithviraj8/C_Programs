#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;

};

struct node* root;//Default value will be assigned .
int len;

void creatNode(){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter Node data : \n");
  scanf("%d",&temp->data );
  temp->next = NULL;

if (root == NULL)  { //List is Empty
  root = temp;
}else{
  struct node* p;
  p = root;// P is the new node which should travel from the the root node.

  while (p->next != NULL) {
    p = p->next; //We assign p to itself. As p is the root node and is pointing to the first node with data we just assign that node to p . So the counter node moves to the first node with data i.e. p node. When p->next i.e the 1st node with data is a NULL , we add the new node accepted from the user i.e. temp node to the current p node (at this point p points to the 1st node which has a data but has no other node after that i.e memory address is NULL).
  }
    p->next = temp;
  }
}

int length(){
  int count = 0;
  struct node* temp;
  temp = root;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void display(){
  struct node* temp;
  temp = root;
  if(temp == NULL){
    printf("No nodes to display\n");
  }else{
    while(temp != NULL){
      printf("%d-->",temp->data);
      temp = temp->next;
    }
    printf("\n\n");
  }

}

void addInBet(){
  struct node* temp,*p;
  temp = root;
  int pos,i=1,LEN;

    printf("\nEnter the postion of the node after which you want to add a new node :");
    scanf("%d",&pos );


    LEN = length();
    printf("Currently list has a length of  %d",len);

    if(pos > LEN){
      printf("Invalid location\n");
      printf("Currently list has a length of  %d ",LEN);

    }else{
        p = root;
        while (i < pos) {
          p = p->next;
          i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter Node data : \n");
        scanf("%d",&temp->data );
        temp->next = p->next;
        p->next = temp;

    }

}

void deleteFromBetween(){
  struct node* temp,*p;
  int pos,i=1,LEN = length();

    printf("\nEnter the postion of the node after which you want to add a new node :");
    scanf("%d",&pos );
    if(pos > LEN){
      printf("Invalid location\n");
      printf("Currently list has a length of  %d ",LEN);

    }else if(pos == 1){

      temp = root;
      root = temp->next;
      temp->next = NULL;
      free(temp);

    }else{
      struct node* p = root, *q;
      int i = 1;
      while (i < pos -1){
        p = p->next;
        i++;

      }
      q = p->next;//q Points to the node that we want to delete.
      p->next = q->next;
      q->next = NULL;
      free(q);
    }
}


int main(){
    int ch;
  while (1) {
    printf("1.Append\n");
    printf("2.display\n");
    printf("3.length\n");
    printf("4.Add in Between : \n");
    printf("5.Delete from Between : \n");

    printf("7.Exit \n");
    scanf("%d",&ch);
    switch (ch) {
      case 1:   creatNode();
                break;
      case 2:   display();
                break;
      case 3:   len = length();
                printf("The length is : %d\n\n",len);
                break;
      case 4:   addInBet();
                break;

      case 5:   deleteFromBetween();
                break;

      case 7: exit(1);
                break;
      default:
                  printf("Wrong choice\n");
                  break;
    }
  }

  return 0;

}
