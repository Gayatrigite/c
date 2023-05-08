//WAP to convert infix expression into equivalent postfix and prefix format using stack 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char * arr;
};

int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr,char val){
    if(isFull(ptr)){
        printf("Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack empty");
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
char * infixTopostfix(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int j=0;  //track postfix
    int i=0;  //track infix

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

char * infixToprefix(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char));
    char * prefix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int j=0;  //track prefix
    int i=strlen(infix)-1;  //track infix from end

    while(i>=0){
        if(!isOperator(infix[i])){
            prefix[j] = infix[i];
            i--;
            j++;
        }
        else{
            if(precedence(infix[i])>= precedence(stackTop(sp))){
                push(sp, infix[i]);
                i--;
            }
            else{
                prefix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        prefix[j] = pop(sp);
        j++;
    }
    prefix[j] = '\0';

    // Reverse the prefix expression
    for(int i=0, j=strlen(prefix)-1; i<j; i++, j--){
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }

    return prefix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix is %s\n", infixTopostfix(infix));
    printf("prefix is %s", infixToprefix(infix));
    return 0;
}