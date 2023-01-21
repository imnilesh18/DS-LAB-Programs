#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int ch,n,a[MAX],i;


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
	for(int i = 0; i<n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}


void insert(){
	int n1,POS;
	printf("Enter the element to be inserted : \n");
	scanf("%d",&n1);
	printf("Enter the position: \n");
	scanf("%d",&POS);
	int i;
	for(int i = n-1; i>=POS+1; i--)
	{
		a[i+1] = a[i];
	}
	a[POS] = n1;
	n++;
}


void delete(){
	int POS;
	printf("Enter the Position:");
	scanf("%d", &POS);
	for(int i = POS+1; i < n-1; i++)
	{
		a[i]=a[i+1];
		
	}
	n--;
}


int main(){
while(1){
	printf("MENU\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.EXIT\n");
	printf("Enter the choice:\n");
	scanf("%d", &ch);
	switch(ch){
		case 1:create();
		break;
		case 2:display();
		break;
		case 3:insert();
		break;
		case 4:delete();
		break;
		case 5:exit(0);
		default:printf("\nInvalid Choice\n\n");
        break;
		}
	}
}

