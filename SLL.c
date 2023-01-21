#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};


struct node *start = NULL;


struct node *create_ll(struct node *start){
	struct node *new_node, *ptr;
	int ele;
	printf("Enter the element: \n");
	scanf("%d", &ele);
	while(ele != 0){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = ele;
		if(start == NULL){
			new_node -> next = NULL;
			start = new_node;
		}
		else{
			ptr = start;
			while(ptr -> next!= NULL)
				ptr = ptr -> next;
				ptr -> next = new_node;
				new_node -> next = NULL;
		}
	printf("Enter the element : \n");
	scanf("%d", &ele);
	}
	return start;
}


struct node *display(struct node *start){
	int count=0;
	struct node *ptr;
	ptr = start;
	while(ptr!=NULL){
		printf("%d\t", ptr -> data);
		ptr = ptr -> next;
		count++;
	}
	printf("\n\nThe no. of elements in the list are : %d", count);
return start;
}


struct node *search(struct node *start){
	int val;
	struct node *ptr, *pos;
	ptr = start;
	printf("Enter the element to search : \n");
	scanf("%d", &val);
	while(ptr!=NULL){
		if(val == ptr -> data){
			printf("%d Element found \n" , val);
		pos = ptr;
		printf("The Element found in Position %p\n", pos);
		break;
		}
		else{
			ptr = ptr ->next;
		}
	}
	if(ptr == NULL){
		printf("Element %d not found \n", val);
	}
	return start;
}


struct node *insert_beginning(struct node *start){
	int ele;	
	struct node *new_node;
	printf("Enter the element : \n");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	
	new_node ->data = ele;
	new_node-> next = start;
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
	new_node -> next = NULL;
	return start;
}


struct node *insert_before(struct node *start){
	int ele,val;	
	struct node *new_node, *ptr, *preptr;
	printf("Enter the element : \n");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	ptr = start;
	printf("Before which value: ");
	scanf("%d", &val);
	while(ptr -> data != val){
		preptr = ptr;
		ptr = ptr-> next;
	}
	preptr -> next = new_node;
	new_node ->next = ptr;
	return start;
}


struct node *insert_after(struct node *start){
	int ele,val;	
	struct node *new_node, *ptr, *preptr;
	printf("Enter the element : \n");
	scanf("%d", &ele);
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = ele;
	ptr = start;
	printf("After which value: ");
	scanf("%d", &val);
	while(preptr -> data != val){
		preptr = ptr;
		ptr = ptr-> next;
	}
	preptr -> next = new_node;
	new_node -> next = ptr;
	return start;
}


struct node *delete_beginning(struct node *start){
	struct node *ptr;
	ptr = start;
	start = ptr-> next;
	free(ptr);
	return start;
}


struct node *delete_end(struct node *start){
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != NULL){
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = NULL;
	free(ptr);
	return start;
}

struct node *delete_node(struct node *start){
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value of the node which has to be deleted :");
	scanf("%d", &val);
	ptr = start;
	if(ptr -> data == val){
	start = delete_beginning(start);
	return start;
	}
	else
	{
		while(ptr -> data != val)
		{
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}


struct node *delete_after(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	preptr = ptr;
	while(preptr -> data != val)
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next=ptr -> next;
	free(ptr);
	return start;
}


struct node *delete_list(struct node *start)
{
struct node *ptr;
	if(start!=NULL){
		ptr=start;
		while(ptr != NULL)
		{
			printf("\n %d is to be deleted next", ptr -> data);
			start = delete_beginning(ptr);
			ptr = start;
		}
	}
	return start;
}


struct node *sort_list(struct node *start)
{
	struct node *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while(ptr1 -> next != NULL)
	{
		ptr2 = ptr1 -> next;
		while(ptr2 != NULL)
		{
			if(ptr1 -> data > ptr2 -> data)
			{
				temp = ptr1 -> data;
				ptr1 -> data = ptr2 -> data;
				ptr2 -> data = temp;
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return start;
}


int main(){
	int choice;
	while (choice>0){
		printf("\n1.Create\n2.Display\n3.Search\n4.Insert At Beginning\n5.Insert At End\n6.Insert Before\n7.Insert After\n");
		printf("8.Delete At Beginning\n9.Delete At End\n10.Delete Node\n11.Delete After\n12.Delete List\n13.Sort List\n14.Exit\n");

		printf("Enter your choice : \n");
		scanf("%d", &choice);
		switch(choice){
		case 1: start = create_ll(start);
			break;
		case 2: start = display(start);
			break;
		case 3: start = search(start);
			break;
		case 4: start = insert_beginning(start);
			break;
		case 5: start = insert_end(start);
			break;
		case 6: start = insert_before(start);
			break;
		case 7: start = insert_after(start);
			break;
		case 8: start = delete_beginning(start);
			break;
		case 9: start = delete_end(start);
			break;
		case 10: start = delete_node(start);
			break;
		case 11: start = delete_after(start);
			break;
		case 12: start = delete_list(start);
			break;
		case 13: start = sort_list(start);
			break;
		case 14: exit(0);
			break;
		default: printf("\nInvalid Choice\n\n");
        break;
		}
	}
	return 0;
}
