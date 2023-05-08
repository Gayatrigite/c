#include <stdio.h>
#include <stdlib.h>
// STACK Push Pop Peek
struct stack{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct stack *ptr){ //O(1)
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr){ //O(1)
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}
void push(struct stack * ptr,int val){ //O(1)
    if(isFull(ptr)){
        printf("Stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack * ptr){ //O(1)
    if(isEmpty(ptr)){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack * s,int i){
    int arrayInd = s->top -i +1;
    if(arrayInd < 0){
        printf("not a valid position for the stack\n");
        return -1;
    }
    else{
        return s->arr[arrayInd];
    }
}
int stackTop(struct stack *s){
    return s->arr[s->top];
}
int stackBottom(struct stack *s){
    return s->arr[0];
}
void display(struct stack *ptr){
    {
    if (isEmpty(ptr)) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in the stack are: \n");
        for (int i = ptr->top; i >= 0; i--) {
            printf("%d \n", ptr->arr[i]);
        }
        printf("\n");
    }
}
}
int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s,56);
    push(s,66);
    push(s,76);
    push(s,86);
    push(s,96);
    push(s,6);
    display(s);
    pop(s);
    display(s);
    for(int j=1; j<= s->top+1; j++){
        printf("The value at index %d is %d \n",j,peek(s,j));
    }
}
