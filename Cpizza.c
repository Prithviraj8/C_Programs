#include<stdio.h>
#include<string.h>
struct Queue{
  int id;
	char name[20];
	int ph_no;
	char date[8];

};

 struct Queue queue[5];
int front = -1,rear = -1,max = 5;

int isFull(){
  if(rear == (max - 1) ){
    printf("The queue is full \n");
    return 1;
  }else{
    return 0;
  }
}

int isEmpty(){
  if(front == -1 && rear == -1){
    printf("Queue is is Empty\n");
    return 1;
  }else{
    return 0;
  }
}

void order(struct Queue q) {

if (isFull == 1) {
  printf("No orders can be taken anymore\n");
}else{
  rear++;
  queue[rear] = q;

  }
}

void delivery(){
  if (isEmpty == 0) {
    //Not empty.
    front++;
    struct Queue temp;
    temp = queue[front];
    printf("%d \n %s \n %s \n %s \n", temp.id, temp.name, temp.ph_no, temp.date);
  }else{
    printf("No orders taken yet\n");
  }
}

void display() {
    int i;
    // struct Queue q;
    printf("\nOrder Queue is \n");
    for(i = (front + 1);i <= rear;i++){
      printf("\nName %s\n",queue[i].name );
      printf("\nID is %d\n",queue[i].id );
      printf("\nPhone no is %d\n",queue[i].ph_no);
      printf("\nDate is %s\n",queue[i].date );
    }

}

int main(){

struct Queue q;
 int cnt = 0;
  printf("Enter your pizza order \n" );
  printf("Enter Phone number\n");
  scanf("%d",&q.ph_no);
  printf("Enter Your Name : \n");
  scanf("%s", &q.name );
  printf("Enter your order ID :\n");
  scanf("%d",&q.id );
  printf("Enter the date :\n");
  scanf("%s", &q.date);
  // printf("Do you want it deliverd ? \n");
  // scanf("%c\n",&ans);
  order(q);
  delivery();
  display();
  return 0;
}
