#include <stdio.h>
#define CAPACITY 3
int stack[CAPACITY];
int top= -1;
void push(int x){
    if(top < CAPACITY-1){
        top= top+1;
    stack[top]=x;
    printf(" the %d th item is:%d\n",top,x);}
        else{
        printf(" stack is full\n");
}



}
void printStk(){
    printf("Stack:");
    int i;
    for(i=0;i< CAPACITY;i++){
        printf("%d ",stack[i]);
    }
printf("\n");
}


int pop(){
    if(top>=0){
        int value = stack[top];
        top= top-1;
        return value;
    }
    printf(" exception! empty stack\n");
return -1;
}
int peek(){
    if(top>=0){
        return stack[top];
    }
    printf("exception! the is no item for peek\n");
return -1;
}

int main(){




push(10);
push(34);
push(43);
printStk();
peek();
 printf("the peek item is:%d\n",peek());
 printf("the pop item is:%d\n", pop());
push(4);
printf("the peek item is:%d\n",peek());
printStk();


}

