Linked List Assignment
Problem Statement:- Write a RemoveDuplicates() function which takes a list sorted in increasing
order and deletes any duplicate nodes from the list. Ideally, the list should only be traversed once.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
struct Node *head;
void sortList(struct Node *head)
{
  struct Node *current;
  int temp;
  int swapped;
  do
  {
    swapped = 0;
    current = head;

    while (current->next != NULL)
    {
      if (current->data > current->next->data)
      {
        temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        swapped = 1;
      }
      current = current->next;
    }
  } while (swapped);
}

void removeDuplicates(struct Node *head)
{

  struct Node *current = head;

  struct Node *next_next;

  if (current == NULL)
    return;

  while (current->next != NULL)
  {

    if (current->data == current->next->data)
    {

      next_next = current->next->next;
      free(current->next);
      current->next = next_next;
    }

    else
    {
      current = current->next;
    }
  }
}

void insert(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  if (head == NULL)
  {
    head = newNode;
    printf("Inserted node at address %p as head node.\n", head);
    printf("\n");
  }
  else
  {
    struct Node *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    printf("Inserted node with value %d at address %p.\n", data, newNode);
    printf("Previous node is at address %p.\n", current);
    printf("Next node is at address %p.\n", newNode->next);
    printf("\n");
  }
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d\t", node->data);
    node = node->next;
    printf("\n");
  }
}
void printlist(struct Node *node)
{
  while (node != NULL)
  {
    printf("\nPrevious node is at address %p \n", node->prev);
    printf("\nNode with value %d is at address %p \n", node->data, node);
    printf("\nNext node is at address %p \n", node->next);
    node = node->next;
    printf("\n");
  }
}

int main()
{

  int n, x;
  printf("Enter the number of nodes to be inserted: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &x);
    insert(x);
  }
  printf("Before Sorting\n");
  printList(head);
  printf("After Sorting\n");
  sortList(head);
  printList(head);
  printf("After Removing Duplicates\n");
  removeDuplicates(head);
  printlist(head);

  return 0;
}




1.
Given a list, split it into two sublists — one for the front half, and one for the back half. If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}. Getting this right for all
the cases is harder than it looks. You should check your solution against a few cases (length = 2, length = 3, length=4) to make sure that the list gets split correctly near the short­list boundary conditions. If it works right for length=4, it probably works right for length=1000. You will probably need special case code to deal with the (length <2) cases.

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Return the total number of nodes in a list
int findLength(struct Node* head)
{
    int count = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

/*
    Split the given list's nodes into front and back halves
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
*/
void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
    int len = findLength(source);
    if (len < 2)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct Node* current = source;

    int hopCount = (len - 1) / 2;        // (figured these with a few drawings)
    for (int i = 0; i < hopCount; i++) {
        current = current->next;
    }

    // Now cut at current
    *frontRef = source;
    *backRef = current->next;
    current->next = NULL;
}

int main(void)
{
    // input keys
    int keys[] = {2, 3, 5, 7, 11};
    int n = sizeof(keys)/sizeof(keys[0]);

    // points to the head node of the linked list
    struct Node* head = NULL;

    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    struct Node *a = NULL, *b = NULL;
    frontBackSplit(head, &a, &b);

    // print linked list
    printf("Front List: ");
    printList(a);

    printf("\nBack List: ");
    printList(b);

    return 0;
}


2. WAP to perform addition o f two polynomials using singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node Node;

void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if (*poly == NULL) {
        *poly = temp;
        return;
    }

    Node* current = *poly;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = temp;
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    Node* current = poly;

    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }

    printf("\n");
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    insert(&poly1, 5, 4);
    insert(&poly1, 3, 2);
    insert(&poly1, 1, 0);

    Node* poly2 = NULL;
    insert(&poly2, 4, 4);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);

    printf("First polynomial: ");
    print(poly1);

    printf("Second polynomial: ");
    print(poly2);

    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);

    return 0;
}



3. Write an iterative Reverse() function that reverses a list by rearranging
all the .next pointers and the head pointer.

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Reverses a given linked list by changing its `.next` pointers and
// its head pointer. Takes a pointer (reference) to the head pointer
void reverse(struct Node** head)
{
    struct Node* previous = NULL;   // the previous pointer
    struct Node* current = *head;   // the main pointer

    // traverse the list
    while (current != NULL)
    {
        // tricky: note the next node
        struct Node* next = current->next;

        current->next = previous;    // fix the current node

        // advance the two pointers
        previous = current;
        current = next;
    }

    // fix the head pointer to point to the new front
    *head = previous;
}

int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }

    reverse(&head);

    printList(head);

    return 0;
}




Problem Statement(ISHA) -
WAP to perform Multiplication , Addition and Substraction of two polynomials using single Linked List.
#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
// Creating Linklist
struct node *create(int n)
{
    printf("\n");
    struct node *temp, *head, *newNode;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Coefficient of x%d: ", n);
    int data;
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (int i = n - 1; i >= 0; i--)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Coefficient of x%d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
// To find maximum degree for printing polynomial
int max(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}
// Print polynomial
void print(struct node *head, int n)
{
    struct node *temp;
    temp = head;
    while (temp != NULL && n >= 0)
    {
        printf("%dx^%d", abs(temp->data), n);
        if (n > 0 && temp->data >= 0)
        {
            printf(" + ");
        }
        else if (n > 0 && temp->data < 0)
        {
            printf(" - ");
        }
        temp = temp->next;
        n--;
    }
    printf("\n");
}
// Addition of two polynomial
struct node *add(struct node *head1, struct node *head2, int n1, int n2)
{
    struct node *t1, *t2, *head3, *newNode, *t3;
    t1 = head1;
    t2 = head2;
    head3 = (struct node *)malloc(sizeof(struct node));
    head3->data = -1;
    head3->next = NULL;
    t3 = head3;
    while (t1 != NULL && t2 != NULL)
    {
        if (n1 == n2)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = t1->data + t2->data;
            newNode->next = NULL;
            t3->next = newNode;
            t3 = t3->next;
            t1 = t1->next;
            t2 = t2->next;
            n1--;
            n2--;
        }
        else if (n1 > n2)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = t1->data;
            newNode->next = NULL;
            t3->next = newNode;
            t3 = t3->next;
            t1 = t1->next;
            n1--;
        }
        else if (n2 > n1)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = t2->data;
            newNode->next = NULL;
            t3->next = newNode;
            t3 = t3->next;
            t2 = t2->next;
            n2--;
        }
    }
    return head3->next;
}
// Subtracting 2nd polynomial from 1st
struct node *sub(struct node *head1, struct node *head2, int n1, int n2)
{
    struct node *t1, *t2, *head3, *newNode, *t3;
    t1 = head1;
    t2 = head2;
    head3 = (struct node *)malloc(sizeof(struct node));
    head3->data = -1;
    head3->next = NULL;
    t3 = head3;
    while (t1 != NULL && t2 != NULL)
    {
        if (n1 == n2)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = t1->data - t2->data;
            newNode->next = NULL;
            t3->next = newNode;
            t3 = t3->next;
            t1 = t1->next;
            t2 = t2->next;
            n1--;
            n2--;
        }
        else if (n1 > n2)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = t1->data;
            newNode->next = NULL;
            t3->next = newNode;
            t3 = t3->next;
            t1 = t1->next;
            n1--;
        }
        else if (n2 > n1)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = t2->data;
            newNode->next = NULL;
            t3->next = newNode;
            t3 = t3->next;
            t2 = t2->next;
            n2--;
        }
    }
    return head3->next;
}
// multiplication of polynomial
struct node *nullResult(int n)
{
    struct node *temp, *head, *newNode;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    temp = head;
    for (int i = n - 1; i >= 0; i--)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = 0;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
struct node *multiply(struct node *head1, struct node *head2, int n1, int n2)
{
    struct node *result = nullResult(n1 + n2);
    struct node *t1, *t2, *t3, *temp, *temp1;
    temp = result;
    temp1 = result;
    t1 = head1;
    t2 = head2;
    t3 = t2;
    int x = n2;
    int index = 1;
    while (n1 >= 0)
    {
        while (n2 >= 0)
        {
            temp1->data = temp1->data + (t1->data * t2->data);
            t2 = t2->next;
            temp1 = temp1->next;
            n2--;
        }
        n2 = x;
        temp1 = temp->next;
        temp = temp->next;
        t2 = t3;
        t1 = t1->next;
        n1--;
    }
    return result;
}
int main()
{
    printf("\nDegree of 1st polynomial : ");
    int n1;
    scanf("%d", &n1);
    struct node *head1 = create(n1);
    printf("\nDegree of 2nd polynomial : ");
    int n2;
    scanf("%d", &n2);
    struct node *head2 = create(n2);
    printf("\n1st Polynomial : ");
    print(head1, n1);
    printf("\n2nd Polynomial : ");
    print(head2, n2);
printf("-----------------------------------------------------------------");
printf("\n\nAddition : ");
print(add(head1,head2,n1,n2),max(n1,n2));
printf("\n\nSubtraction : ");
print(sub(head1,head2,n1,n2),max(n1,n2));
printf("\n\nMultiplication : ");
print(multiply(head1,head2,n1,n2),(n1+n2));
printf("\n\n");
return 0;
}


Stack Assignment 

Problem Statement:- Write a program to find x^n using explicit stack
#include <stdio.h>
#include <stdlib.h>



struct Stack
{
    int data;
    struct Stack *next;
};


struct Stack* newNode(int data)
{
    struct Stack* node = (struct Stack*) malloc(sizeof(struct Stack));
    node->data = data;
    node->next = NULL;
    return node;
}


void push(struct Stack** root, int data)
{
    struct Stack* node = newNode(data);
    node->next = *root;
    *root = node;
}


int pop(struct Stack** root)
{
    if (*root == NULL)
        return -1;
    struct Stack* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}


int power(int x, int n)
{
    struct Stack* stack = NULL;

   
    int pow = 1;
    while (n)
    {
        push(&stack, n);
        n--;
        pow = pow * x;
    }  

   
    int result = 1;
    while (stack)
    {
        result = result * x;
        pow = pow / x;
        n = pop(&stack) - 1;
    }
    return result;
}

int main()
{
    int x, n;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("%d^%d = %d\n", x, n, power(x, n));

    return 0;
}




Queue Assignment
Problem Statement:- An operating system assigns job to print queues based on the number of pages to be printed (1 to 50 pages). You may assume that the system printers are able to print 10 page per minute. Smaller print jobs are printed before larger print jobs and print jobs are processed from a single print queue implemented as a priority queue). The system administrators would like to compare the time required to process a set of print jobs using 1, 2, or 3 system printers. Write a program which simulates processing 100 print jobs of varying lengths using either 1, 2, or 3 printers. Assume that a print request is made every minute and that the number of pages to print varies from 1 to 50 pages. To be fair, you will need to process the same set of print jobs each time you add a printer. The output from your program should indicate the order in which the jobs were received, the order in which they were printed, and the time required to process the set of print jobs. If more than one printer is being used, indicate which printer each job was printed on.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PAGES 50
#define NUM_JOBS 100
#define PRINT_SPEED 1

typedef struct job
{
  int id;
  int pages;
  int printer;
  struct job *next;
} Job;

Job *newJob(int id, int pages)
{
  Job *job = (Job *)malloc(sizeof(Job));
  job->id = id;
  job->pages = pages;
  job->printer = 0;
  job->next = NULL;
  return job;
}

void printJob(Job *job, int printer)
{
  job->printer = printer;
  printf("Printer %d printed job %d with %d pages\n", rand()%3+1, job->id, job->pages);
}

int main()
{
  srand(time(NULL));

  printf("Enter the number of printers: \n");
  int n;
  scanf("%d", &n);
  Job *queue = NULL;
  for (int i = 0; i < NUM_JOBS; i++)
  {
    int pages = rand() % MAX_PAGES + 1;
    Job *job = newJob(i + 1, pages);

    if (queue == NULL)
    {
      queue = job;
    }
    else
    {
      Job *curr = queue;
      while (curr->next != NULL)
      {
        curr = curr->next;
      }
      curr->next = job;
    }
  }

  for (int numPrinters = n; numPrinters <= n; numPrinters++)
  {
    printf("Processing jobs with %d printer(s)\n", numPrinters);

    Job *curr = queue;
    int printerSpeeds[numPrinters];
    for (int i = 0; i < numPrinters; i++)
    {
      printerSpeeds[i] = PRINT_SPEED;
    }

    int time = 0;
    while (curr != NULL)
    {

      int shortest = 0;
      for (int i = 1; i < numPrinters; i++)
      {
        if (printerSpeeds[i] < printerSpeeds[shortest])
        {
          shortest = i;
        }
      }

      if (printerSpeeds[shortest] > 0)
      {

        printJob(curr, shortest + 1);
        printerSpeeds[shortest] -= curr->pages;
        curr = curr->next;
      }
      else
      {

        time++;
        for (int i = 0; i < numPrinters; i++)
        {
          printerSpeeds[i] = (printerSpeeds[i] < 0) ? 0 : printerSpeeds[i] + PRINT_SPEED;
        }
      }
    }

    printf("Total time with %d printer(s): %d minutes\n", numPrinters, time);
  }

  return 0;
}



                                         LAB ASSIGNMENT


TREES

1.Write a Program to create a Binary Tree and perform following
non recursive operations on it. a. Preorder Traversal b. Postorder
Traversal c. Count total no. of nodes d. Display height of a tree.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    struct node *temp = *root;
    while (temp != NULL) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                return;
            }
            temp = temp->left;
        } else if (data > temp->data) {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                return;
            }
            temp = temp->right;
        } else {
            return;
        }
    }
}

void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    struct node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node *temp = stack[top--];
        printf("%d ", temp->data);
        if (temp->right != NULL) {
            stack[++top] = temp->right;
        }
        if (temp->left != NULL) {
            stack[++top] = temp->left;
        }
    }
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    struct node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        struct node *temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL) {
            stack1[++top1] = temp->left;
        }
        if (temp->right != NULL) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 >= 0) {
        struct node *temp = stack2[top2--];
        printf("%d ", temp->data);
    }
}

int countNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    int count = 1;
    struct node *stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node *temp = stack[top--];
        if (temp->right != NULL) {
            stack[++top] = temp->right;
            count++;
        }
        if (temp->left != NULL) {
            stack[++top] = temp->left;
            count++;
        }
    }
    return count;
}

int height(struct node *root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct node *root

root = NULL;
insert(&root, 10);
insert(&root, 5);
insert(&root, 15);
insert(&root, 3);
insert(&root, 7);
insert(&root, 13);
insert(&root, 18);
printf("Preorder traversal: ");
preorder(root);
printf("\n");
printf("Postorder traversal: ");
postorder(root);
printf("\n");
printf("Total number of nodes: %d\n", countNodes(root));
printf("Height of the tree: %d\n", height(root));
return 0;
}
2. Write a Program to create a Binary Tree and perform following
nonrecursive operations on it. a. Levelwise display b. Mirror image c.
Display height of a tree.


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertLeft(struct node *root, int value) {
    root->left = createNode(value);
    return root->left;
}

struct node *insertRight(struct node *root, int value) {
    root->right = createNode(value);
    return root->right;
}

void levelwiseDisplay(struct node *root) {
    if(root == NULL)
        return;

    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while(front != rear) {
        struct node *temp = queue[++front];
        printf("%d ", temp->data);

        if(temp->left != NULL)
            queue[++rear] = temp->left;

        if(temp->right != NULL)
            queue[++rear] = temp->right;
    }
}

