 #include <stdio.h>
 #include<conio.h>
#include <stdlib.h>
struct stack{
    int top;
    int capacity;
    int *arr;
};

struct stack* myStack(int cap){
    struct stack*  sp=(struct stack*)malloc(sizeof(struct stack));
    sp->top =-1;
    sp->capacity= cap;
    sp->arr=(int*)malloc(sizeof(int)* sp->capacity);
    return(sp);
};

int menu(){
 int choice;
 printf("\n 1. push");
 printf("\n 2. pop");
 printf("\n 3.show Stack");
 printf("\n 4.exit");

 printf("Enter your choice >> ");
 scanf("%d",&choice);
 return (choice);

}
int isStackFull(struct stack *sp){
if(sp->top == sp->capacity-1)
    return(1);
else
    return(0);

}

int isEmpty(struct stack *sp){
if(sp->top == -1)
    return(1);
else
    return(0);
}

void doubleStack(struct stack *sp){
    int i;
     sp->capacity=(sp->capacity)*2;
    int *temp=(int*)malloc(sizeof(int)* sp->capacity);
    for (i=0; i<= sp-> top; i++){
        temp[i]= sp->arr[i];
    }
    free(sp->arr);
    sp->arr = temp;
}

void push(struct stack *sp){
    if(isStackFull(sp)){
        doubleStack(sp);
        printf(" \n stack is doubled");
    }
    int value;
    printf("\n enter the value: ");
    scanf("%d", &value);
    sp->top++;
    sp->arr[sp->top]= value;
    printf("/n %d is added",value);
   }


void halfStack(struct stack *sp){
    int i;
    if(sp->top == ((sp->capacity)/2)-1){
        sp->capacity=(sp->capacity)/2;
        int *temp=(int*)malloc(sizeof(int)*sp->capacity);
        for(i=0; i<= sp->top; i++){
            temp[i]= sp->arr[i];
        }
        free(sp->arr);
        sp->arr= temp;
        printf("\n Stack half done");
    }

}


void  pop(struct stack * sp){

    if(isEmpty(sp)){
        printf("\nstack is underflowed");
    }
    else{
        int value= sp->arr[sp->top];
         sp->top--;
         printf("\n poped value is: %d", value);
         halfStack(sp);

    }
}
void showStack(struct stack *sp){
    if(isEmpty(sp)){
        printf("\nstack is empty");
    }else
    {
        int j;
         printf("\n Elements of this Stack is: ");

        for(j=0;j<= sp->top; j++){
            printf(" %d  ",sp->arr[j]);
        }

    }
}

void printStatus(struct stack *sp){
    printf("\n stack capacity: %d",sp->capacity);
    printf("\nStack size: %d",sizeof(int)*sp->capacity);
    printf("\n stack top: %d",sp->top);

}

int main(){
     struct stack *sp= myStack(5);
    int breakLoop= 0;
     while(1){
        system("cls");
        switch(menu()){
        case 1:
            push(sp);
            printStatus(sp);
            getch();
            break;

        case 2:
            pop(sp);
            printStatus(sp);
            getch();
            break;
        case 3:
            showStack(sp);
            printStatus(sp);
            getch();
            break;
        case 4:
            breakLoop=1;
            break;
        default:
            printf("\n Invalid choice");
        }
            if(breakLoop==1)
                break;
}

}






