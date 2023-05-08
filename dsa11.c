#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the array

int tree[MAX_SIZE]; // The binary tree stored as an array
int size = 0; // Current size of the tree

// Function to insert a new element into the tree
void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Error: tree is full.\n");
        return;
    }
    tree[size++] = value;
}

// Function to get the index of the left child of a given node
int leftChild(int index) {
    return 2 * index + 1;
}

// Function to get the index of the right child of a given node
int rightChild(int index) {
    return 2 * index + 2;
}

// Function to print the contents of the tree in in-order traversal
void inOrderTraversal(int index) {
    if (index >= size) {
        return;
    }
    inOrderTraversal(leftChild(index));
    printf("%d ", tree[index]);
    inOrderTraversal(rightChild(index));
}

// Example usage
int main() {
    // Insert elements into the tree
    insert(5);
    insert(2);
    insert(8);
    insert(1);
    insert(3);
    insert(7);
    insert(9);

    // Print the contents of the tree
    printf("In-order traversal: ");
    inOrderTraversal(0);
    printf("\n");

    return 0;
}