void mirrorImage(struct node *root) {
    if(root == NULL)
        return;

    mirrorImage(root->left);
    mirrorImage(root->right);

    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int getHeight(struct node *root) {
    if(root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);

    printf("Levelwise Display: ");
    levelwiseDisplay(root);
    printf("\n");

    mirrorImage(root);

    printf("Levelwise Display after Mirror Image: ");
    levelwiseDisplay(root);
    printf("\n");

    printf("Height of the Tree: %d\n", getHeight(root));

    return 0;
}



3.  Write a program to illustrate operations on a BST holding numeric keys.

The menu must include: • Insert • Delete • Find • Show


#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct node * minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}

int main() {
    struct node *root = NULL;
    int choice, key;

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Find\n4. Show\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("%d inserted successfully.\n", key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("%d deleted successfully.\n", key);
                break;

            case 3:
                printf("Enter key to find: ");
                scanf("%d", &key);
                if(search(root, key) != NULL)
                    printf("%d found in the tree.\n", key);
                else
                    printf("%d not found in the tree.\n", key);
                break;

            case 4:
                printf("Tree contents: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

4. Write a program to illustrate operations on a BST holding numeric keys.
The menu must include: • Insert • Mirror Image • Find • Post order
(nonrecursive)


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;

node* create_node(int key) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

node* mirror(node* root) {
    if (root == NULL) {
        return NULL;
    }
    node* new_root = create_node(root->key);
    new_root->left = mirror(root->right);
    new_root->right = mirror(root->left);
    return new_root;
}

node* find(node* root, int key) {
    while (root != NULL && root->key != key) {
        if (key < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

void post_order(node* root) {
    if (root == NULL) {
        return;
    }
    node* stack[100];
    int top = -1;
    node* current = root;
    while (1) {
        while (current != NULL) {
            if (current->right != NULL) {
                stack[++top] = current->right;
            }
            stack[++top] = current;
            current = current->left;
        }
        if (top == -1) {
            break;
        }
        current = stack[top--];
        if (current->right != NULL && top != -1 && current->right == stack[top]) {
            stack[top--] = current;
            current = current->right;
        } else {
            printf("%d ", current->key);
            current = NULL;
        }
    }
}

int main() {
    node* root = NULL;
    int choice, key;
    while (1) {
        printf("\nMenu:\n1. Insert\n2. Mirror Image\n3. Find\n4. Post order\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                root = mirror(root);
                printf("Mirror image created.\n");
                break;
            case 3:
                printf("Enter key to find: ");
                scanf("%d", &key);
                if (find(root, key) != NULL) {
                    printf("Key found.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 4:
                printf("Post order traversal: ");
                post_order(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}


5. Write a Program to create a Binary Tree and perform following
Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal
c. Display Number of Leaf Nodes d. Mirror Image

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(node* root) {
    node* stack[100];
    int top = -1;
    node* current = root;
    while (1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        if (top == -1) {
            break;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        node* current = stack[top--];
        printf("%d ", current->data);
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

int count_leaves(node* root) {
    if (root == NULL) {
        return 0;
    }
    node* stack[100];
    int top = -1;
    stack[++top] = root;
    int count = 0;
    while (top != -1) {
        node* current = stack[top--];
        if (current->right == NULL && current->left == NULL) {
            count++;
        }
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    return count;
}

node* mirror(node* root) {
    if (root == NULL) {
        return NULL;
    }
    node* new_root = create_node(root->data);
    new_root->left = mirror(root->right);
    new_root->right = mirror(root->left);
    return new_root;
}

int main() {
    node* root = NULL;
    int choice, data;
    while (1) {
        printf("\nMenu:\n1. Insert\n2. Inorder traversal\n3. Preorder traversal\n4. Count leaves\n5. Mirror image\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n”);
break;
        case 4:
            printf("Number of leaf nodes: %d\n", count_leaves(root));
            break;
        case 5:
            printf("Mirror image:\n");
            node* mirror_root = mirror(root);
            printf("Inorder traversal: ");
            inorder(mirror_root);
            printf("\n");
            printf("Preorder traversal: ");
            preorder(mirror_root);
            printf("\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}
return 0;
}

6. Write a Program to create a Binary Tree and perform following
Nonrecursive operations on it. a. Inorder Traversal b. Preorder Traversal
c. Display Height of a tree d. Find Maximum

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(node* root) {
    node* stack[100];
    int top = -1;
    node* current = root;
    while (1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        if (top == -1) {
            break;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        node* current = stack[top--];
        printf("%d ", current->data);
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    node* stack[100];
    int top = -1;
    stack[++top] = root;
    int max_height = 0;
    int current_height = 0;
    node* last_popped = NULL;
    while (top != -1) {
        node* current = stack[top];
        if (last_popped == NULL || last_popped->left == current || last_popped->right == current) {
            current_height++;
            if (current->left != NULL) {
                stack[++top] = current->left;
            } else if (current->right != NULL) {
                stack[++top] = current->right;
            }
        } else if (current->left == last_popped) {
            if (current->right != NULL) {
                stack[++top] = current->right;
            }
        } else {
            current_height--;
        }
        last_popped = current;
        if (current_height > max_height) {
            max_height = current_height;
        }
        top--;
    }
    return max_height;
}

int find_max(node* root) {
    node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main() {
    node* root = NULL;
    int choice, data;
    while (1) {
        printf("\nMenu:\n1. Insert\n2. Inorder traversal\n3. Preorder traversal\n4. Display height\n5. Find maximum\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {

        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Data inserted successfully!\n");
            break;
        case 2:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Height of the tree: %d\n", height(root));
            break;
        case 5:
            printf("Maximum element in the tree: %d\n", find_max(root));
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}
return 0;
}

7. You have to maintain information for a shop owner. For each of the
products sold in his/hers shop the following information is kept: a
unique code, a name, a price, amount in stock, date received, expiration
date. For keeping track of its stock, the clerk would use a computer
program based on a search tree data structure. Write a program to help
this person, by implementing the following operations: • Insert an item
with all its associated data. • Find an item by its code, and support
updating of the item found. • List valid items in lexicographic order of
their names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each product
typedef struct {
    char code[10];
    char name[50];
    float price;
    int stock;
    char date_received[11];
    char expiration_date[11];
} Product;

// Define the structure for the search tree node
typedef struct Node {
    Product product;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with a given product
Node* createNode(Product product) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->product = product;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a product into the search tree
Node* insert(Node* root, Product product) {
    if (root == NULL) {
        return createNode(product);
    }
    if (strcmp(product.code, root->product.code) < 0) {
        root->left = insert(root->left, product);
    } else {
        root->right = insert(root->right, product);
    }
    return root;
}

// Function to search for a product by its code
Node* search(Node* root, char code[]) {
    if (root == NULL || strcmp(code, root->product.code) == 0) {
        return root;
    }
    if (strcmp(code, root->product.code) < 0) {
        return search(root->left, code);
    }
    return search(root->right, code);
}

// Function to update the details of a product
void updateProduct(Node* node) {
    printf("Enter the new name: ");
    fgets(node->product.name, 50, stdin);
    printf("Enter the new price: ");
    scanf("%f", &node->product.price);
    printf("Enter the new stock: ");
    scanf("%d", &node->product.stock);
    printf("Enter the new date received: ");
    fgets(node->product.date_received, 11, stdin);
    printf("Enter the new expiration date: ");
    fgets(node->product.expiration_date, 11, stdin);
}

// Function to list all valid products in lexicographic order of their names
void listProducts(Node* root) {
    if (root != NULL) {
        listProducts(root->left);
        if (strcmp(root->product.expiration_date, "N/A") != 0 && strcmp(root->product.expiration_date, "Expired") != 0) {
            printf("%s, %s, %.2f, %d, %s, %s\n", root->product.code, root->product.name, root->product.price, root->product.stock, root->product.date_received, root->product.expiration_date);
        }
        listProducts(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    char code[10];

    do {
        printf("\n1. Insert a product");
        printf("\n2. Find and update a product");
        printf("\n3. List valid products in lexicographic order");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1: {
                Product product;
                printf("\nEnter the product code: ");
                fgets(product.code, 10, stdin);
                printf("Enter the product name: ");
                fgets(product.name, 50, stdin);
                printf("Enter the product price : ");
scanf("%f", &product.price);
printf("Enter the product stock: ");
scanf("%d", &product.stock);
getchar(); // to consume the newline character
printf("Enter the date received (dd/mm/yyyy): ");
fgets(product.date_received, 11, stdin);
printf("Enter the expiration date (dd/mm/yyyy or N/A): ");
fgets(product.expiration_date, 11, stdin);
root = insert(root, product);
printf("\nProduct inserted successfully!\n");
break;
}
case 2: {
printf("\nEnter the product code to search: ");
fgets(code, 10, stdin);
Node* node = search(root, code);
if (node == NULL) {
printf("Product not found!\n");
} else {
updateProduct(node);
printf("Product details updated successfully!\n");
}
break;
}
case 3: {
printf("\nList of valid products in lexicographic order:\n");
listProducts(root);
break;
}
case 4: {
printf("\nExiting program...\n");
break;
}
default: {
printf("\nInvalid choice, please try again!\n");
}
}
} while (choice != 4);
return 0;}



8. You have to maintain information for a shop owner. For each of the
products sold in his/hers shop the following information is kept: a
unique code, a name, a price, amount in stock, date received, expiration
date. For keeping track of its stock, the clerk would use a computer
program based on a search tree data structure. Write a program to help
this person, by implementing the following operations: • Insert an item
with all its associated data. • Find an item by its code, and support
updating of the item found. • List valid items in lexicographic order of
their names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a product
struct Product {
    int code;
    char name[50];
    float price;
    int stock;
    char date_received[11];
    char expiration_date[11];
    struct Product *left;
    struct Product *right;
};

// Define a function to create a new product
struct Product* create_product(int code, char name[], float price, int stock, char date_received[], char expiration_date[]) {
    struct Product* new_product = (struct Product*) malloc(sizeof(struct Product));
    new_product->code = code;
    strcpy(new_product->name, name);
    new_product->price = price;
    new_product->stock = stock;
    strcpy(new_product->date_received, date_received);
    strcpy(new_product->expiration_date, expiration_date);
    new_product->left = NULL;
    new_product->right = NULL;
    return new_product;
}

// Define a function to insert a product into the binary search tree
struct Product* insert_product(struct Product* root, struct Product* new_product) {
    // If the root is null, set the new product as the root
    if (root == NULL) {
        return new_product;
    }

    // Otherwise, insert the product into the appropriate position in the tree
    if (new_product->code < root->code) {
        root->left = insert_product(root->left, new_product);
    } else if (new_product->code > root->code) {
        root->right = insert_product(root->right, new_product);
    }

    return root;
}

// Define a function to find a product by its code and update it
void update_product(struct Product* root, int code) {
    // Traverse the tree to find the product with the given code
    struct Product* current = root;
    while (current != NULL) {
        if (code == current->code) {
            // Update the product
            printf("Enter updated information for product with code %d:\n", code);
            printf("Name: ");
            scanf("%s", current->name);
            printf("Price: ");
            scanf("%f", &current->price);
            printf("Stock: ");
            scanf("%d", &current->stock);
            printf("Date received (YYYY-MM-DD): ");
            scanf("%s", current->date_received);
            printf("Expiration date (YYYY-MM-DD): ");
            scanf("%s", current->expiration_date);
            printf("Product updated successfully.\n");
            return;
        } else if (code < current->code) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("Product with code %d not found.\n", code);
}

// Define a function to list all valid products in lexicographic order of their names
void list_products(struct Product* root) {
    if (root != NULL) {
        list_products(root->left);
        if (strcmp(root->expiration_date, "N/A") != 0 && strcmp(root->expiration_date, "0000-00-00") != 0 && strcmp(root->expiration_date, "") != 0 && strcmp(root->date_received, "") != 0) {
            printf("Code: %d\nName: %s\nPrice: %.2f\nStock: %d\nDate received: %s\nExpiration date: %s\n\n", root->code, root->name, root->price, root->stock, root->date_received, root->expiration_date);
        }
        List_products (struct Product* root->right);
    }
}

int main() {
    // Declare variables for the product data
    int code, stock;
    char name[50], date_received[11], expiration_date[11];
    float price;

    // Declare the root of the binary search tree
    struct Product* root = NULL;

    // Display the menu of operations
    int choice;
    do {
        printf("\nShop Inventory Management\n");
        printf("1. Insert a new product\n");
        printf("2. Update an existing product\n");
        printf("3. List all valid products in lexicographic order of their names\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Prompt the user for the product data
                printf("Enter product code: ");
                scanf("%d", &code);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product stock: ");
                scanf("%d", &stock);
                printf("Enter date received (YYYY-MM-DD): ");
                scanf("%s", date_received);
                printf("Enter expiration date (YYYY-MM-DD or N/A): ");
                scanf("%s", expiration_date);
                // Create a new product with the given data
                struct Product* new_product = create_product(code, name, price, stock, date_received, expiration_date);
                // Insert the new product into the binary search tree
                root = insert_product(root, new_product);
                printf("Product added successfully.\n");
                break;

            case 2:
                // Prompt the user for the product code to update
                printf("Enter product code to update: ");
                scanf("%d", &code);
                // Update the product with the given code
                update_product(root, code);
                break;

            case 3:
                // List all valid products in lexicographic order of their names
                printf("Valid Products:\n\n");
                list_products(root);
                break;

            case 4:
                // Exit the program
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

9. Write a Program to create a Binary Search Tree and perform following
nonrecursive operations on it. a. Preorder Traversal b. Inorder Traversal
c. Display Number of Leaf Nodes d. Mirror Image

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary search tree
struct Node* insert_node(struct Node* root, int data) {
    // If the tree is empty, set the new node as the root
    if (root == NULL) {
        return create_node(data);
    }
    // Otherwise, compare the data of the nodes
    if (data < root->data) {
        // If the new node data is less than the root node data,
        // insert the new node into the left subtree
        struct Node* left_child = insert_node(root->left, data);
        root->left = left_child;
    } else if (data > root->data) {
        // If the new node data is greater than the root node data,
        // insert the new node into the right subtree
        struct Node* right_child = insert_node(root->right, data);
        root->right = right_child;
    }
    return root;
}

// Function to perform preorder traversal of the binary search tree nonrecursively
void preorder_traversal(struct Node* root) {
    // Create an empty stack to store the nodes
    struct Node* stack[100];
    int top = -1;
    // Push the root node onto the stack
    stack[++top] = root;
    // Repeat until the stack is empty
    while (top >= 0) {
        // Pop the top node from the stack and visit it
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        // Push the right child onto the stack (if it exists)
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        // Push the left child onto the stack (if it exists)
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    printf("\n");
}

// Function to perform inorder traversal of the binary search tree nonrecursively
void inorder_traversal(struct Node* root) {
    // Create an empty stack to store the nodes
    struct Node* stack[100];
    int top = -1;
    // Set the current node to the root node
    struct Node* current_node = root;
    // Repeat until the current node and the stack are both empty
    while (current_node != NULL || top >= 0) {
        // Push all left child nodes onto the stack
        while (current_node != NULL) {
            stack[++top] = current_node;
            current_node = current_node->left;
        }
        // Pop the top node from the stack and visit it
        current_node = stack[top--];
        printf("%d ", current_node->data);
        // Set the current node to the right child (if it exists)
        current_node = current_node->right;
    }
    printf("\n");
}

// Function to display the number of leaf nodes in the binary search tree
int count_leaf_nodes(struct Node* root) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }
    // If the node is a leaf node, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    // Otherwise, recursively count the leaf nodes in the left and right subtrees
    return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
}

// Function to create the mirror image of the binary search tree
void mirror_image(struct Node* root) {
    // If the tree is empty, return
    if (root == NULL) {
        return;
    }
    // Swap the left and right child nodes
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recursively create the mirror image of the left and right subtrees
    mirror_image(root->left);
    mirror_image(root->right);
}

// Function to display the binary search tree
void display_tree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    display_tree(root->left);
    display_tree(root->right);
}

// Main function to test the binary search tree program
int main() {
    // Create the binary search tree
    struct Node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    // Print the binary search tree using preorder traversal
    printf("Preorder Traversal: ");
    preorder_traversal(root);
    // Print the binary search tree using inorder traversal
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    // Display the number of leaf nodes in the binary search tree
    printf("Number of Leaf Nodes: %d\n", count_leaf_nodes(root));
    // Create the mirror image of the binary search tree
    mirror_image(root);
    // Print the binary search tree using preorder traversal
    printf("Mirror Image Preorder Traversal: ");
    preorder_traversal(root);
    // Display the number of leaf nodes in the binary search tree
    printf("Number of Leaf Nodes: %d\n", count_leaf_nodes(root));
    return 0;
}

10. Write a Program to create a Binary Search Tree and perform following
nonrecursive operations on it. a. Preorder Traversal b. Postorder
Traversal c. Display total Number of Nodes d. Display Leaf nodes.

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to insert a node into the binary search tree
struct node* insert(struct node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return(newNode(data));
    }
    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    // Return the (unchanged) node pointer
    return(node);
}

// Function to perform a preorder traversal of the binary search tree (nonrecursive)
void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node* temp = stack[top--];
        printf("%d ", temp->data);
        if (temp->right != NULL) {
            stack[++top] = temp->right;
        }
        if (temp->left != NULL) {
            stack[++top] = temp->left;
        }
    }
}

// Function to perform a postorder traversal of the binary search tree (nonrecursive)
void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        struct node* temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL) {
            stack1[++top1] = temp->left;
        }
        if (temp->right != NULL) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 >= 0) {
        struct node* temp = stack2[top2--];
        printf("%d ", temp->data);
    }
}

// Function to count the total number of nodes in the binary search tree
int countNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 1;
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct node* temp = stack[top--];
        if (temp->right != NULL) {
            stack[++top] = temp->right;
            count++;
        }
        if (temp->left != NULL) {
            stack[++top] = temp->left;
            count++;
        }
    }
    return count;
}

// Function to display the leaf nodes of the binary search tree
void displayLeaves(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* stack[100];
int top = -1;
stack[++top] = root;
while (top >= 0) {
    struct node* temp = stack[top--];
    if (temp->right != NULL) {
        stack[++top] = temp->right;
    }
    if (temp->left != NULL) {
        stack[++top] = temp->left;
    }
    if (temp->left == NULL && temp->right == NULL) {
        printf("%d ", temp->data);
    }
}

}
// Main function to test the binary search tree and its operations
int main() {
struct node* root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);
printf("Preorder traversal: ");
preorder(root);
printf("\n");
printf("Postorder traversal: ");
postorder(root);
printf("\n");
printf("Total number of nodes: %d\n", countNodes(root));
printf("Leaf nodes: ");
displayLeaves(root);
printf("\n");
return 0;
}
11. Write a Program to create a Binary Search Tree and perform deletion of
a node from it. Also display the tree in nonrecursive postorder way.
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node in the binary search tree
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to find the minimum value node in the binary search tree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary search tree
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display the binary search tree in nonrecursive postorder way
void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        struct node* temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL) {
            stack1[++top1] = temp->left;
        }
        if (temp->right != NULL) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Main function to test the binary search tree and its operations
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Original binary search tree: ");
    postorder(root);
    printf("\n");
    root = deleteNode(root, 20);
printf("Binary search tree after deletion of node with value 20: ");
postorder(root);
printf("\n");
return 0;
}

12. Write a Program to create a Binary Search Tree and display it levelwise. Also perform deletion of a node from it.
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node in the binary search tree
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to display the binary search tree levelwise
void levelOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
}

// Function to find the minimum value node in the binary search tree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary search tree
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to test the binary search tree and its operations
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Binary search tree levelwise: ");
    levelOrder(root);
    printf("\n");
    root = deleteNode(root, 20);
    printf("Binary search tree levelwise after deletion of node with value 20: ");
    levelOrder(root);
    printf("\n");
    return 0;
}

13. Write a Program to create a Binary Search Tree and display its mirror
image with and without disturbing the original tree. Also display height
of a tree using nonrecursion.
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node in the binary search tree
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to display the binary search tree in inorder way
void inorder(struct node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Function to display the mirror image of the binary search tree without disturbing the original tree
struct node* mirror(struct node* node) {
    if (node == NULL) {
        return node;
    }
    struct node* left = mirror(node->left);
    struct node* right = mirror(node->right);
    node->left = right;
    node->right = left;
    return node;
}

// Function to display the binary search tree levelwise
void levelOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
}

// Function to find the height of the binary search tree using nonrecursion
int height(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    struct node* queue[100];
    int front = 0;
    int rear = 0;
    int level = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        while (size > 0) {
            struct node* temp = queue[front++];
            if (temp->left != NULL) {
                queue[rear++] = temp->left;
            }
            if (temp->right != NULL) {
                queue[rear++] = temp->right;
            }
            size--;
        }
        level++;
    }
    return level;
}

// Main function to test the binary search tree and its operations
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Original binary search tree inorder: ");
    inorder(root);
    printf("\n");
    printf("Levelwise display of binary search tree: ");
    levelOrder(root);
    printf("\n");
    printf("Height of binary search tree: %d\n", height(root));
    printf("Mirror image of binary search tree without disturbing original tree: \n");
    mirror(root);
    printf("Binary search tree inorder after mirror operation: ");
    inorder(root);
    printf("\n");
    return 0;
}
14. You have to maintain information for a shop owner. For each of the
products sold in his/hers shop the following information is kept: a
unique code, a name, a price, amount in stock, date received, expiration
date. For keeping track of its stock, the clerk would use a computer
program based on a search tree data structure. Write a program to help
this person, by implementing the following operations: • Insert an item
with all its associated data. • List expired items in Prefix order of their
names. • List all items. • Delete an item given by its code. • Delete all
expired items.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int code;
    char name[50];
    float price;
    int stock;
    char date_received[11];
    char expiration_date[11];
    struct item *left;
    struct item *right;
};

struct item *root = NULL;

// Helper function to create a new item node
struct item *create_item(int code, char name[], float price, int stock, char date_received[], char expiration_date[]) {
    struct item *new_item = (struct item *) malloc(sizeof(struct item));
    new_item->code = code;
    strcpy(new_item->name, name);
    new_item->price = price;
    new_item->stock = stock;
    strcpy(new_item->date_received, date_received);
    strcpy(new_item->expiration_date, expiration_date);
    new_item->left = NULL;
    new_item->right = NULL;
    return new_item;
}

// Function to insert an item into the binary search tree
void insert_item(int code, char name[], float price, int stock, char date_received[], char expiration_date[]) {
    if (root == NULL) {
        root = create_item(code, name, price, stock, date_received, expiration_date);
        return;
    }

    struct item *curr = root;
    while (1) {
        if (code < curr->code) {
            if (curr->left == NULL) {
                curr->left = create_item(code, name, price, stock, date_received, expiration_date);
                return;
            }
            curr = curr->left;
        } else if (code > curr->code) {
            if (curr->right == NULL) {
                curr->right = create_item(code, name, price, stock, date_received, expiration_date);
                return;
            }
            curr = curr->right;
        } else {
            printf("Item with code %d already exists.\n", code);
            return;
        }
    }
}

// Function to list expired items in prefix order of their names
void list_expired_items(struct item *curr) {
    if (curr == NULL) {
        return;
    }

    list_expired_items(curr->left);
    if (strcmp(curr->expiration_date, "00/00/0000") != 0) {
        printf("%s\n", curr->name);
    }
    list_expired_items(curr->right);
}

// Function to list all items in the binary search tree
void list_all_items(struct item *curr) {
    if (curr == NULL) {
        return;
    }

    list_all_items(curr->left);
    printf("%d %s %.2f %d %s %s\n", curr->code, curr->name, curr->price, curr->stock, curr->date_received, curr->expiration_date);
    list_all_items(curr->right);
}

// Helper function to find the item node with the given code
struct item *find_item(int code) {
    struct item *curr = root;
    while (curr != NULL) {
        if (code < curr->code) {
            curr = curr->left;
        } else if (code > curr->code) {
            curr = curr->right;
        } else {
            return curr;
        }
    }
    return NULL;
}

// Function to delete an item with the given code from the binary search tree
void delete_item(int code) {
    struct item *curr = root;
    struct item *parent = NULL;

    while (curr != NULL && curr->code != code) {
        parent = curr;
    if (code < curr->code) {
        curr = curr->left;
    } else {
        curr = curr->right;
    }
}

if (curr == NULL) {
    printf("Item with code %d does not exist.\n", code);
    return;
}

// Case 1: The item to be deleted has no children
if (curr->left == NULL && curr->right == NULL) {
    if (curr == root) {
        root = NULL;
    } else if (curr == parent->left) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }
    free(curr);
}

// Case 2: The item to be deleted has one child
else if (curr->left == NULL || curr->right == NULL) {
    struct item *child = curr->left == NULL ? curr->right : curr->left;
    if (curr == root) {
        root = child;
    } else if (curr == parent->left) {
        parent->left = child;
    } else {
        parent->right = child;
    }
    free(curr);
}

// Case 3: The item to be deleted has two children
else {
    struct item *successor = curr->right;
    while (successor->left != NULL) {
        successor = successor->left;
    }
    int successor_code = successor->code;
    char successor_name[50];
    float successor_price = successor->price;
    int successor_stock = successor->stock;
    char successor_date_received[11];
    char successor_expiration_date[11];
    strcpy(successor_name, successor->name);
    strcpy(successor_date_received, successor->date_received);
    strcpy(successor_expiration_date, successor->expiration_date);
    delete_item(successor->code);
    curr->code = successor_code;
    strcpy(curr->name, successor_name);
    curr->price = successor_price;
    curr->stock = successor_stock;
    strcpy(curr->date_received, successor_date_received);
    strcpy(curr->expiration_date, successor_expiration_date);
}
}
// Function to delete all expired items from the binary search tree
void delete_expired_items(struct item *curr, struct item *parent) {
if (curr == NULL) {
return;
}
delete_expired_items(curr->left, curr);

if (strcmp(curr->expiration_date, "00/00/0000") != 0) {
    if (curr == root) {
        root = curr->right != NULL ? curr->right : curr->left;
    } else if (curr == parent->left) {
        parent->left = curr->right != NULL ? curr->right : curr->left;
    } else {
        parent->right = curr->right != NULL ? curr->right : curr->left;
    }
    free(curr);
}

delete_expired_items(parent->right, parent);

}
int main() {
// Example usage
insert_item(1, "Apple", 1.50, 10, "05/01/2023", "05/07/2023");
insert_item(2, "Banana", 0.99, 20, "05/01/2023", "05/08/2023");
insert_item(3, "Orange", 0.75, 15, "05/02/2023", "05/10/2023");
insert_item(4, "Grapes", 2.99, 5, "05/03/2023", "05/06/2023");
// List all items
printf("All items:\n");
list_items(root);

// List expired items in Prefix order of their names
printf("Expired items:\n");
list_expired_items(root);

// Delete item with code 2
delete_item(2);

// Delete all expired items
delete_expired_items(root, NULL);

// List all items after deletions
printf("All items after deletions:\n");
list_items(root);

return 0;
}
15. Write a program, using trees, to assign the roll nos. to the students of
your class as per their previous years result. i.e topper will be roll no. 1.
#include <stdio.h>
#include <stdlib.h>

// define a structure for a student node in the binary search tree
struct node {
    int roll_number;
    float previous_year_marks;
    struct node *left_child;
    struct node *right_child;
};

// function to create a new node for a student
struct node *create_node(int roll_number, float previous_year_marks) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->roll_number = roll_number;
    new_node->previous_year_marks = previous_year_marks;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

// function to insert a new student node into the binary search tree
struct node *insert_node(struct node *root, int roll_number, float previous_year_marks) {
    if (root == NULL) {
        return create_node(roll_number, previous_year_marks);
    } else if (previous_year_marks > root->previous_year_marks) {
        root->right_child = insert_node(root->right_child, roll_number, previous_year_marks);
    } else {
        root->left_child = insert_node(root->left_child, roll_number, previous_year_marks);
    }
    return root;
}

// function to assign roll numbers to students in the binary search tree
void assign_roll_numbers(struct node *root, int *roll_number_ptr) {
    if (root == NULL) {
        return;
    }
    assign_roll_numbers(root->left_child, roll_number_ptr);
    root->roll_number = (*roll_number_ptr)++;
    assign_roll_numbers(root->right_child, roll_number_ptr);
}

int main() {
    struct node *root = NULL;
    int num_students;
    int roll_number = 1;

    // get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // get the previous year's marks for each student and insert them into the binary search tree
    for (int i = 0; i < num_students; i++) {
        float marks;
        printf("Enter the previous year's marks for student %d: ", i + 1);
        scanf("%f", &marks);
        root = insert_node(root, 0, marks);
    }

    // assign roll numbers to the students in the binary search tree
    assign_roll_numbers(root, &roll_number);

    // print the roll numbers for each student in the binary search tree
    printf("Roll Numbers:\n");
    for (int i = 0; i < num_students; i++) {
        struct node *current_node = root;
        float marks;
        printf("Student %d: ", i + 1);
        scanf("%f", &marks);
        while (current_node->previous_year_marks != marks) {
            if (marks > current_node->previous_year_marks) {
                current_node = current_node->right_child;
            } else {
                current_node = current_node->left_child;
            }
        }
        printf("%d\n", current_node->roll_number);
    }

    return 0;
}

16. Write a program to efficiently search a particular employee record by
using Tree data structure. Also sort the data on emp­id in ascending
order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an employee record
typedef struct EmployeeRecord {
    int id;
    char name[50];
    struct EmployeeRecord* left;
    struct EmployeeRecord* right;
} EmployeeRecord;

// Function to create a new employee record node
EmployeeRecord* createNode(int id, char* name) {
    EmployeeRecord* node = (EmployeeRecord*) malloc(sizeof(EmployeeRecord));
    node->id = id;
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new employee record node into the binary search tree
EmployeeRecord* insertNode(EmployeeRecord* root, int id, char* name) {
    if (root == NULL) {
        return createNode(id, name);
    }
    if (id < root->id) {
        root->left = insertNode(root->left, id, name);
    } else if (id > root->id) {
        root->right = insertNode(root->right, id, name);
    }
    return root;
}

// Function to search for an employee record by ID
EmployeeRecord* searchNode(EmployeeRecord* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return searchNode(root->left, id);
    }
    return searchNode(root->right, id);
}

// Function to print the binary search tree in ascending order of ID
void printTree(EmployeeRecord* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("Employee ID: %d, Name: %s\n", root->id, root->name);
    printTree(root->right);
}

// Main function to test the binary search tree implementation
int main() {
    EmployeeRecord* root = NULL;

    // Insert some sample employee records
    root = insertNode(root, 102, "John");
    root = insertNode(root, 205, "Jane");
    root = insertNode(root, 311, "Mary");
    root = insertNode(root, 407, "Bob");
    root = insertNode(root, 512, "Alice");

    // Search for an employee record by ID
    int searchId = 311;
    EmployeeRecord* searchResult = searchNode(root, searchId);
    if (searchResult == NULL) {
        printf("Employee record with ID %d not found\n", searchId);
    } else {
        printf("Employee record with ID %d found, Name: %s\n", searchId, searchResult->name);
    }

    // Print the binary search tree in ascending order of ID
    printf("Sorted employee records by ID:\n");
    printTree(root);

    return 0;
}

Advance Trees
1.	Write a Program to create Inorder Threaded Binary Tree and Traverse itin Inorder and Preorder way.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 0;
    return node;
}

// Function to perform Inorder traversal of the Threaded Binary Tree
void inOrder(struct Node* root) {
    struct Node* curr = root;

    while (curr != NULL) {
        // If left child is not NULL, traverse the left subtree
        if (curr->left != NULL)
            curr = curr->left;

        // Print the current node
        printf("%d ", curr->data);

        // If the node is threaded, move to the inorder successor
        if (curr->isThreaded)
            curr = curr->right;
        else {
            // Otherwise, move to the right child
            curr = curr->right;

            // While the left child is not NULL, traverse the left subtree
            while (curr != NULL && curr->left != NULL)
                curr = curr->left;
        }
    }
}

// Function to perform Preorder traversal of the Threaded Binary Tree
void preOrder(struct Node* root) {
    struct Node* curr = root;

    while (curr != NULL) {
        // Print the current node
        printf("%d ", curr->data);

        // If left child is not NULL, traverse the left subtree
        if (curr->left != NULL)
            curr = curr->left;

        // If the node is threaded, move to the inorder successor
        else if (curr->isThreaded)
            curr = curr->right;
        else {
            // Otherwise, move to the right child
            curr = curr->right;

            // While the left child is not NULL, traverse the left subtree
            while (curr != NULL && curr->left != NULL)
                curr = curr->left;
        }
    }
}

// Function to create an Inorder Threaded Binary Tree
void createInorderThreadedBinaryTree(struct Node* root) {
    if (root == NULL)
        return;

    // Initialize previous node as NULL
    struct Node* prev = NULL;

    // Call the function recursively for the left subtree
    if (root->left != NULL)
        createInorderThreadedBinaryTree(root->left);

    // If the left child is NULL, set the left child as the previous node
    if (root->left == NULL)
        root->left = prev;

    // If the previous node is not NULL and its right child is NULL,
    // set the right child as the current node and mark it as threaded
    if (prev != NULL && prev->right == NULL) {
        prev->right = root;
        prev->isThreaded = 1;
    }

    // Set the previous node as the current node
    prev = root;

    // Call the function recursively for the right subtree
    if (root->right != NULL)
        createInorderThreadedBinaryTree(root->right);
}

int main() {
    // Create the Binary Tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Create the Inorder Threaded Binary Tree
    createInorderThreadedBinaryTree(root);

    // Traverse the Inorder Threaded Binary Tree in Inorder way
    printf("Inorder Traversal:\n");
    inOrder(root);
    printf("\n");

    // Traverse the Inorder Threaded Binary Tree in Preorder way
    printf("Preorder Traversal:\n");
    preOrder(root);
    printf("\n");

    return 0;
}

2.Write a Program to create Inorder Threaded Binary Tree and Traverse it
in Inorder and Postorder way.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int is_threaded; // flag to indicate if right pointer is a thread or a child
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->is_threaded = 0;
    return node;
}

void createThreadedBST(struct Node* root, struct Node** prev) {
    if (root == NULL) return;
    createThreadedBST(root->left, prev);
    if (*prev != NULL && (*prev)->right == NULL) {
        (*prev)->right = root;
        (*prev)->is_threaded = 1;
    }
    *prev = root;
    createThreadedBST(root->right, prev);
}

struct Node* leftmost(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

void inorderTraversal(struct Node* root) {
    struct Node* current = leftmost(root);
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->is_threaded)
            current = current->right;
        else
            current = leftmost(current->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = createNode(6);
    root->left = createNode(3);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right = createNode(8);
    root->right->left = createNode(7);
    root->right->right = createNode(10);

    struct Node* prev = NULL;
    createThreadedBST(root, &prev);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

3.Write a Program to implement AVL tree and perform different rotations
on it.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getheight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return getheight(node->left) - getheight(node->right);
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return (newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int balance = getBalance(node);
    //left-left
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
        //right-right
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    //left-right
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //right -left
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void printLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(struct Node* root) {
    int h = getheight(root);
    int i;
    for (i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}


int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
   
   
    printf("Avl Tree Pre-order Traversal: \n");
    preorder(root);
   
    printf("\n\nLevel wise dsiplay \n");
    levelOrder(root);
   
    return 0;
}



**************************************************************************************
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return createNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 10;
    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    printTree(root->left, space);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("AVL tree:\n");
    printTree(root, 0);

    return 0;}
4.Write a Program to create Inorder Threaded Binary Tree and Traverse it
in Postorder and Preorder way.
#include <stdio.h>
#include <stdlib.h>

// Definition of threaded binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 0;
    return node;
}

// Function to create inorder threaded binary tree
struct Node* createInorderThreadedTree(int inorder[], int n) {
    if (n == 0) {
        return NULL;
    }

    // Create root node
    struct Node* root = createNode(inorder[0]);

    // Initialize previous node and set its right pointer to root
    struct Node* prev = NULL;
    if (n > 1) {
        prev = createNode(inorder[1]);
        prev->isThreaded = 1;
        prev->right = root;
    }

    // Traverse the inorder array and create threaded binary tree
    int i = 2;
    struct Node* curr = root;
    while (i < n) {
        if (inorder[i] <= curr->data) {
            // Insert node in left subtree
            struct Node* node = createNode(inorder[i]);
            curr->left = node;
            node->isThreaded = 1;
            node->right = curr;
            curr = node;
            i++;
        } else {
            // Insert node in right subtree
            if (curr->isThreaded) {
                // Update prev's right pointer
                prev->right = createNode(inorder[i]);
                prev->right->isThreaded = 1;
                prev->right->right = curr->right;
                curr->right = prev->right;
            } else {
                curr->right = createNode(inorder[i]);
            }
            prev = curr;
            curr = curr->right;
            i++;
        }
    }
    return root;
}

// Function to traverse inorder threaded binary tree in preorder way
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    if (!root->isThreaded) {
        preorderTraversal(root->left);
    }
    preorderTraversal(root->right);
}

// Function to traverse inorder threaded binary tree in postorder way
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    if (!root->isThreaded) {
        postorderTraversal(root->left);
    }
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Driver code
int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct Node* root = createInorderThreadedTree(inorder, n);

    printf("Preorder traversal:\n");
    preorderTraversal(root);

    printf("\nPostorder traversal:\n");
    postorderTraversal(root);

    return 0;
}




























GRAPHS

1.	Write a Program to accept a graph from user and represent it with
Adjacency Matrix and perform BFS and DFS traversals on it.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void addEdge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

void bfs(int s, int n) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int u, v;
    printf("BFS Traversal: ");
    visited[s] = 1;
    queue[rear++] = s;
    while(front != rear) {
        u = queue[front++];
        printf("%d ", u);
        for(v = 0; v < n; v++) {
            if(adj_matrix[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

void dfs(int u, int n) {
    int v;
    printf("%d ", u);
    visited[u] = 1;
    for(v = 0; v < n; v++) {
        if(adj_matrix[u][v] == 1 && visited[v] == 0) {
            dfs(v, n);
        }
    }
}

int main() {
    int n, e, i, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for(i = 0; i < e; i++) {
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &u);
    bfs(u, n);
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &u);
    printf("DFS Traversal: ");
    dfs(u, n);
    printf("\n");
    return 0;
}

2.Write a Program to implement Prim’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to represent a
Graph.


#include<stdio.h>
#include<stdlib.h>

#define INF 9999999 // Define infinity as a very large number

// Create a structure for a node
struct node {
    int vertex;
    int weight;
    struct node* next;
};

// Create a structure for an adjacency list
struct adj_list {
    struct node* head;
};

// Create a structure for a graph
struct graph {
    int vertices;
    struct adj_list* array;
};

// Create a new node
struct node* new_node(int dest, int weight) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->vertex = dest;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

// Create a new graph with V vertices
struct graph* create_graph(int vertices) {
    struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
    graph->vertices = vertices;
    graph->array = (struct adj_list*) malloc(vertices * sizeof(struct adj_list));
    for (int i = 0; i < vertices; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Add an edge to the graph
void add_edge(struct graph* graph, int src, int dest, int weight) {
    struct node* new_node = new_node(dest, weight);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;
    new_node = new_node(src, weight);
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}

// Find the vertex with minimum key value
int min_key(int key[], int mst_set[], int vertices) {
    int min = INF, min_index;
    for (int v = 0; v < vertices; ++v) {
        if (mst_set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the minimum spanning tree
void print_mst(int parent[], int graph[][100], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; ++i) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Implement Prim's algorithm
void prim_mst(struct graph* graph) {
    int vertices = graph->vertices;
    int key[vertices], parent[vertices], mst_set[vertices];
    for (int i = 0; i < vertices; ++i) {
        key[i] = INF;
        mst_set[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < vertices - 1; ++count) {
        int u = min_key(key, mst_set, vertices);
        mst_set[u] = 1;
        struct node* ptr = graph->array[u].head;
        while (ptr != NULL) {
            int v = ptr->vertex;
            int weight = ptr->weight;
            if (mst_set[v] == 0 && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            ptr = ptr->next;
        }
    }
    print_mst(parent, graph, vertices

// function to implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // to store the parent of each vertex in MST
    int key[V]; // to store the key value of each vertex
    bool mstSet[V]; // to keep track of vertices already included in MST
    
    // initialize key values and mstSet
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    // set the key value of the first vertex as 0 and parent as -1
    key[0] = 0;
    parent[0] = -1;
    
    // iterate over all vertices to construct MST
    for (int count = 0; count < V-1; count++) {
        // find the vertex with minimum key value from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        
        // add the selected vertex to MST
        mstSet[u] = true;
        
        // update the key values and parent of the adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    // print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// driver function
int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    
    primMST(graph);
    
    return 0;
}

3.Write a Program to implement Kruskal’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to represent a
Graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX_EDGES];
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*) a;
    struct Edge* edgeB = (struct Edge*) b;
    return edgeA->weight - edgeB->weight;
}

void kruskalMST(struct Graph* graph) {
    struct Subset* subsets = (struct Subset*) malloc(graph->V * sizeof(struct Subset));
    for (int i = 0; i < graph->V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare);
    
    struct Edge result[graph->V];
    int e = 0;
    int i = 0;
    while (e < graph->V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    return;
}

int main() {
    int V, E;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);
    
    struct Graph* graph = createGraph(V, E);
    
    printf("Enter the edges in the format [source] [destination] [weight]:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
    
    kruskalMST(graph);
    
    return 0;
}


4.Write a Program to implement Dijkstra’s algorithm to find shortest
distance between two nodes of a user defined graph. Use Adjacency List
to represent a graph.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

// node structure for adjacency list
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// graph structure
struct Graph {
    struct AdjListNode* array[MAX_NODES];
    int num_nodes;
};

// create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// create a new graph with n nodes
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_nodes = n;
    int i;
    for (i = 0; i < n; i++)
        graph->array[i] = NULL;
    return graph;
}

// add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // add edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    // add edge from dest to src
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

// find the node with the minimum distance
int minDistance(int dist[], int visited[], int n) {
    int minDist = INT_MAX, minIndex = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// print the shortest distance from src to dest
void printShortestPath(int dist[], int n, int src, int dest) {
    printf("Shortest distance from node %d to node %d is %d\n", src, dest, dist[dest]);

    // print the path from src to dest
    printf("Path: ");
    int i;
    int path[MAX_NODES], count = 0;
    path[count++] = dest;
    int curr = dest;
    while (curr != src) {
        for (i = 0; i < n; i++) {
            struct AdjListNode* node = graph->array[curr];
            while (node != NULL) {
                if (dist[i] + node->weight == dist[curr]) {
                    path[count++] = i;
                    curr = i;
                    break;
                }
                node = node->next;
            }
        }
    }
    for (i = count - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("\n");
}

// calculate the shortest path using Dijkstra's algorithm
void dijkstra(struct Graph* graph, int src, int dest) {
    int dist[MAX_NODES], visited[MAX_NODES];
    int i;
    for (i = 0; i < graph->num_nodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (i = 0); i < graph->num_nodes - 1; i++) {
    int u = minDistance(dist, visited, graph->num_nodes);
    visited[u] = 1;
    struct AdjListNode* node = graph->array[u];
    while (node != NULL) {
        int v = node->dest;
        if (!visited[v] && dist[u] != INT_MAX && dist[u] + node->weight < dist[v]) {
            dist[v] = dist[u] + node->weight;
        }
        node = node->next;
    }
}

printShortestPath(dist, graph->num_nodes, src, dest);

}
// main function to test the implementation
int main() {
int n, e;
printf("Enter the number of nodes in the graph: ");
scanf("%d", &n);
struct Graph* graph = createGraph(n);
printf("Enter the number of edges in the graph: ");
scanf("%d", &e);
printf("Enter the edges and their weights: \n");
int i;
for (i = 0; i < e; i++) {
int src, dest, weight;
scanf("%d %d %d", &src, &dest, &weight);
addEdge(graph, src, dest, weight);
}
int src, dest;
printf("Enter the source node: ");
scanf("%d", &src);
printf("Enter the destination node: ");
scanf("%d", &dest);
dijkstra(graph, src, dest);
return 0;
}

5.Write a Program to accept a graph from user and represent it with
Adjacency List and perform BFS and DFS traversals on it.
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

struct node {
    int vertex;
    struct node* next;
};

struct node* create_node(int v);
void add_edge(struct node* adjacency_list[], int src, int dest);
void print_graph(struct node* adjacency_list[], int n);
void bfs(struct node* adjacency_list[], int start_node, int n);
void dfs(struct node* adjacency_list[], int start_node, int visited[]);

int main() {
    int n, i, j, src, dest, start_node;
    struct node* adjacency_list[MAX_NODES] = { NULL };

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the edges as (source, destination) pairs:\n");
    while (1) {
        printf("Source: ");
        scanf("%d", &src);
        printf("Destination: ");
        scanf("%d", &dest);

        if (src == -1 && dest == -1) {
            break;
        }

        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            printf("Invalid edge! Try again.\n");
            continue;
        }

        add_edge(adjacency_list, src, dest);
    }

    printf("Enter the starting node: ");
    scanf("%d", &start_node);

    printf("Adjacency List:\n");
    print_graph(adjacency_list, n);

    printf("BFS Traversal:\n");
    bfs(adjacency_list, start_node, n);

    printf("DFS Traversal:\n");
    int visited[MAX_NODES] = { 0 };
    dfs(adjacency_list, start_node, visited);

    return 0;
}

struct node* create_node(int v) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

void add_edge(struct node* adjacency_list[], int src, int dest) {
    struct node* new_node = create_node(dest);
    new_node->next = adjacency_list[src];
    adjacency_list[src] = new_node;
}

void print_graph(struct node* adjacency_list[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        struct node* current_node = adjacency_list[i];
        printf("%d: ", i);
        while (current_node != NULL) {
            printf("%d ", current_node->vertex);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

void bfs(struct node* adjacency_list[], int start_node, int n) {
    int visited[MAX_NODES] = { 0 };
    int queue[MAX_NODES], front = 0, rear = 0;
    visited[start_node] = 1;
    queue[rear++] = start_node;

    while (front != rear) {
        int current_node = queue[front++];
        printf("%d ", current_node);

        struct node* temp = adjacency_list[current_node];
        while (temp != NULL) {
            int adj_node = temp->vertex;
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                queue[rear++] = adj_node;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfs(struct node* adjacency_list[], int start_node,

void dfs(struct node* adjacency_list[], int start_node, int visited[]) {
    visited[start_node] = 1;
    printf("%d ", start_node);

    struct node* temp = adjacency_list[start_node];
    while (temp != NULL) {
        int adj_node = temp->vertex;
        if (visited[adj_node] == 0) {
            dfs(adjacency_list, adj_node, visited);
        }
        temp = temp->next;
    }
}

6.Write a Program to implement Kruskal’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency Matrix to
represent a graph.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edge[MAX];
};

struct Subset {
    int parent, rank;
};

struct Graph createGraph(int V, int E) {
    struct Graph graph;
    graph.V = V;
    graph.E = E;
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph graph) {
    int V = graph.V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph.edge, graph.E, sizeof(graph.edge[0]), compare);
    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph.E) {
        struct Edge next_edge = graph.edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("Edges in minimum spanning tree:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost = %d\n", minimumCost);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Graph graph = createGraph(V, E);
    printf("Enter edges and their weights:\n");
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &graph.edge[i].src, &graph.edge[i].dest, &graph.edge[i].weight);
    }
    KruskalMST(graph);
    return 0;
}

7.Write a Program to implement Dijkstra’s algorithm to find shortest
distance between two nodes of a user defined graph. Use Adjacency
Matrix to represent a graph.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX][MAX], int src, int dest, int V) {
    int dist[V];
    int visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Shortest distance between node %d and node %d: %d\n", src, dest, dist[dest]);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    int graph[MAX][MAX];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    printf("Enter edges and their weights:\n");
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }
    int src, dest;
    printf("Enter source node: ");
    scanf("%d", &src);
    printf("Enter destination node: ");
    scanf("%d", &dest);
    dijkstra(graph, src, dest, V);
    return 0;
}

8. Write a Program to implement Prim’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to represent a
graph.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int minKey(int key[], int visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(struct Graph* graph) {
    int parent[MAX];
    int key[MAX];
    int visited[MAX];
    for (int i = 0; i < graph->V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < graph->V - 1; count++) {
        int u = minKey(key, visited, graph->V);
        visited[u] = 1;
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            int weight = pCrawl->weight;
            if (visited[v] == 0 && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            pCrawl = pCrawl->next;
        }
    }
    printMST(parent, graph, graph->V);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges and their weights:\n");
    for (int i = 0; i < E; ++i) {
           int src, dest, weight;
    scanf("%d %d %d", &src, &dest, &weight);
    addEdge(graph, src, dest, weight);
}
primMST(graph);
return 0;
}


9. Write a Program to implement Kruskal’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to represent a
Graph.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int myComp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    int parent[V];
    memset(parent, -1, sizeof(parent));
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }
    printf("Edge \tWeight\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    printf("Enter edges and their weights:\n");
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }
    kruskalMST(graph);
    return 0;
}

10. Write a Program to implement Dijkstra’s algorithm to find shortest
distance between two nodes of a user defined graph. Use Adjacency List
to represent a graph.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;
    if (smallest != idx) {
        struct MinHeapNode* smallestNode = minHeap->array[smallest];
        struct MinHeapNode* idxNode = minHeap->array[idx];
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
}
}
int isEmpty(struct MinHeap* minHeap) {
return minHeap->size == 0;
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
if (isEmpty(minHeap))
return NULL;
struct MinHeapNode* root = minHeap->array[0];
struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
minHeap->array[0] = lastNode;
minHeap->pos[root->v] = minHeap->size - 1;
minHeap->pos[lastNode->v] = 0;
--minHeap->size;
minHeapify(minHeap, 0);
return root;
}
void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
int i = minHeap->pos[v];
minHeap->array[i]->dist = dist;
while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
i = (i - 1) / 2;
}
}
int isInMinHeap(struct MinHeap* minHeap, int v) {
if (minHeap->pos[v] < minHeap->size)
return 1;
return 0;
}
void printPath(int parent[], int j) {
if (parent[j] == -1)
return;
printPath(parent, parent[j]);
printf("%d ", j);
}
void printSolution(int dist[], int n, int parent[], int src, int dest) {
printf("Shortest path from %d to %d is: ", src, dest);
printPath(parent, dest);
printf("%d ", src);
printf("\nShortest distance is: %d\n", dist[dest]);
}
void dijkstra(struct Graph* graph, int src, int dest) {
int V = graph->V;
int dist[V];
int parent[V];
struct MinHeap* minHeap = createMinHeap(V);
for (int v = 0; v < V; ++v) {
dist[v] = INT_MAX;
parent[v] = -1;
minHeap->array[v] = newMinHeapNode(v, dist[v]);
minHeap->pos[v] = v;
}
minHeap->array[src] = newMinHeapNode(src, dist[src]);
minHeap->pos[src] = src;
dist[src] = 0;
decreaseKey(minHeap, src, dist[src]);
minHeap->size = V;
while (!isEmpty(minHeap)) {
struct MinHeapNode* minHeapNode = extractMin(minHeap);
int u = minHeapNode->v;
struct AdjListNode* adjListNode = graph->array[u].head;
while (adjListNode != NULL) {
int v = adjListNode->dest;
if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && adjListNode->weight + dist[u] < dist[v]) {
dist[v] = dist[u] + adjListNode->weight;
parent[v] = u;
decreaseKey(minHeap, v, dist[v]);
}

11.Write a Program to implement Prim’s algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency Matrix to
represent a graph.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // Maximum number of vertices in the graph

int findMinKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primMST(graph);
    return 0;
}













SEARCHING SORTING

WAP to implement Bubble sort and Quick Sort on 1D array of Student
structure (contains student_name, student_roll_no, total_marks), with
key as student_roll_no. And count the number of swap performed.


#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

// Function to swap two Student structures
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort implementation
int bubbleSort(struct Student arr[], int n) {
    int swapCount = 0;
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].student_roll_no > arr[j+1].student_roll_no) {
                swap(&arr[j], &arr[j+1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

// Quick Sort implementation
int partition(struct Student arr[], int low, int high, int *swapCount) {
    int pivot = arr[high].student_roll_no;
    int i = low - 1;
    int j;
    for (j = low; j <= high-1; j++) {
        if (arr[j].student_roll_no < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            (*swapCount)++;
        }
    }
    swap(&arr[i+1], &arr[high]);
    (*swapCount)++;
    return (i + 1);
}

void quickSort(struct Student arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int p = partition(arr, low, high, swapCount);
        quickSort(arr, low, p-1, swapCount);
        quickSort(arr, p+1, high, swapCount);
    }
}

// Function to print the Student array
void printArray(struct Student arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Student Name: %s, Roll No.: %d, Total Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
}

// Driver function
int main() {
    struct Student arr[] = {
        {"John", 3, 85},
        {"Mary", 2, 90},
        {"Peter", 4, 80},
        {"Alice", 1, 95}
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Bubble Sort
    int bubbleSwapCount = bubbleSort(arr, n);
    printf("\nAfter Bubble Sort:\n");
    printArray(arr, n);
    printf("Number of swaps performed: %d\n", bubbleSwapCount);

    // Resetting the array to original order
    swap(&arr[0], &arr[3]);
    swap(&arr[1], &arr[2]);

    // Quick Sort
    int quickSwapCount = 0;
    quickSort(arr, 0, n-1, &quickSwapCount);
    printf("\nAfter Quick Sort:\n");
    printArray(arr, n);
    printf("Number of swaps performed: %d\n", quickSwapCount);

    return 0;
}

 WAP to implement Insertion sort and Merge Sort on 1D array of Student structure (contains student_name, student_roll_no, total_marks), with key as student_roll_no. And count the number of swap performed.
#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

// Function to swap two Student structures
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort implementation
int insertionSort(struct Student arr[], int n) {
    int swapCount = 0;
    int i, j;
    struct Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].student_roll_no > key.student_roll_no) {
            arr[j+1] = arr[j];
            j--;
            swapCount++;
        }

        arr[j+1] = key;
    }
    return swapCount;
}

// Merge Sort implementation
void merge(struct Student arr[], int l, int m, int r, int *swapCount) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct Student L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l+i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*swapCount)++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Student arr[], int l, int r, int *swapCount) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, swapCount);
        mergeSort(arr, m+1, r, swapCount);
        merge(arr, l, m, r, swapCount);
    }
}

// Function to print the Student array
void printArray(struct Student arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Student Name: %s, Roll No.: %d, Total Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
}

// Driver function
int main() {
    struct Student arr[] = {
        {"John", 3, 85},
        {"Mary", 2, 90},
        {"Peter", 4, 80},
        {"Alice", 1, 95}
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Insertion Sort
    int insertionSwapCount = insertionSort(arr, n);
    printf("\nAfter Insertion Sort:\n");
    printArray(arr)


WAP to implement Selection sort and Bucket Sort on 1D array of
Employee structure (contains employee_name, emp_no, emp_salary),
with key as emp_no. And count the number of swap performed
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int emp_no;
    int emp_salary;
};

// Function to swap two Employee structures
void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort implementation
int selectionSort(struct Employee arr[], int n) {
    int swapCount = 0;
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].emp_no < arr[min_idx].emp_no) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            swapCount++;
        }
    }
    return swapCount;
}

// Bucket Sort implementation
void bucketSort(struct Employee arr[], int n, int maxEmpNo, int *swapCount) {
    struct Employee *buckets[maxEmpNo+1];
    int i, j;
    for (i = 0; i <= maxEmpNo; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i].emp_no;
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = (struct Employee*)malloc(sizeof(struct Employee));
            *buckets[bucketIndex] = arr[i];
        } else {
            struct Employee *bucketPtr = buckets[bucketIndex];
            while (bucketPtr->emp_no != bucketIndex && bucketPtr->emp_no != -1) {
                bucketPtr++;
            }
            *bucketPtr = arr[i];
        }
    }

    int index = 0;
    for (i = 0; i <= maxEmpNo; i++) {
        if (buckets[i] != NULL) {
            int bucketSize = sizeof(buckets[i])/sizeof(struct Employee);
            for (j = 0; j < bucketSize; j++) {
                if (buckets[i][j].emp_no != -1) {
                    arr[index++] = buckets[i][j];
                }
            }
            free(buckets[i]);
        }
    }
}

// Function to print the Employee array
void printArray(struct Employee arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Employee Name: %s, Emp No.: %d, Emp Salary: %d\n", arr[i].employee_name, arr[i].emp_no, arr[i].emp_salary);
    }
}

// Driver function
int main() {
    struct Employee arr[] = {
        {"John", 3, 85000},
        {"Mary", 2, 90000},
        {"Peter", 4, 80000},
        {"Alice", 1, 95000}
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Selection Sort
    int selectionSwapCount = selectionSort(arr, n);
    printf("\nAfter Selection Sort:\n");
    printArray(arr, n);

    // Bucket Sort
    int maxEmpNo = arr[n-1].emp_no;
    bucketSort(arr, n, maxEmpNo, &selection



WAP to implement Shell sort and Heap Sort on 1D array of Employee
structure (contains employee_name, emp_no, emp_salary), with key as
emp_no. And count the number of swap performed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int emp_no;
    int emp_salary;
};

// Function to swap two Employee structures
void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

// Shell Sort implementation
int shellSort(struct Employee arr[], int n) {
    int swapCount = 0;
    int gap, i, j;
    struct Employee temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j-gap].emp_no > temp.emp_no; j -= gap) {
                arr[j] = arr[j-gap];
                swapCount++;
            }
            arr[j] = temp;
        }
    }
    return swapCount;
}

