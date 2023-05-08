#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node {
    int data;
    struct node *next;
};

struct node *hashTable[SIZE] = {NULL};

void insert(int val) {
    int key = val % SIZE;
    int i = 1;
    while (hashTable[key] != NULL && i < SIZE) {
        key = (key + i) % SIZE;
        i++;
    }
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    hashTable[key] = newNode;
}

void search() {
    int val, index, i, key;
    printf("\nEnter search element\n");
    scanf("%d", &val);
    key = val % SIZE;
    i = 1;
    while (hashTable[key] != NULL && i <= SIZE) {
        if (hashTable[key]->data == val) {
            printf("\nElement found at index %d", key);
            return;
        }
        key = (key + i) % SIZE;
        i++;
    }
    printf("\n Element not found!");
}

void printHashTable() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("HashTable[%d]-->", i);
        struct node *temp = hashTable[i];
        while (temp != NULL) {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    insert(27);
    insert(7);
    insert(37);
    
    
    printHashTable();
    search();
    return 0;
}
