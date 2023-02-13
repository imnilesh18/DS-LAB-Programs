#include<stdio.h>
#define MAX 10
int adj[][MAX] = {{0, 1, 0, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};


void bfs(){
    int visited[MAX] = {0};
    int start = 0;
    int r, f, i;
    r = f = -1;
    int q[MAX];
    q[++r] = start;
    visited[start] = 1;
    while(r!=f){
        start = q[++f];
        printf("%d -> ", start);
        for(i = 0; i< MAX; i++){
            if(adj[start][i] == 1 && visited[i] == 0){
                q[++r] =  i;
                visited[i] = 1;
            }
        }
    }
}


void dfs(int start){
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1, i;
    printf("%d -> ", start);
    visited[start] = 1;
    stack[++top] = start;
    while(top!=-1){
        start = stack[top];
        for(i = 0; i < MAX; i++){
             if(adj[start][i] && visited[i] == 0){
                stack[++top] = i;
                printf("%d -> ", i);
                visited[i] = 1;
                break;            
        }
    }
    if(i == MAX){
        top--;
    }
    }
}


int main(){
    printf("\nBFS :: \n");
    bfs(0);
    printf("\nDFS :: \n");
    dfs(0);
    return 0;
}
