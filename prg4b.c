#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void tower( int n , int source, int temp, int dest){
    if (n == 0)
        return;


    tower(n - 1 , source, dest, temp);
    printf("\nMove disc %d from %c to %c \n", n, source, dest);
    tower(n - 1, temp, source, dest);
}


int main(){
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    tower(n , 'A', 'B', 'C');
    int res = (pow(2,n) -1);
    printf("\nTotal numbers of moves are %d\n" , res);
    return 0;
}