// Heap Sort implementation
void heapify(struct Employee arr[], int n, int i, int *swapCount) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l].emp_no > arr[largest].emp_no) {
        largest = l;
    }
    if (r < n && arr[r].emp_no > arr[largest].emp_no) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swapCount)++;
        heapify(arr, n, largest, swapCount);
    }
}

void heapSort(struct Employee arr[], int n, int *swapCount) {
    int i;
    for (i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i, swapCount);
    }
    for (i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        (*swapCount)++;
        heapify(arr, i, 0, swapCount);
    }
}

// Function to print the Employee array
void printArray(struct Employee arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Employee Name: %s, Emp No.: %d, Emp Salary: %d\n", arr[i].employee_name, arr[i].emp_no, arr[i].emp_salary);
    }
}

// Driver function
int main() {
    struct Employee arr[] = {
        {"John", 3, 85000},
        {"Mary", 2, 90000},
        {"Peter", 4, 80000},
        {"Alice", 1, 95000}
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Shell Sort
    int shellSwapCount = shellSort(arr, n);
    printf("\nAfter Shell Sort:\n");
    printArray(arr, n);

    // Heap Sort
    int heapSwapCount = 0;
    heapSort(arr, n, &heapSwapCount);
    printf("\nAfter Heap Sort:\n");
    printArray(arr, n);

    printf("\nNumber of swaps performed in Shell Sort: %d\n", shellSwapCount);
    printf("Number of swaps performed);

WAP to implement Insertion sort and Quick Sort on 1D array of Student structure (contains student_name, student_roll_no, total_marks), with key as student_roll_no. And count the number of swap performed. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

// Function to swap two Student structures
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort implementation
int insertionSort(struct Student arr[], int n) {
    int swapCount = 0;
    int i, j;
    struct Student temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i-1; j >= 0 && arr[j].student_roll_no > temp.student_roll_no; j--) {
            arr[j+1] = arr[j];
            swapCount++;
        }
        arr[j+1] = temp;
    }
    return swapCount;
}

// Quick Sort implementation
int partition(struct Student arr[], int low, int high, int *swapCount) {
    struct Student pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].student_roll_no < pivot.student_roll_no) {
            i++;
            swap(&arr[i], &arr[j]);
            (*swapCount)++;
        }
    }
    swap(&arr[i+1], &arr[high]);
    (*swapCount)++;
    return i+1;
}

