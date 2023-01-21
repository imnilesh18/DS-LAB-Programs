#include<stdio.h>
#include<stdlib.h>
int ch,n,a[50],i;


void create(){
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(int i = 0; i<n;i++){
		scanf("%d", &a[i]);
	}
}


void display(){
	printf("The elements of array are: \n");
	for(int i = 0;i<n;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}


int main(){
while(1){
	printf("MENU\n");
	printf("1.CREATE\n");
	printf("2.DISPLAY\n");
    printf("3.EXIT\n");
	printf("Enter the choice:\n");
	scanf("%d", &ch);
	switch(ch){
		case 1:create();
		break;
		case 2:display();
		break;
        case 3:exit(0);
        default:printf("\nInvalid Choice\n\n");
        break;
		}
	}
}
