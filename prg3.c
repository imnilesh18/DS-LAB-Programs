#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int TOP = -1;
int ele;


void push(){
	if(TOP==MAX-1){
		printf("Stack overflow\n");
	}
	else{
		printf("Enter the element:\n");
		scanf("%d", &ele);
		stack[++TOP]=ele;
	}
}


void pop(){
	if(TOP == -1){
		printf("Stack Underflow\n");
	}
	else{
		printf("Deleted Element : %d\n", stack[TOP--]);
	}
}


void display(){
	if(TOP == -1){
		printf("Stack Underflow\n");
	}
	else{
		for(int i = 0; i<=TOP;i++){
			printf("%d\t", stack[i]);
		}
	}
	printf("\n");
}


void seek(){
	if(TOP == -1){
		printf("The Stack is Empty\n");
	}	
	else {
		printf("TOP = %d\n", stack[TOP]);
	}
}


int main(){
int ch;
while(1){
	printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.SEEK\n5.EXIT\n");
	printf("Enter the choice:\n");
	scanf("%d", &ch);
	switch(ch){
		case 1:push();
		break;
		case 2:pop();
		break;
		case 3:display();
		break;
		case 4:seek();
		break;
		case 5:exit(0);
		default:printf("\nInvalid Choice\n\n");
        break;
		}
	}
}