void quickSort(struct Student arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi-1, swapCount);
        quickSort(arr, pi+1, high, swapCount);
    }
}

// Function to print the Student array
void printArray(struct Student arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Student Name: %s, Roll No.: %d, Total Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
}

// Driver function
int main() {
    struct Student arr[] = {
        {"John", 3, 85},
        {"Mary", 2, 90},
        {"Peter", 4, 80},
        {"Alice", 1, 95}
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    // Insertion Sort
    int insertionSwapCount = insertionSort(arr, n);
    printf("\nAfter Insertion Sort:\n");
    printArray(arr, n);

    // Quick Sort
    int quickSwapCount = 0;
    quickSort(arr, 0, n-1, &quickSwapCount);
    printf("\nAfter Quick Sort:\n");
    printArray(arr, n);

    printf("\nNumber of swaps performed in Insertion Sort: %d\n", insertionSwapCount);
    printf("Number of swaps performed in Quick Sort: %d\n", quickSwapCount);

    return 0;
}

WAP to implement Selection sort and Merge Sort on 1D array of Student structure (contains student_name, student_roll_no, total_marks), with key as student_roll_no. And count the number of swap performed.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_name;
    int student_roll_no;
    int total_marks;
};

// Selection Sort
int selectionSort(Student arr[], int n) {
    int swap_count = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].student_roll_no < arr[min_idx].student_roll_no) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            swap_count++;
        }
    }
    return swap_count;
}

