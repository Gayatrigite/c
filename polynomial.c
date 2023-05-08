//Polynimial operations using linked list addition subtraction multiplication

#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node * next;
};

struct node * insert(struct node * head,int co,int ex){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p;
    ptr->coeff = co;    //newnode coeff
    ptr->expo = ex;    //newnode expo
    ptr->next = NULL;

    if(head == NULL || ex > head->expo){
        ptr->next = head;
        head = ptr;
    }
    else{
        p = head;
        while (p->next != NULL && p->next->expo >= ex)
        {
            if(p->next->expo == ex){
                p->next->coeff = p->next->coeff + co;
                return head;
            }
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}

struct node * add_poly(struct node * poly1,struct node * poly2){
    struct node * result = NULL;
    struct node * ptr1 = poly1;
    struct node * ptr2 = poly2;

    if(ptr1->expo > ptr2->expo){
        result = insert(result,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->next;
    }
    else if(ptr2->expo > ptr1->expo){
        result = insert(result,ptr2->coeff,ptr2->expo);
    }
    else{
        int sum = ptr1->coeff + ptr2->coeff;
        result = insert(result,sum,ptr1->expo);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL) {
        result = insert(result, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        result = insert(result, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }

    return result;
}

struct node * sub_poly(struct node * poly1,struct node * poly2){
    struct node * result1 = NULL;
    struct node * ptr1 = poly1;
    struct node * ptr2 = poly2;

    if(ptr1->expo > ptr2->expo){
        result1 = insert(result1,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->next;
    }
    else if(ptr2->expo > ptr1->expo){
        result1 = insert(result1,ptr2->coeff,ptr2->expo);
    }
    else{
        int sub = ptr1->coeff - ptr2->coeff;
        result1 = insert(result1,sub,ptr1->expo);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL) {
        result1 = insert(result1, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        result1 = insert(result1, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }

    return result1;
}
struct node * mul_poly(struct node* poly1,struct node* poly2){
	struct node* ptr1=poly1;
	struct node* ptr2=poly2;
    int res1,res2;
	struct node* result2=NULL;
	while(ptr1!=NULL){
		ptr2=poly2;
		while(ptr2!=NULL){
			res1=ptr1->coeff*ptr2->coeff;
			res2=ptr1->expo+ptr2->expo;
			result2=insert(result2,res1,res2);
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	return result2;
}

void print_poly(struct node * poly){
    struct node * ptr = poly;
    while(ptr != NULL){
        printf("%dX^%d", ptr->coeff, ptr->expo);
        if (ptr->next != NULL) {
            printf(" + ");
        }
        ptr = ptr->next;
    }
    printf("\n");
    }

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    poly1 = insert(poly1, 3, 2);
    poly1 = insert(poly1, 4, 1);
    poly1 = insert(poly1, 2, 0);
    printf("First polynomial: ");
    print_poly(poly1);

    poly2 = insert(poly2, 2, 2);
    poly2 = insert(poly2, -3, 1);
    poly2 = insert(poly2, 5, 0);
    printf("Second polynomial: ");
    print_poly(poly2);

    struct node* result = add_poly(poly1, poly2);
    struct node* result1 = sub_poly(poly1, poly2);
    struct node* result2 = mul_poly(poly1, poly2);
    printf("Resultant polynomial: ");
    print_poly(result);
    print_poly(result1);
    print_poly(result2);

    return 0;
}

