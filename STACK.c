#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[20];
char stacktoinfi[20][20];
int top = -1;
int top_i = -1;

int isempty(){
	if (top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(){
	if (top == (19)){
		return 1;
	}
	else
		return 0;

}
void push(char elem){
	if (isfull() == 0){
		top++;
		stack[top] = elem;
		printf("\n");
	}
	else{
		printf("Stack full!");
		printf("\n");
	}
}
void push_i(char elem[20]){
	top_i++;
	strcpy(stacktoinfi[top_i], elem);
}
char pop(){
	char temp;
	if (isempty() == 0){
		temp = stack[top];
		top--;
		return temp;
	}
	else{
		return '\0';
	}
}
char* pop_i(){
	char *temp;
	strcpy(temp,stacktoinfi[top_i]);
	top_i--;
	return temp;
}
void display(){
	int i;
	for(i = top; i >= 0; i--){
		printf("%c", stack[i]);
		printf("\n");
	}
}
void display_i(){
	int i;
	for(i = top_i; i >= 0; i--){
		printf("%c", stacktoinfi[i]);
		printf("\n");
	}
}
int ISP(char ch){
	if (ch == '('){
		return 0;
	}
	if (ch == '^'){
		return 3;
	}
	if ((ch == '*') || (ch == '/')){
		return 2;
	}
	if ((ch == '+') || (ch == '-')){
		return 1;
	}
	else{
		return -1;
	}

}
int ICP(char ch){
	if (ch == '('){
		return 5;
	}
	if (ch == '^'){
		return 4;
	}
	if ((ch == '*') || (ch == '/')){
		return 2;
	}
	if ((ch == '+') || (ch == '-')){
		return 1;
	}
	else{
		return -1;
	}
}

int ISP_pre(char ch){
	if (ch == '('){
		return 0;
	}
	if (ch == '^'){
		return 4;
	}
	if ((ch == '*') || (ch == '/')){
		return 2;
	}
	if ((ch == '+') || (ch == '-')){
		return 1;
	}
	else{
		return -1;
	}

}
int ICP_pre(char ch){
	if (ch == '('){
		return 5;
	}
	if (ch == '^'){
		return 3;
	}
	if ((ch == '*') || (ch == '/')){
		return 2;
	}
	if ((ch == '+') || (ch == '-')){
		return 1;
	}
	else{
		return -1;
	}
}

void display_array(char arr[20]){
	for(int i = 0; arr[i] != '\0'; i++){
		printf("%c", arr[i]);
		printf(" ");
	}
}
/*
void display_pre(char arr[20], int k){
	for(int i = k; i >= 0; i--){
		printf("%c", arr[i]);
		printf(" ");
	}
}*/
void streverse(char str[20]){
	char str1[20];
	int a = strlen(str);
	int i = 0;
	int b;
	for (b = a - 1; b >= 0;b--,i++){
		str1[i] = str[b];
	}
	for(i = 0; i < strlen(str1); i++){
		if(str1[i] == '('){
			str[i] = ')';
		}
		if (str[i] == ')'){
			str[i] = '(';
		}

	}
	//str1[a] = '\0';
}

void infix_to_prefix(char exp[20]){
	char rever[20];
	int k = 0;
	char prefix[20];
	char ch;
	int i = 0;
	int a = strlen(exp);
	int b;
	for (b = a - 1; b >= 0;b--,i++){
		rever[i] = exp[b];
	}
	rever[i]='\0';
	for(i = 0; i < strlen(rever); i++){
		if(rever[i] == '('){
			rever[i] = ')';
		}
		if (rever[i] == ')'){
			rever[i] = '(';
		}
	}
	rever[i] = '\0';

	for(i = 0; rever[i] != '\0'; i++){
		if (rever[i] == '('){
			push(rever[i]);
		}
		else if(rever[i] == ')'){
			while((ch = pop()) != '('){
				prefix[k] = ch;
				k++;
			}
			//pop();
		}
		else if(rever[i] == '+' || rever[i] == '-' || rever[i] == '*' || rever[i] == '/' || rever[i] == '^'){
			while((top>=0) && ISP_pre(stack[top]) > ICP_pre(rever[i])){
				prefix[k] = pop();
				k++;
			}
			push(rever[i]);
		}
		else{
			prefix[k] = rever[i];
			k++;
		}
	}
	while(top >= 0){
		prefix[k] = pop();
		k++;
	}
	prefix[k] = '\0';
	char final[20];
	int j=0;
	for(i = a-1; i >= 0; i--){
		if((prefix[i] != '(') || (prefix[i] != ')')){
			final[j] = prefix[i];
			j++;
		}
	}
	final[a] = '\0';
	display();
}

void infix_to_postfix(char exp[20]){
	int k = 0;
	char postfix[20];
	char ch;
	int i;
	for(i = 0; exp[i] != '\0'; i++){
		if (exp[i] == '('){
			push(exp[i]);
		}
		else if(exp[i] == ')'){
			while((ch = pop()) != '('){
				postfix[k] = ch;
				k++;
			}
			//pop();
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
			while(top>=0 && ISP(stack[top]) >= ICP(exp[i])){
				postfix[k] = pop();
				k++;
			}
			push(exp[i]);
		}
		else{
			postfix[k] = exp[i];
			k++;
		}
	}
	while(top >= 0){
		postfix[k] = pop();
		k++;
	}
	postfix[k] = '\0';
	display_array(postfix);
}
void postfix_to_infix(char exp[20]){
	char str[20];
	char st[20];
	char op1[20];
	char op2[20];
	char st1[20];
	for(int i = 0; exp[i] != '\0'; i++){
		if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
			strcpy(str, "");
			strcpy(st, "");
			strcpy(op1,pop_i());
			strcpy(op2 ,pop_i());
			str[0] = '(';
			str[1] = '\0';
			strcat(str, op2);
			st[0] = exp[i];
			st[1] = '\0';
			strcat(str,st);
			strcat(str,op1);
			strcpy(st, "");
			st[0] = ')';
			st[1] = '\0';
			strcat(str,st);
			push_i(str);
		}
		else{
			strcpy(st1, "");
			st1[0] = exp[i];
			st1[1] = '\0';
			push_i(st1);
		}
	}
	strcpy(st, "");
	strcpy(st,pop_i());
	printf(" %s", st);

}

void prefix_to_infix(char exp[20]){
	char str[20];
	char st[20];
	char op1[20];
	char op2[20];
	char st1[20];
	int l;
	l = strlen(exp);
	for(int i = (l-1); exp[i] != '\0'; i--){
		if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
			strcpy(str, "");
			strcpy(st, "");
			strcpy(op1,pop_i());
			strcpy(op2 ,pop_i());
			str[0] = '(';
			str[1] = '\0';
			strcat(str, op1);
			st[0] = exp[i];
			st[1] = '\0';
			strcat(str,st);
			strcat(str,op2);
			strcpy(st, "");
			st[0] = ')';
			st[1] = '\0';
			strcat(str,st);
			push_i(str);
		}
		else{
			strcpy(st1, "");
			st1[0] = exp[i];
			st1[1] = '\0';
			push_i(st1);
		}
	}
	strcpy(st, "");
	strcpy(st,pop_i());
	printf(" %s", st);

}

int main(void) {
	char exp[20];
	int opt;
	opt = 1;
	while (opt != 0){
		printf("Options are : \n 1 : In to pre \n 2 : In to post \n 3 : Post to in \n 4 : Pre to In \n 5 : Is Full \n 0 : Exit ");
		scanf("%d", &opt);
		switch(opt){
		case 1 :printf("Enter infix");
				scanf(" %s", exp );
				infix_to_prefix(exp);
				break;
		case 2 :printf("Enter infix");
				scanf(" %s", exp );
				infix_to_postfix(exp);
				break;

		case 3 :printf("Enter postfix");
				scanf(" %s", exp );
				postfix_to_infix(exp);
				break;

		case 4 :printf("Enter prefix");
				scanf(" %s", exp );
				prefix_to_infix(exp);
				break;
		case 0 : printf("Bye");
				 break;
		default :printf("Wrong option");
				 break;
		}
	}
	return 0;
}