// Merge Sort
void merge(Student arr[], int left, int mid, int right, int& swap_count) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    Student L[n1], R[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            swap_count += n1 - i;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Student arr[], int left, int right, int& swap_count) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, swap_count);
        mergeSort(arr, mid + 1, right, swap_count);

        // Merge the sorted halves
        merge(arr, left, mid, right, swap_count);
    }
}

int main() {
    Student arr[] = {
        {"Alice", 3, 90},
        {"Bob", 1, 85},
        {"Charlie", 4, 80},
        {"David", 2, 95},
        {"Emily", 5, 75}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Selection Sort
    cout << "Selection Sort: " << endl;
    int selection_swap_count = selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].student_name << ", Roll No: " << arr[i].student_roll_no << ", Total Marks: " << arr[i].total_marks << endl;
    }
    cout <<

Sorting & Searching WAP to implement Bubble sort and Heap Sort on 1D array of Employee structure (contains employee_name, emp_no, emp_salary), with key as emp_no. And count the number of swap performed
orting & Searching WAP to implement Bubble sort and Heap Sort on 1D array of Employee structure (contains employee_name, emp_no, emp_salary), with key as emp_no. And count the number of swap performed

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string employee_name;
    int emp_no;
    int emp_salary;
};

// Bubble Sort
int bubbleSort(Employee arr[], int n) {
    int swap_count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].emp_no > arr[j+1].emp_no) {
                swap(arr[j], arr[j+1]);
                swap_count++;
            }
        }
    }
    return swap_count;
}

