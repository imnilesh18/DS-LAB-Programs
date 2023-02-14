#include<stdio.h>
#include<stdlib.h>


struct node{
	struct node *prev;
	int data;
	struct node *next;
};


struct node *start = NULL;


struct node *create_dll(struct node *start){
	struct node *new_node, *ptr;
	int ele;
	printf("Enter the element: \n");
	scanf("%d", &ele);
	while(ele != 0){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = ele;
		if(start == NULL){
			new_node -> prev = NULL;
			new_node -> next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr -> next!= NULL){
				ptr = ptr -> next;
			}	
			ptr -> next = new_node;
			new_node -> prev = ptr;
			new_node -> next = NULL;
		}
	printf("Enter the element : \n");
	scanf("%d", &ele);
	}
	return start;
}


struct node *insert_beginning(struct node *start){
	int ele;	
	struct node *new_node, *ptr;
	printf("Enter the element : \n");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	
	ptr = start;
	new_node-> next = ptr;
	ptr -> prev = new_node;
	new_node -> prev = NULL;
	start = new_node;
	return start;
}



struct node *insert_end(struct node *start){
	struct node *ptr, *new_node;
	int ele;
	printf("Enter the element : \n");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	ptr = start;
	while(ptr -> next!=NULL){
		ptr = ptr -> next;
	}
	ptr -> next = new_node;
	new_node -> prev = ptr;
	new_node -> next = NULL;
	return start;
}


struct node *insert_in_between(struct node *start){
	int ele,val;	
	struct node *new_node, *ptr, *preptr;
	printf("Enter the element : \n");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	ptr = start;
	printf("After which value: ");
	scanf("%d", &val);
	while(preptr -> data!=val){
        	preptr = ptr;
		ptr = ptr->next;
	}
	preptr -> next =new_node;
	new_node -> prev = preptr;
	new_node -> next = ptr;
	ptr -> prev  = new_node;
	
	return start;
}

struct node *delete_beginning(struct node *start){
	struct node *ptr;
	ptr = start;
	start = ptr-> next;
	start -> prev = NULL;
	free(ptr);
	return start;
}

struct node *delete_in_between(struct node *start){
	int val;	
	struct node *ptr, *temp;
	ptr = start;
	printf("After which value: ");
	scanf("%d", &val);
	while(ptr -> data!=val){
		ptr = ptr->next;
	}
	temp = ptr -> next;
	ptr -> next = temp -> next;
	temp -> next -> prev = ptr;
	free(temp);
	return start;
}

struct node *counting(struct node *start){
	int count = 0;
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL){
		ptr = ptr -> next;
		count++;
	}
	printf("The no. of elements in the list are : %d\n", count);
return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL){
		printf("%d\t", ptr -> data);
		ptr = ptr -> next;
	}
	return start;
}

int main(){
	int choice;
	while (choice>0){
		printf("\n1.Create\n2.Insert At Beginning\n3.Insert At End\n4.Insert In Between\n5.Delete At Beginning\n6.Delete In Between\n7.Count\n8.Display\n9.Exit\n");
		printf("Enter your choice : \n");
		scanf("%d", &choice);
		switch(choice){
		case 1: start = create_dll(start);
			break;
		case 2: start = insert_beginning(start);
			break;
		case 3: start = insert_end(start);
			break;
		case 4: start = insert_in_between(start);
			break;
		case 5: start = delete_beginning(start);
			break;
		case 6: start = delete_in_between(start);
			break;
		case 7: start = counting(start);
			break;
		case 8: start = display(start);
			break;
		case 9: exit(0);
			break;
		}
	}
	return 0;
}
