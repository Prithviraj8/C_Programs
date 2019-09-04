#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Queue{
	int id;
	char name[20];
	char ph_no[10];
	char date[8];


};
struct Queue queue[5];
int front = -1;
int rear = -1;
int MAX = 5;
int isfull(){
	if (rear == (MAX - 1)){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(){
	if(front == rear){
		return 1;
	}
	else{
		return 0;
	}
}
void order(struct Queue q){
	if(isfull() == 0){
		rear++; //rear becomes 0.
		queue[rear] = q;
	}
	else{
		printf("Order list full! \n");
	}
}
void deliver(){
	if(isempty() == 0){
		front++; //front becomes 1.
		struct Queue temp;
		temp = queue[front]; //Pizza order on the front end of the queue is stored in temp.
		printf("%d \n %s \n %s \n %s \n", temp.id, temp.name, temp.ph_no, temp.date);
	}
	else{
		printf("No more orders to deliver! \n");
	}
}
void display(){
	int i;
	printf("\nOrder queue is : ");
	for (i = (front + 1); i<= rear; i++ ){
		printf("%d \n", queue[i].id);
		printf("%s \n", queue[i].name);
		while((getchar()) != '\n');
		printf(" %s \n",queue[i].ph_no);
		printf(" %s \n", queue[i].date);

	}
}
int main(void) {
	struct Queue or;
	int opt = 1;
	while (opt != 0){
		printf("Welcome to Pizza Place. Options are : \n 1 Order \n 2 : Deliver \n 3 : Display \n 0 : Exit ");
		scanf("%d", &opt);
		switch(opt){
			case 1 : printf("Enter id : ");
					 scanf("%d", &or.id);
					 strcpy(or.name, "");
					 fflush(stdin);
					 printf("Enter name : ");
					 scanf(" %s", or.name);
					 printf("Enter phone number : ");
					 scanf("%s", or.ph_no);
					 strcpy(or.date, "");
					 printf("Enter date : ");
					 scanf(" %s", or.date);
					 order(or);
					 break;
			case 2 : deliver();
					 break;
			case 3 : display();
					 break;
			case 0 : printf("Exiting.");
					 break;
			default : printf("Wrong option!");
					  break;
		}
	}
	return 0;
}
