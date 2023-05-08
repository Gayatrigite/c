#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Stack {
    int top;
    char data[MAX_LEN];
};

void push(struct Stack *stack, char c) {
    if (stack->top == MAX_LEN - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = c;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

void concatenate(char str1[], char str2[]) {
    struct Stack stack;
    stack.top = -1;
    int i, j;
    for (i = strlen(str2)-1; i >= 0; i--) {
        push(&stack, str2[i]);
    }
    for (i = strlen(str1)-1; i >= 0; i--) {
        push(&stack, str1[i]);
    }
    char c;
    for (i = 0; stack.top != -1; i++) {
        c = pop(&stack);
        str1[i] = c;
    }
    str1[i] = '\0';
}

int compare(char str1[], char str2[]) {
    struct Stack stack1, stack2;
    stack1.top = stack2.top = -1;
    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        push(&stack1, str1[i]);
    }
    for (i = 0; str2[i] != '\0'; i++) {
        push(&stack2, str2[i]);
    }
    char c1, c2;
    while (stack1.top != -1 && stack2.top != -1) {
        c1 = pop(&stack1);
        c2 = pop(&stack2);
        if (c1 != c2) {
            return c1 - c2;
        }
    }
    if (stack1.top != -1) {
        return 1;
    } else if (stack2.top != -1) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter the first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline
    printf("Enter the second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline
    concatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);
    int cmp = compare(str1, str2);
    if (cmp == 0) {
        printf("The two strings are equal.\n");
    } else if (cmp > 0) {
        printf("The first string is greater than the second string.\n");
    } else {
        printf("The second string is greater than the first string.\n");
    }
    return 0;
}
