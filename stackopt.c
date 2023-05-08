#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char * arr;
};
int stacktop(struct stack *sp){
    return sp->arr[sp->top];
}
int empty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int full(struct stack *ptr){
    if(ptr->top==ptr->size-1){
         return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *ptr,int data){
    if(full(ptr)){
        printf("can't push");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}
char pop(struct stack *ptr){
    if(empty(ptr)){
        printf("stack is empty");
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isoperator(char ch){
    if(ch=='/' || ch=='*' || ch=='-' || ch=='+'){
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char ch){
    if(ch=='/' || ch=='*'){
        return 3;
    }
    if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
char * infixtopostfix(char *infix){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    char *postfix=(char *)malloc((strlen(infix)+1)*(sizeof(char)));
    int j=0;
    int i=0;
    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!empty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
char *infixtoprefix(char *infix){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    char *prefix=(char *)malloc((strlen(infix)+1)*(sizeof(char)));
    int i=strlen(infix)-1;
    int j=0;
    while(i>=0){
        if(!isoperator(infix[i])){
            prefix[j]=infix[i];
            i--;
            j++;
        }
        else{
            if(precedence(infix[i])>=precedence(stacktop(sp))){
                push(sp,infix[i]);
                i--;
            }
            else{
                prefix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!empty(sp)){
        prefix[j]=pop(sp);
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
    //printf("postfix is %s\n", infixtopostfix(infix));
    printf("prefix is %s", infixtoprefix(infix));
    return 0;
}