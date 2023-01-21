#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 50

int s[MAX];
int top = -1;

void push(int ele)
{
	s[++top]=ele;
}


int pop(){
	
	return s[top--];
}


int main(){
	char exp[50];
	int i,op1,op2,res,len;
	printf("Enter the Suffix Expression to be evaluated : ");
	scanf("%s",exp);
	len = strlen(exp);
	for(i = 0; i< len ; i++){
		if(exp[i]!= '+' && exp[i]!= '-' && exp[i]!= '/' && exp[i]!= '%' && exp[i]!= '^' && exp[i]!='*'){
			exp[i] = exp[i] - '0';
			push(exp[i]);
		}  
		else{
			op1 = pop();
			op2 = pop();
			switch(exp[i]){
				case '+' :res = op2 + op1;
				break;
				case '-' : res = op2 - op1;
				break;
				case '*' :res = op2 * op1;
				break;
				case '/' :res = op2 / op1;
				break;
				case '^' :res = pow(op1,op2);
				break;
				default:printf("\nInvalid Choice\n\n");
        		break;
			}
			push(res);
			}
		}	
	printf("Result = %d \n",res);
}
