#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};

struct stack *aStack(int cap){
    struct stack *sp= malloc(sizeof(struct stack));
    sp->top= -1;
    sp->size= cap;
    sp->arr = (int*)malloc(sizeof(int));
    return sp;
};

int isStackFull(struct stack *sp){
    if(sp->top == sp->size-1)
        return 1;
    else
        return 0;

}

int isEmpty(struct stack *sp){
    if(sp->top == -1)
        return 1;
    else
        return 0;
}

void doubleStack(struct stack *sp){
    int i;
    sp->size=(sp->size)*2;
    int *temp=(int*)malloc(sizeof(int)* sp->size);
    for (i=0; i<= sp-> top; i++){
        temp[i]= sp->arr[i];
    }
    free(sp->arr);
    sp->arr = temp;
}

void push(struct stack *sp,int x){
            if(isStackFull(sp)){
            doubleStack(sp);
            }
            sp->top++;
            sp->arr[sp->top]= x;
            printf("\n %d th  item is: %d ",sp->top, x);
    }

int pop(struct stack *sp){
    if(isEmpty(sp)){
        printf("\n Stack Under flow");
    }else{
         int value;
        value= sp->arr[sp->top];
        sp->top--;
        printf("\n poped item is: %d",value);
        return value;
    }
}

int peek(struct stack *sp){
    if(isEmpty(sp))
        {
        printf("\n there is nothing for you");
    }else{
     return sp->arr[sp->top];
    }
}

void printStack(struct stack *sp){
    int i;
    printf("\n The stack is : ");
    for(i=0; i<= sp->top; i++){
        printf("%d ",sp->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack *sp=aStack(2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,10);
    push(sp,3);
    push(sp,4);
    push(sp,765);
    push(sp,1560);
    printStack(sp);
    pop(sp);
    printf("\n top item is:%d ",peek(sp));
    printStack(sp);
   getch();
}