// Heap Sort
void heapify(Employee arr[], int n, int i, int& swap_count) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // If left child is larger than root
    if (l < n && arr[l].emp_no > arr[largest].emp_no) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r].emp_no > arr[largest].emp_no) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swap_count++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, swap_count);
    }
}

void heapSort(Employee arr[], int n, int& swap_count) {
    // Build heap (rearrange array)
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swap_count);
    }

    // One by one extract an element from heap
    for (int i = n-1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        swap_count++;

        // call max heapify on the reduced heap
        heapify(arr, i, 0, swap_count);
    }
}

int main() {
    Employee arr[] = {
        {"Alice", 3, 50000},
        {"Bob", 1, 75000},
        {"Charlie", 4, 40000},
        {"David", 2, 90000},
        {"Emily", 5, 60000}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    cout << "Bubble Sort: " << endl;
    int bubble_swap_count = bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].employee_name << ", Emp No: " << arr[i].emp_no << ", Emp Salary: " << arr[i].emp_salary << endl;
    }
    cout << "Number of Swaps: " << bubble_swap_count << endl;

    // Heap Sort
    cout << "Heap Sort: " << endl;
    int heap_swap_count = 0;
    heapSort(arr, n, heap_swap_count);
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].employee_name << ", Emp No: " << arr[i].emp_no << ", Emp Salary: " << arr[i].emp_salary << endl;


WAP to implement Bucket Sort and Quick sort on 1D array of Faculty
structure (contains faculty_name, faculty_ID, subject_codes,
class_names), with key as faculty_ID. And count the number of swap
performed


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID 1000000 // Maximum value of faculty_ID

// Structure to represent a faculty member
struct Faculty {
    char faculty_name[50];
    int faculty_ID;
    char subject_codes[50];
    char class_names[50];
};

// Function to swap two Faculty objects
void swap(struct Faculty* a, struct Faculty* b, int* count) {
    struct Faculty temp = *a;
    *a = *b;
    *b = temp;
    (*count)++;
}

// Function to implement Bucket Sort
void bucketSort(struct Faculty arr[], int n, int* count) {
    // Create buckets
    struct Faculty buckets[MAX_ID];
    memset(buckets, 0, sizeof(buckets));
    
    // Place each Faculty object in the corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i].faculty_ID - 1;
        buckets[bucket_index] = arr[i];
    }
    
    // Copy the sorted Faculty objects back to the original array
    int index = 0;
    for (int i = 0; i < MAX_ID; i++) {
        if (buckets[i].faculty_ID != 0) {
            arr[index++] = buckets[i];
        }
    }
}

// Function to implement Quick Sort
void quickSort(struct Faculty arr[], int low, int high, int* count) {
    if (low < high) {
        int pivot = arr[high].faculty_ID;
        int i = low - 1;
        
        for (int j = low; j <= high - 1; j++) {
            if (arr[j].faculty_ID < pivot) {
                i++;
                swap(&arr[i], &arr[j], count);
            }
        }
        
        swap(&arr[i+1], &arr[high], count);
        
        int partition = i + 1;
        
        quickSort(arr, low, partition - 1, count);
        quickSort(arr, partition + 1, high, count);
    }
}

int main() {
    int n;
    printf("Enter the number of faculty members: ");
    scanf("%d", &n);
    
    // Create an array of Faculty objects
    struct Faculty arr[n];
    
    // Read the input Faculty objects
    for (int i = 0; i < n; i++) {
        printf("Enter details of faculty member %d:\n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].faculty_name);
        printf("ID: ");
        scanf("%d", &arr[i].faculty_ID);
        printf("Subject codes: ");
        scanf("%s", arr[i].subject_codes);
        printf("Class names: ");
        scanf("%s", arr[i].class_names);
    }
    
    // Implement Bucket Sort and count the number of swaps
    int bucket_sort_count = 0;
    bucketSort(arr, n, &bucket_sort_count);
    
    // Implement Quick Sort and count the number of swaps
    int quick_sort_count = 0;
    quickSort(arr, 0, n-1, &quick_sort_count);
    
    // Print the sorted array
    printf("\nBucket Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %s %s\n", arr[i].faculty

WAP to implement Merge Sort and Heap Sort on 1D array of Faculty
structure (contains faculty_name, faculty_ID, subject_codes,
class_names), with key as faculty_ID. And count the number of swap
performed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Faculty structure
struct Faculty {
    char faculty_name[50];
    int faculty_ID;
    char subject_codes[20];
    char class_names[20];
};

// Merge function for Merge Sort
void merge(struct Faculty arr[], int l, int m, int r, int *swap_count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temp arrays
    struct Faculty L[n1], R[n2];
    
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        // Compare and merge
        if (L[i].faculty_ID <= R[j].faculty_ID) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        *swap_count += 1; // Increment swap count
        k++;
    }
    
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void merge_sort(struct Faculty arr[], int l, int r, int *swap_count) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sort first and second halves
        merge_sort(arr, l, m, swap_count);
        merge_sort(arr, m + 1, r, swap_count);
        
        // Merge the sorted halves
        merge(arr, l, m, r, swap_count);
    }
}

// Heapify function for Heap Sort
void heapify(struct Faculty arr[], int n, int i, int *swap_count) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // Left child index
    int r = 2 * i + 2; // Right child index
    
    // If left child is larger than root
    if (l < n && arr[l].faculty_ID > arr[largest].faculty_ID)
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r].faculty_ID > arr[largest].faculty_ID)
        largest = r;
    
    // If largest is not root
    if (largest != i) {
        // Swap arr[i] with arr[largest]
        struct Faculty temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        *swap_count += 1; // Increment swap count
        
        // Recursively heap


You have a fleet of N cars waiting for repair, with the estimated repair
times rk for the car Ci , 1 ? k ? N. What is the best repairschedule (order
of repairs) to minimize the total lost time for being out­of­service. How
much computation is needed to find the lost service­times all schedules?

To minimize the total lost time for being out-of-service, we can use the Shortest Job First (SJF) scheduling algorithm. This algorithm schedules the jobs in ascending order of their estimated repair times.

To find the lost service times for all schedules, we need to calculate the waiting time for each car. The waiting time for a car is the time from when it arrives until it starts being repaired. The total lost service time for all schedules is the sum of the waiting times for all cars.

To calculate the waiting time for a car, we need to know the repair times of all the cars that arrived before it. So, we need to consider all possible permutations of the N cars to find the best repair schedule that minimizes the total lost time for being out-of-service.

The total number of permutations of N cars is N! (N factorial), which is a very large number. Therefore, finding the best repair schedule for a large fleet of cars can be computationally very expensive.

One way to reduce the computational cost is to use a heuristic approach. For example, we can use the nearest neighbor algorithm, which starts with a random car and selects the car with the shortest estimated repair time that has not been scheduled yet. This algorithm may not always give the optimal solution, but it can significantly reduce the computational cost while still producing reasonably good results.
The total lost service time for all schedules is the sum of the waiting times for all cars.

To calculate the waiting time for a car, we need to know the repair times of all the cars that arrived before it. So, we need to consider all possible permutations of the N cars to find the best repair schedule that minimizes the total lost time for being out-of-service.

The total number of permutations of N cars is N! (N factorial), which is a very large number. Therefore, finding the best repair schedule for a large fleet of cars can be computationally very expensive.
One way to reduce the computational cost is to use a heuristic approach. For example, we can use the nearest neighbor algorithm, which starts with a random car and selects the car with the shortest estimated repair time that has not been scheduled yet. This algorithm may not always give the optimal solution, but it can significantly reduce the computational cost while still producing reasonably good results.



Write a program to arrange the data of the faculties recruited in the
institute. There are three categories of faculties in the every deartment
namely professor, Associate professor, and assistant professor.
Recruitment is done as mentioned below. 1. Every professor has two
associate professors. 2. Every Associate has two assistant professors.
Data is given randomly. Suggest suitable sorting method and implement.

#include<stdio.h>
#include<string.h>

struct faculty {
    char name[20];
    char category[20];
    int recruitment_order;
};

void merge(struct faculty arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct faculty L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        strcpy(L[i].name, arr[left + i].name);
        strcpy(L[i].category, arr[left + i].category);
        L[i].recruitment_order = arr[left + i].recruitment_order;
    }

    for (j = 0; j < n2; j++) {
        strcpy(R[j].name, arr[mid + 1 + j].name);
        strcpy(R[j].category, arr[mid + 1 + j].category);
        R[j].recruitment_order = arr[mid + 1 + j].recruitment_order;
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i].category, R[j].category) < 0 || 
            (strcmp(L[i].category, R[j].category) == 0 && L[i].recruitment_order < R[j].recruitment_order)) {
            strcpy(arr[k].name, L[i].name);
            strcpy(arr[k].category, L[i].category);
            arr[k].recruitment_order = L[i].recruitment_order;
            i++;
        }
        else {
            strcpy(arr[k].name, R[j].name);
            strcpy(arr[k].category, R[j].category);
            arr[k].recruitment_order = R[j].recruitment_order;
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k].name, L[i].name);
        strcpy(arr[k].category, L[i].category);
        arr[k].recruitment_order = L[i].recruitment_order;
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k].name, R[j].name);
        strcpy(arr[k].category, R[j].category);
        arr[k].recruitment_order = R[j].recruitment_order;
        j++;
        k++;
    }
}

void mergeSort(struct faculty arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    struct faculty faculties[] = {
        {"John Doe", "associate professor", 3},
        {"Jane Smith", "assistant professor", 2},
        {"Mike Johnson", "professor", 1},
        {"Lisa Brown", "assistant professor", 5},


Assume that an array A with n elements was sorted in an ascending
order, but two of its elements swapped their positions by a mistake while
maintaining the array. Write a code to identify the swapped pair of
elements and their positions in the asymptotically best possible time.
[Assume that all given elements are distinct integers.]
 
#include<stdio.h>

void findSwappedPair(int arr[], int n) {
    int i, j;
    int first = -1, second = -1;

    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            first = i;
            break;
        }
    }

    if (first == -1) {
        printf("The array is already sorted.\n");
        return;
    }

    for (j = first + 1; j < n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            second = j;
            break;
        }
    }

    if (second == -1) {
        second = n - 1;
    }

    printf("The swapped pair is (%d, %d) at positions (%d, %d).\n", arr[first], arr[second], first, second);
}

int main() {
    int arr[] = {1, 3, 5, 4, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSwappedPair(arr, n);

    return 0;
}


Using Quick sort, assign the roll nos. to the students of your class as per Searching their previous years result. i.e. topper will be roll no. 1

#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[50];
    int roll;
    float previous_year_result;
} Student;

void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student arr[], int low, int high) {
    float pivot = arr[high].previous_year_result;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].previous_year_result >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quicksort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = (Student*) malloc(n * sizeof(Student));

    printf("Enter the students' names and previous year's results:\n");

    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the previous year's result of student %d: ", i + 1);
        scanf("%f", &students[i].previous_year_result);

        students[i].roll = i + 1;
    }

    quicksort(students, 0, n - 1);

    printf("The assigned roll numbers are:\n");

    for (int i = 0; i < n; i++) {
        printf("%d. %s (previous year's result: %.2f)\n", i + 1, students[i].name, students[i].previous_year_result);

        if (students[i].previous_year_result == students[0].previous_year_result) {
            printf("The topper is %s with roll number 1.\n", students[i].name);
        }

        students[i].roll = i + 1;
    }

    free(students);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    char name[50];
    float height;
    float weight;
} Employee;

void merge(Employee arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if ((L[i].height + L[i].weight) / 2 >= (R[j].height + R[j].weight) / 2) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee* employees = (Employee*) malloc(n * sizeof(Employee));

    printf("Enter the employees' names, heights, and weights:\n");

    for (int i = 0; i < n; i++) {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", employees[i].name);

        printf("Enter the height of employee %d (in meters): ", i + 1);
        scanf("%f", &employees[i].height);

        printf("Enter the weight of employee %d (in kilograms): ", i + 1);
        scanf("%f", &employees[i].weight);
    }

    mergesort(employees, 0, n - 1);

    printf("The arranged list of employees based on the average of their height and weight is:\n");

    for (int i = 0; i < n; i++) {
        printf("%d. %s (average of height and weight: %.2f)\n", i + 1, employees[i].name, (employees[i].height + employees[i].weight) / 2);
    }

    free(employees);

    return 0;
}


Given a set of points Pi , 1 ? i ? N (? 2) on the x ­axis, find Pi and P j
such that |Pi ? P j | is minimum. e.g. P1 | P2 | P3 | P4 | P5 | P6 {P4 , P6}
is the closest pair

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

int cmp_x(const void* a, const void* b) {
    Point* p1 = (Point*) a;
    Point* p2 = (Point*) b;
    if (p1->x < p2->x) return -1;
    if (p1->x > p2->x) return 1;
    return 0;
}

int cmp_y(const void* a, const void* b) {
    Point* p1 = (Point*) a;
    Point* p2 = (Point*) b;
    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return 0;
}

double dist(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double brute_force(Point* points, int n) {
    double min_dist = INFINITY;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double d = dist(points[i], points[j]);
            if (d < min_dist) {
                min_dist = d;
            }
        }
    }
    return min_dist;
}

