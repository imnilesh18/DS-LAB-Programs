#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};


struct node *front = NULL;
struct node *rear = NULL;


void enqueue(){
	struct node *new_node;
	int ele;
	printf("Enter the element : ");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	if(front == NULL){
		front = new_node;
		rear = new_node;
		front -> next = NULL;
		rear  -> next = NULL;
	}
	else{
		rear -> next = new_node;
		rear = new_node;
		rear -> next = NULL;
	}
}


void dequeue(){
	struct node *temp;
	if(front == NULL){
		printf("Queue Underflow");
	}
	else{
		temp = front;
		front = front -> next;
		printf("The element deleted is : %d", temp -> data); 
		free(temp);
	}
}


void display(){
	struct node *temp;
	temp = front;
	if(front==NULL){
		printf("Queue is Empty");
	}
	while(temp!= NULL){
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
}


int main(){
	int choice;
	while (choice>0){
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.Exit\n");
		printf("Enter your choice : \n");
		scanf("%d", &choice);
		switch(choice){
		case 1: enqueue();
			break;
		case 2: dequeue();
			break;
		case 3: display();
			break;
		case 4: exit(0);
			break;
		default:printf("\nInvalid Choice\n\n");
        break;
		}
	}
	return 0;
}
		
	
