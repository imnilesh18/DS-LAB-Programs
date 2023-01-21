#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};


struct node *TOP = NULL;


void push(){
	int ele;
	struct node *new_node;
	printf("Enter the element : ");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	if(TOP == NULL){
		new_node -> next = NULL;
		TOP = new_node;
	}
	else{
		new_node -> next = TOP;
		TOP = new_node;
	}
}


void pop(){
	struct node *ptr;
	if(TOP == NULL){
		printf("Stack Underflow");
	}
	else{
		ptr = TOP;
		TOP = TOP -> next;
		printf("The item popped is : %d", ptr -> data);
		free(ptr);
	}
}


void display(){
	if(TOP == NULL){
		printf("Stack is Empty");
	}
	else{
		struct node *temp;
		temp = TOP;
		while(temp != NULL){
			printf("%d\t", temp -> data);
			temp = temp -> next;
		}
	}
}


int main(){
	int choice;
	while (choice>0){
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\n");
		printf("Enter your choice : \n");
		scanf("%d", &choice);
		switch(choice){
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: exit(0);
			break;
		}
	}
	return 0;
}
		