double closest_pair(Point* points, Point* temp, int left, int right) {
    if (right - left <= 3) {
        return brute_force(points + left, right - left);
    }
    int mid = (left + right) / 2;
    double d1 = closest_pair(points, temp, left, mid);
    double d2 = closest_pair(points, temp, mid, right);
    double d = fmin(d1, d2);
    int k = 0;
    for (int i = left; i < right; i++) {
        if (fabs(points[i].x - points[mid].x) < d) {
            temp[k++] = points[i];
        }
    }
    qsort(temp, k, sizeof(Point), cmp_y);
    for (int i = 0; i < k-1; i++) {
        for (int j = i+1; j < k && temp[j].y - temp[i].y < d; j++) {
            double dij = dist(temp[i], temp[j]);
            if (dij < d) {
                d = dij;
            }
        }
    }
    return d;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    Point* points = malloc(n * sizeof(Point));
    Point* temp = malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        printf("Enter x and y coordinates of point %d: ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    qsort(points, n, sizeof(Point), cmp_x);
    double d = closest_pair


WAP to search a particular students record in 'n' number of students pool by using Binary search with and without recursive function. Assume suitable data for student record. 


#include <stdio.h>

// Define a struct for a student record
struct student {
    int roll_no;
    char name[50];
    float marks;
};

// Binary search function without recursion
int binary_search(struct student students[], int n, int roll_no) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (students[mid].roll_no == roll_no) {
            return mid;
        } else if (students[mid].roll_no < roll_no) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Binary search function with recursion
int binary_search_recursive(struct student students[], int low, int high, int roll_no) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (students[mid].roll_no == roll_no) {
        return mid;
    } else if (students[mid].roll_no < roll_no) {
        return binary_search_recursive(students, mid + 1, high, roll_no);
    } else {
        return binary_search_recursive(students, low, mid - 1, roll_no);
    }
}

int main() {
    int n, roll_no, index;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of student records
    struct student students[n];

    // Populate the array with student records
    for (int i = 0; i < n; i++) {
        printf("Enter the details for student %d:\n", i + 1);
        printf("Roll no: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Prompt the user to enter the roll no to search for
    printf("Enter the roll no to search for: ");
    scanf("%d", &roll_no);

    // Perform binary search using the non-recursive function
    index = binary_search(students, n, roll_no);
    if (index != -1) {
        printf("Student found:\n");
        printf("Roll no: %d\n", students[index].roll_no);
        printf("Name: %s\n", students[index].name);
        printf("Marks: %.2f\n", students[index].marks);
    } else {
        printf("Student not found.\n");
    }

    // Perform binary search using the recursive function
    index = binary_search_recursive(students, 0, n - 1, roll_no);
    if (index != -1) {
        printf("Student found:\n");
        printf("Roll no: %d\n", students[index].roll_no);
        printf("Name: %s\n", students[index].name);
        printf("Marks: %.2f\n", students[index].marks);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}



WAP to perform addition o f two polynomials using singly linked list

#include <stdio.h>
#include <stdlib.h>
struct Node {
   int coef;
   int exp;
   struct Node* next;
};
typedef struct Node Node;
void insert(Node** poly, int coef, int exp) {
   Node* temp = (Node*) malloc(sizeof(Node));
   temp->coef = coef;
   temp->exp = exp;
   temp->next = NULL;
  
   if (*poly == NULL) {
       *poly = temp;
       return;
   }
  
   Node* current = *poly;
  
   while (current->next != NULL) {
       current = current->next;
   }
  
   current->next = temp;
}
void print(Node* poly) {
   if (poly == NULL) {
       printf("0\n");
       return;
   }
  
   Node* current = poly;
  
   while (current != NULL) {
       printf("%dx^%d", current->coef, current->exp);
       if (current->next != NULL) {
           printf(" + ");
       }
       current = current->next;
   }
  
   printf("\n");
}
Node* add(Node* poly1, Node* poly2) {
   Node* result = NULL;
  
   while (poly1 != NULL && poly2 != NULL) {
       if (poly1->exp == poly2->exp) {
           insert(&result, poly1->coef + poly2->coef, poly1->exp);
           poly1 = poly1->next;
           poly2 = poly2->next;
       } else if (poly1->exp > poly2->exp) {
           insert(&result, poly1->coef, poly1->exp);
           poly1 = poly1->next;
       } else {
           insert(&result, poly2->coef, poly2->exp);
           poly2 = poly2->next;
       }
   }
  
   while (poly1 != NULL) {
       insert(&result, poly1->coef, poly1->exp);
       poly1 = poly1->next;
   }
  
   while (poly2 != NULL) {
       insert(&result, poly2->coef, poly2->exp);
       poly2 = poly2->next;
   }
  
   return result;
}
int main() {
   Node* poly1 = NULL;
   insert(&poly1, 5, 4);
   insert(&poly1, 3, 2);
   insert(&poly1, 1, 0);
   Node* poly2 = NULL;
   insert(&poly2, 4, 4);
   insert(&poly2, 2, 2);
   insert(&poly2, 1, 1);
   printf("First polynomial: ");
   print(poly1);
   printf("Second polynomial: ");
   print(poly2);
   Node* result = add(poly1, poly2);
   printf("Result: ");
   print(result);
   return 0;
}




WAP to perform Multiplication o f two polynomials using singly linked i


#include<stdio.h>	
	#include<stdlib.h>
	
	struct node
	{
	int coefficient,exponent;
	struct node *next;
	};
	
	struct node *hPtr1,*hPtr2,*hPtr3;
	

	struct node *buildNode(int coefficient, int exponent)
	{
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->coefficient=coefficient;
	ptr->exponent=exponent;
	ptr->next=NULL;
	return ptr;
	}
	

	void polynomial_insert(struct node ** myNode,int coefficient,int exponent)
	{
	struct node *lPtr,*pPtr,*qPtr=*myNode;
	lPtr=buildNode(coefficient,exponent);
	if (*myNode==NULL || (*myNode)->exponent<exponent)
	{
	 *myNode=lPtr;
	 (*myNode)->next=qPtr;
	 return;
	}
	while(qPtr)
	{
	 pPtr=qPtr;
	 qPtr=qPtr->next;
	 if(!qPtr)
	 {
	  pPtr->next=lPtr;
	  break;
	 }
	 else if((exponent<pPtr->exponent) && (exponent>qPtr->exponent))
	 {
	  lPtr->next = qPtr;
	  pPtr->next = lPtr;
	  break;
	 }
	}
	return;
	}  
	

	void polynomial_add(struct node **n1,int coefficient,int exponent)
	{
	struct node *x=NULL,*temp=*n1;
	if (*n1==NULL || (*n1)->exponent<exponent)
	{
	 *n1=x=buildNode(coefficient,exponent);
	 (*n1)->next=temp;
	}
	else
	{
	 while(temp)
	 {
	  if(temp->exponent==exponent)
	  {
	   temp->coefficient=temp->coefficient+coefficient;
	   return;
	  }
	  if(temp->exponent>exponent && (!temp->next || temp->next->exponent<exponent))
	  {
	   x=buildNode(coefficient,exponent);
	   x->next=temp->next;
	   temp->next=x;
	   return;
	  }
	  temp=temp->next;
	 }
	 x->next=NULL;
	 temp->next=x;
	}
	}
	 
	void polynomial_multiply(struct node **n1,struct node *n2,struct node *n3)
	{
	struct node * temp;
	int coefficient, exponent;
	temp = n3;
	if(!n2 && !n3)
	{
	 return;
	}
	if(!n2)
	{
	 *n1 = n3;
	}
	else if(!n3)
	{
	 *n1 = n2;
	}
	else
	{
	 while(n2)
	 {
	  while(n3)
	  {
	   coefficient = n2->coefficient * n3->coefficient;
	   exponent = n2->exponent + n3->exponent;
	   n3 = n3->next;
	   polynomial_add(n1, coefficient, exponent);
	  }
	  n3 = temp;
	  n2 = n2->next;
	 }
	}
	return;
	}
	

	struct node *polynomial_deleteList(struct node *ptr)
	{
	struct node *temp;
	while(ptr)
	{
	 temp=ptr->next;
	 free(ptr);
	 ptr = temp;
	}
	return NULL;
	}
	 
	void polynomial_view(struct node *ptr)
	{
	int i = 0;
	int flag=0;
	while (ptr)
	{
	 if(ptr->exponent!=0 || ptr->exponent!= 1)
	 {
	  if(ptr->coefficient>0 && flag==0)
	  {
	   printf("%dx^%d", ptr->coefficient,ptr->exponent);
	   flag++;
	  }
	  else if(ptr->coefficient>0 && flag==1)
	  {
	   printf("+%dx^%d", ptr->coefficient,ptr->exponent);
	  }
	  else if(ptr->coefficient<0)
	  {
	   printf("%dx^%d",ptr->coefficient,ptr->exponent);
	  }
	 }
	 else if(ptr->exponent==0)
	 {
	  if(ptr->coefficient>0 && flag==0 )
	  {
	   printf("%d",ptr->coefficient);
	     flag++;
	  }
	  else if(ptr->coefficient>0 && flag==1)
	  {
	   printf("+%d", ptr->coefficient);
	  }
	  else if(ptr->coefficient < 0)
	  {
	   printf("%d", ptr->coefficient);
	  }
	 }
	 else if(ptr->exponent==1)
	 {
	  if(ptr->coefficient>0 && flag==0)
	  {
	   printf("%dx",ptr->coefficient);
	   flag++;
	  }
	  else if(ptr->coefficient > 0 && flag==1)
	  {
	   printf("+%dx", ptr->coefficient);
	  }
	  else if(ptr->coefficient < 0)
	  {
	   printf("%dx", ptr->coefficient);
	  }
	 }
	 ptr=ptr->next;
	 i++;
	}
	printf("\n");
	return;
	}
	 
	int main(int argc,char *argv[])
	{
	int coefficient,exponent,i,n;
	int count;
	printf("Multiplication of Two Polynomials\n");
	printf("Enter the number of coefficients in the multiplicand:");
	scanf("%d",&count);
	for(i=0;i<count;i++)
	{
	 printf("Enter the coefficient part:");
	 scanf("%d", &coefficient);
	 printf("Enter the exponent part:");
	 scanf("%d",&exponent);
	 polynomial_insert(&hPtr1, coefficient, exponent);
	}
	printf("Enter the number of coefficients in the multiplier:");
	scanf("%d",&count);
	for(i=0;i<count;i++)
	{
	 printf("Enter the coefficient part:");
	 scanf("%d", &coefficient);
	 printf("Enter the exponent part:");
	 scanf("%d",&exponent);
	 polynomial_insert(&hPtr2, coefficient, exponent);
	}
	printf("Polynomial Expression 1: ");
	polynomial_view(hPtr1);
	printf("Polynomial Expression 2: ");
	polynomial_view(hPtr2);
	polynomial_multiply(&hPtr3, hPtr1, hPtr2);
	printf("Output:\n");
	polynomial_view(hPtr3);
	hPtr1 = polynomial_deleteList(hPtr1);
	hPtr2 = polynomial_deleteList(hPtr2);
	hPtr3 = polynomial_deleteList(hPtr3);
	return 0;
	}

WAP to st
ore at most 10 digit integer in a Doubly linked list and perform arithmetic operations on it.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the node in the doubly linked list
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the doubly linked list
void insert(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
}

// Function to delete a node from the doubly linked list
void delete(Node** headRef, Node* nodeToDelete) {
    if (*headRef == NULL || nodeToDelete == NULL) {
        return;
    }
    if (*headRef == nodeToDelete) {
        *headRef = nodeToDelete->next;
    }
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }
    free(nodeToDelete);
}

// Function to delete the entire doubly linked list
void deleteList(Node** headRef) {
    Node* current = *headRef;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

// Function to display the contents of the doubly linked list
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to add two numbers stored in the doubly linked list
Node* add(Node* num1, Node* num2) {
    Node* result = NULL;
    Node* current1 = num1;
    Node* current2 = num2;
    int carry = 0;
    while (current1 != NULL || current2 != NULL) {
        int sum = carry;
        if (current1 != NULL) {
            sum += current1->data;
            current1 = current1->next;
        }
        if (current2 != NULL) {
            sum += current2->data;
            current2 = current2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        insert(&result, sum);
    }
    if (carry > 0) {
        insert(&result, carry);
    }
    return result;
}

// Function to subtract two numbers stored in the doubly linked list
Node* subtract(Node* num1, Node* num2) {
    Node* result = NULL;
    Node* current1 = num1;
    Node* current2 = num2;
    int borrow = 0;
    while (current1 != NULL || current2 != NULL) {
        int diff = borrow;
        if (current1 != NULL) {
            diff += current1->data;
            current1 = current1->next;
        }
        if (current2 != NULL) {
            diff

WAP to convert a given Infix expression into its equivalent prefix Postfix
expression and evaluate it using stack.


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

tbt - threaded binary tree
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int lbit;
    int rbit;
};

struct node * createNode(int data) {
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lbit = 0;
    newNode->rbit = 0;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    struct node *newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
    } else {
        struct node *current = root;
        while (1) {
            if (data < current->data){
                if (current->lbit == 0) { 
                    newNode->left = current->left; 
                    newNode->right = current;  
                    current->left = newNode;
                    current->lbit = 1;
                    break;
                } 
                else {
                    current = current->left;  
                }
            } 
            else {
                if (current->rbit == 0) {
                    newNode->right = current->right;
                    newNode->left = current;
                    current->right = newNode;
                    current->rbit = 1;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    return root;
}

struct node *inorderSuccessor(struct node *current) {
    if (current->rbit == 0) {
        return current->right;
    } else {
        current = current->right;
        while (current->lbit == 1) {
            current = current->left;
        }
        return current;
    }
}

void inorderTraversal(struct node *root) {
    struct node *current = root;
    while (current->lbit == 1) {
        current = current->left;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = inorderSuccessor(current);
    }
    printf("\n");
}
void preorder(struct node * root){
    struct node * temp = root;
    while(temp != NULL){
        printf("%d ", temp->data);
        if(temp->lbit == 1){
            temp = temp->left;
        }
        else if(temp->rbit == 1){
            temp = temp->right;
        }
        else{
            while(temp != NULL && temp->rbit == 0){
                temp = temp->right;
            }
            if(temp != NULL){
                temp = temp->right;
            }
        }
    }
    printf("\n");
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf ("Inorder traversal ");
    inorderTraversal(root);
    printf("\nPreorder traversal ");
    preorder(root);
    return 0;
}

string concatenate
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

queue opt
// #include <stdio.h>
// #include <stdlib.h>

// struct queue{
//     int f;
//     int r;
//     int size;
//     int *arr;
// };
// int full(struct queue *q){
//     if(q->r == q->size-1){
//         return 1;
//     }
//     return 0;
// }
// int empty(struct queue *q){
//     if(q->f==q->r){
//         return 1;
//     }
//     return 0;
// }
// void enqueue(struct queue *q,int data){
//     if(full(q)){
//         printf("can't enqueue");
//     }
//     else{
//     q->r++;
//     q->arr[q->r]=data;
// }
// }
// int dequeue(struct queue *q,int data){
//     int a=-1;
//     if(empty(q)){
//         printf("can't dequeue");
//     }
//     else{
//     q->f++;
//     a=q->arr[q->f];
// }
// return a;
// }
// void display(struct queue *q){
//     for(int i=q->f+1;i<=q->r;i++){
//         printf("%d\n",q->arr[i]);
//     }
// }
// int main(){
//     struct queue q;
//     q.size = 100;
//     q.f = q.r = -1;
//     q.arr = (int *)malloc(q.size*sizeof(int));
//     enqueue(&q,12);
//     enqueue(&q,15);
//     display(&q);
//     dequeue(&q,12);
//     dequeue(&q,15);
// }

#include <stdio.h>
#include <stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
int full(struct queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int empty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q,int val){
    if(full(q)){
        printf("can't enqueue");
    }
    else{
    q->r=(q->r+1)%q->size;
    q->arr[q->r]=val;
    printf("enqueued element %d\n",val);
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(empty(q)){
        printf("can't dequeue");
    }
    else{
    q->f=(q->f+1)%q->size;
    a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
    return 0;
}

queue using twostack
#include <stdio.h>
#include<stdlib.h>

#define N 100			// size for arrays representing stack1 and stack2
int stack1[N], stack2[N];	// array representing stacks of size N
int top_stack1 = -1;		// top for stack1
int top_stack2 = -1;		// top for stack2
int count = 0;			// For keeping the count of element present in queue
void push_stack1 (int data)
{
  if (top_stack1 == N - 1)
    {
      printf ("Stack1 is overflow");
      return;
    }
  else
    {
      top_stack1++;
      stack1[top_stack1] = data;
    }
  return;
}

void push_stack2 (int data)
{
  if (top_stack2 == N - 1)
    {
      printf ("Stack2 is overflow");
      return;
    }
  else
    {
      top_stack2++;
      stack2[top_stack2] = data;
    }
  return;
}

int pop_stack1 ()
{
  if (top_stack1 == -1)
    {
      printf ("Stack1 is underflow\n");
      return -1;
    }
  return stack1[top_stack1--];
}

int pop_stack2 ()
{
  if (top_stack2 == -1)
    {
      printf ("Stack2 is underflow\n");
      return -1;
    }
  return stack2[top_stack2--];
}

void enqueue (int data)
{
  push_stack1 (data);
  count++;

}

void dequeue ()
{
  if (top_stack1 == -1 && top_stack2 == -1)
    printf ("Queue is empty\n");
  else
    {
      for (int i = 0; i < count; i++)
	{
	  int temp = pop_stack1 ();
	  push_stack2 (temp);
	}
      int x = pop_stack2 ();
      printf ("Dequeued element is %d\n", x);
      count--;
      for (int i = 0; i < count; i++)
	{
	  int temp = pop_stack2 ();
	  push_stack1 (temp);

	}
    }
}

void display ()
{
  if (top_stack1 == -1)
    {
      printf ("Queue is empty \n");
      return;
    }
  for (int i = 0; i < top_stack1; i++)
    printf ("%d ", stack1[i]);
  printf ("\n");

}

void top ()
{
  printf ("Top element of queue is %d ", stack1[0]);
}

int main ()
{
  enqueue (3);
  enqueue (45);
  enqueue (-1);
  display ();
  dequeue ();
  display ();
  return 0;

}

prims matrix
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // number of vertices in the graph

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) { //checks if the vertex v is not already included in the MST and if the key value of the vertex v is less than the current minimum key value 
            min = key[v]; //key[v] minimum weight edge
            min_index = v;
        }
    }
    return min_index; //min_index is a variable that holds the index of the vertex with the smallest key value that is not yet included in the Minimum Spanning Tree (MST).
}

void primMST(int graph[V][V]) {
    int parent[V]; // array to store the MST
    int key[V]; // minimum key value for each vertex weight
    bool mstSet[V]; // set to store the vertices in the MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V-1; count++) { //Loop through the remaining vertices in the graph, since the first vertex has already been added to the MST.
        int u = minKey(key, mstSet); // Find the vertex with the minimum key value among the vertices not yet in the MST, and assign it to u
        mstSet[u] = true; // Mark u as part of the MST by setting its value in the mstSet array to true.

        for (int v = 0; v < V; v++) { 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) { //there is an edge between u and v, v is not already in the MST, and the weight of the edge is less than the minimum key value of v. If all these conditions are met, then update the parent of v to u, and update its key value to the weight of the edge.
                parent[v] = u;
                key[v] = graph[u][v]; //Set the minimum key value of v to the weight of the edge connecting u and v.
            }
        }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) // Loop through all the vertices in the MST, starting from the second vertex (i = 1), since the parent of the first vertex is -1 and it is not part of the MST.
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primMST(graph);
    return 0;
}

krushkals matrix
#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main()
{

    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j]; //This nested for loop iterates through all possible edges in the graph and finds the one with the minimum weight. It also sets the variables a and b to the vertices that the minimum weight edge connects.
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost + = min;
        }

        cost[a][b] = cost[b][a] = 999;//sets the weight of the edge between a and b to a large value (999) to indicate that it has already been processed and should not be considered again.
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

josephous problem
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue * next;
    struct Queue * front, * rear;
};

struct Queue * getQueuenode(int data){
    struct Queue * newnode = (struct Queue *)malloc(sizeof(struct Queue));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Queue * createQueue(){
    struct Queue * queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue * queue,int data){
    struct Queue * newnode = getQueuenode(data);
    if (queue->rear!=NULL)
    {
        queue->rear->next = newnode;
        queue->rear = newnode;
        return;
    }
    queue->front = queue->rear = newnode;
}

int dequeue(struct Queue * queue){
    if(queue->front == NULL){
        return -1;
    }
    struct Queue * temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

int joseph(int n, int k){
    struct Queue * queue = createQueue();
    for(int i=1; i<=n; i++){
        enqueue(queue,i);
    }
    while(queue->front!=queue->rear){
         for(int i=1; i<k; i++){
            enqueue(queue,dequeue(queue));
    }
    dequeue(queue);
  }
  int lastperson = dequeue(queue);
  free(queue);
  return lastperson;
}

int main() {
    int n, k;
    printf("Enter the total number of people: ");
    scanf("%d", &n);
    printf("Enter the elimination pattern: ");
    scanf("%d", &k);

    int lastperson = joseph(n, k);
    printf("The last person standing is: %d", lastperson);

    return 0;
}

bfs dfs list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//QUEUE OPERATIONS
int queue[100];
int rear=-1;
int front=0;
int queue_count=0;
void enqueue(int data){
    queue[++rear]=data;
    queue_count++;

}
int dequeue(){
    queue_count--;
    return queue[front++];
}

bool isqueueEmpty(){
    return queue_count>0 ? false:true;
}

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

struct Node* insert(struct Node* head, int data){
    if(head == NULL){
        head = create(data);
        return head;
    }
    struct Node* temp = create(data);
    temp->next = head;
    return temp;
}

void print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void BFS(int node, struct Node* G[], int visited[]){
    if(visited[node] == 0){
        visited[node] = 1;
        enqueue(node);
        while(!isqueueEmpty()){
            int val = dequeue();
            printf("%d ", val);
            struct Node* temp = G[val];
            while(temp != NULL){
                int i = temp->data;
                if(visited[i]==0){
                    enqueue(i);
                    visited[i] = 1;
                }
                temp = temp->next;
            }
        }
    }
}

void DFS(int node, struct Node* G[], int visited[]){
    if(visited[node] == 0){
        visited[node] = 1;
        printf("%d ", node);
        struct Node* temp = G[node];
        while(temp != NULL){
            int i = temp->data;
            if(visited[i]==0){
                DFS(i, G, visited);
            }
            temp = temp->next;
        }
    }
}

int main(){
    int n;
    printf("How many nodes are present ?\n");
    scanf("%d", &n);
    int visited[n];
    struct Node* G[n];
    for(int i = 0; i<n; ++i){
        printf("How many edges connected to node %d - ", i);
        int edges;
        scanf("%d", &edges);
        G[i] =  NULL;
        for(int j=0; j<edges; ++j){
            printf("Edge %d -> (0 - %d) - ", i, n-1);
            int e;
            scanf("%d", &e);
            G[i] = insert(G[i], e);
        }
        visited[i] = 0;
    }
    for(int i=0; i<n; ++i){
        printf("%d -> [ ", i);
        print(G[i]);
        printf("]\n");
    }
    for(int i=0; i<n; ++i){
        // DFS(i, G, visited);
        BFS(i, G, visited);
    }
    return 0;
}

bfs dfs matrix
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue
#define MAX_STACK_SIZE 100
int no_vertices;
void printgraph(int adj[][no_vertices]);

// Breadth First Search function
void BFS(int adj[][no_vertices], int start_vertex) {
    bool visited[no_vertices]; // array to keep track of visited vertices
    for(int i = 0; i < no_vertices; i++) {
        visited[i] = false; // mark all vertices as unvisited initially
    }

    // create a queue to store the vertices
    int queue[MAX_QUEUE_SIZE];
    int front = -1, rear = -1;
    queue[++rear] = start_vertex;
    visited[start_vertex] = true;

    printf("\nBFS traversal starting from vertex %d: ", start_vertex);

    while (front != rear) { // while the queue is not empty
        int current_vertex = queue[++front];  //This line dequeues the next vertex from the queue, by incrementing the front pointer and retrieving the element at that position in the queue.
        printf("%d ", current_vertex);  //This line prints the value of the current vertex that was just dequeued.

        // add all unvisited neighbors of the current vertex to the queue
        for(int i = 0; i < no_vertices; i++) {
            if(adj[current_vertex][i] == 1 && !visited[i]) {  //This line checks if the current vertex has an edge connecting it to the vertex at index i, and whether that vertex has been visited already or not. If both conditions are met, the vertex at index i is added to the end of the queue, and marked as visited.
                queue[++rear] = i;   //This line adds the vertex at index i to the end of the queue, by incrementing the rear pointer and setting the element at that position in the queue to the value of i.
                visited[i] = true;   //This line marks the vertex at index i as visited, to avoid revisiting it again later.
            } 
        }
    }
}


// Depth First Search function
void DFS(int adj[][no_vertices], int start_vertex) {
    bool visited[no_vertices]; // array to keep track of visited vertices
    for(int i = 0; i < no_vertices; i++) {
        visited[i] = false; // mark all vertices as unvisited initially
    }

    // create a stack to store the vertices
    int stack[MAX_STACK_SIZE];
    int top = -1;
    stack[++top] = start_vertex;
    visited[start_vertex] = true;

    printf("\nDFS traversal starting from vertex %d: ", start_vertex);

    while (top != -1) { // while the stack is not empty
        int current_vertex = stack[top--];  //This line pops the top vertex from the stack, by retrieving the element at the top position and decrementing the top pointer.
        printf("%d ", current_vertex);  //This line prints the value of the current vertex that was just popped.

        // add all unvisited neighbors of the current vertex to the stack
        for(int i = 0; i < no_vertices; i++) {
            if(adj[current_vertex][i] == 1 && !visited[i]) {  //This line checks if the current vertex has an edge connecting it to the vertex at index i, and whether that vertex has been visited already or not. If both conditions are met, the vertex at index i is pushed onto the stack, and marked as visited.
                stack[++top] = i;   //This line pushes the vertex at index i onto the stack, by incrementing the top pointer and setting the element at that position in the stack to the value of i.
                visited[i] = true;   //This line marks the vertex at index i as visited, to avoid revisiting it again later.
            } 
        }
    }
}
// function to print the adjacency matrix
void printgraph(int adj[][no_vertices]){
    printf("\nThe adjacency matrix of the graph is:\n");
    for(int i=0;i<no_vertices;i++){
        for(int j=0;j<no_vertices;j++){
            printf(" %d ",adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int source = 0, destination = 0;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];

    for(int i=0; i<no_vertices; i++)
        for(int j=0; j<no_vertices; j++)
            adj[i][j] = 0; // initialize adjacency matrix to 0

    // take input of edges
    while (source!=-1 && destination!=-1) {
        printf("Enter an edge from node(0 to %d) to node(0 to %d) : ",no_vertices-1,no_vertices-1);
        scanf("%d%d",&source,&destination);
        if(source!=-1 && destination!=-1){
            adj[source][destination] = 1;
            adj[destination][source] = 1; //graph is undirected, meaning that the edge can be traversed in both directions
        }
    }
    printgraph(adj); // print the adjacency matrix

    int start_vertex;
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);
    BFS(adj, start_vertex); // call BFS function with start vertex
    DFS(adj, start_vertex);
    return 0;
}

dijsktras list
#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

// Graph structure for adjacency list
struct Graph {
    int V; // number of vertices
    struct Node* adjList;
};

// Create a new node in the adjacency list
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Create a graph using adjacency list
struct Graph createGraph(int V) {
    struct Graph graph;
    graph.V = V;
    graph.adjList = (struct Node*)malloc(V * sizeof(struct Node));
    for (int i = 0; i < V; i++) {
        graph.adjList[i].next = NULL;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src].next;
    graph->adjList[src].next = newNode;
}

void main(){
    int n,v,p,src,dest,weight,min,index=1,i,j;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);

    // Create graph using adjacency list
    struct Graph graph = createGraph(n);

    printf("Enter the edges and their weights: ");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&src,&dest,&weight);
        addEdge(&graph,src,dest,weight);
    }

    printf("Enter the node to visit: ");
    scanf("%d",&v);

    printf("Enter the no of paths for the selected node: ");
    scanf("%d",&p);

    int path[p][n];

    printf("Enter the paths for the selected node: ");
    for(int i=0;i<p;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&path[i][j]);
        }
    }

    int distance[p];
    for(int i=0;i<p;i++){
        distance[i] = 0;
        int row = 1;
        for(int j=0;j<n-1;j++){
            if(row!=v){
                int column = path[i][j+1];
                struct Node* curr = graph.adjList + row;
                while(curr->next!=NULL){
                    curr = curr->next;
                    if(curr->dest==column){
                        distance[i] = distance[i] + curr->weight;
                        break;
                    }
                }
            }
            row = column;
        }
    }

    min=distance[0];
    for(i=1;i<p;i++){
        if(distance[i]<=min){
            min=distance[i];
            index=i;
        }
    }
    printf("min distance is %d\n",min);
    printf("min distance path is\n");
    for(i=0;i<n-1;i++){
        if(path[index][i]!=0){
            printf("--->%d",path[index][i]);
        }
    }
}

dijsktras matrix
#include <stdio.h>
#include <stdlib.h>

void main(){
    int cost[10][10],distance[10],path[10][10],n,v,p,row,column,min,index=1,i,j;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);

    printf("Enter the cost matrix: ");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("Enter the node to visit: ");
    scanf("%d",&v);

    printf("Enter the paths for the selected node: ");
    scanf("%d",&p);

    printf("Enter the path matrix: ");
    for(int i=1;i<=p;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&path[i][j]);
        }
    }

    for(int i=1;i<=p;i++){
        distance[i]=0;
        row=1;
        for(int j=1;j<n;j++){
            if(row!=v){
                column = path[i][j+1];
                distance[i] = distance[i]+cost[row][column];
            }
            row=column;
        }
    }

    min=distance[1];
    for(i=1;i<=p;i++){
        if(distance[i]<=min){
            min=distance[i];
            index=i;
        }
    }
    printf("min distance is %d\n",min);
    printf("min distance path is\n");
    for(i=1;i<n;i++){
        if(path[index][i]!=0){
            printf("--->%d",path[index][i]);
        }
    }
}
/*
0 4 0 8 0
4 0 3 0 0
0 3 0 4 0
8 0 4 0 7
0 0 0 7 0

1 2 3 4 5
1 4 5 0 0
*/