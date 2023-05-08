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

// struct node * mul_poly(struct node * poly1,struct node * poly2){
//     struct node * result2 = NULL;
//     struct node * ptr1 = poly1;
//     struct node * ptr2 = poly2;

//     if(ptr1->expo > ptr2->expo){
//         result2 = insert(result2,ptr1->coeff,ptr1->expo);
//         ptr1 = ptr1->next;
//     }
//     else if(ptr2->expo > ptr1->expo){
//         result2 = insert(result2,ptr2->coeff,ptr2->expo);
//     }
//     else{
//         int mul = ptr1->coeff * ptr2->coeff;
//         result2 = insert(result2,mul,ptr1->expo);
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next;
//     }
//     while (ptr1 != NULL) {
//         result2 = insert(result2, ptr1->coeff, ptr1->expo);
//         ptr1 = ptr1->next;
//     }

//     while (ptr2 != NULL) {
//         result2 = insert(result2, ptr2->coeff, ptr2->expo);
//         ptr2 = ptr2->next;
//     }

//     return result2;
// }

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


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     int coef;
//     int exp;
//     struct Node* next;
// } Node;

// Node* createNode(int coef, int exp) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->coef = coef;
//     newNode->exp = exp;
//     newNode->next = NULL;
//     return newNode;
// }

// Node* addPolynomials(Node* poly1, Node* poly2) {
//     Node* result = NULL;
//     Node* temp = NULL;
//     Node* prev = NULL;

//     while(poly1 != NULL && poly2 != NULL) {
//         if(poly1->exp == poly2->exp) {
//             int sum = poly1->coef + poly2->coef;
//             if(sum != 0) {
//                 temp = createNode(sum, poly1->exp);
//                 if(result == NULL) {
//                     result = temp;
//                 } else {
//                     prev->next = temp;
//                 }
//                 prev = temp;
//             }
//             poly1 = poly1->next;
//             poly2 = poly2->next;
//         } else if(poly1->exp > poly2->exp) {
//             temp = createNode(poly1->coef, poly1->exp);
//             if(result == NULL) {
//                 result = temp;
//             } else {
//                 prev->next = temp;
//             }
//             prev = temp;
//             poly1 = poly1->next;
//         } else {
//             temp = createNode(poly2->coef, poly2->exp);
//             if(result == NULL) {
//                 result = temp;
//             } else {
//                 prev->next = temp;
//             }
//             prev = temp;
//             poly2 = poly2->next;
//         }
//     }

//     while(poly1 != NULL) {
//         temp = createNode(poly1->coef, poly1->exp);
//         if(result == NULL) {
//             result = temp;
//         } else {
//             prev->next = temp;
//         }
//         prev = temp;
//         poly1 = poly1->next;
//     }

//     while(poly2 != NULL) {
//         temp = createNode(poly2->coef, poly2->exp);
//         if(result == NULL) {
//             result = temp;
//         } else {
//             prev->next = temp;
//         }
//         prev = temp;
//         poly2 = poly2->next;
//     }

//     return result;
// }

// Node* subtractPolynomials(Node* poly1, Node* poly2) {
//     Node* result = NULL;
//     Node* temp = NULL;
//     Node* prev = NULL;

//     while(poly1 != NULL && poly2 != NULL) {
//         if(poly1->exp == poly2->exp) {
//             int diff = poly1->coef - poly2->coef;
//             if(diff != 0) {
//                 temp = createNode(diff, poly1->exp);
//                 if(result == NULL) {
//                     result = temp;
//                 } else {
//                     prev->next = temp;
//                 }
//                 prev = temp;
//             }
//             poly1 = poly1->next;
//             poly2 = poly2->next;
//         } else if(poly1->exp > poly2->exp) {
//             temp = createNode(poly1->coef, poly1->exp);
//             if(result == NULL) {
//                 result = temp;
//             } else {
//                 prev->next = temp;
//             }
//             prev = temp;
//             poly1 = poly1->next;
//         } else {
//             temp = createNode(-poly2->coef, poly2->exp);
//             if(result == NULL) {
//                 result = temp;
//             } else
// {
// prev->next = temp;
// }
// prev = temp;
// poly2 = poly2->next;
// }
// }
// while(poly1 != NULL) {
//     temp = createNode(poly1->coef, poly1->exp);
//     if(result == NULL) {
//         result = temp;
//     } else {
//         prev->next = temp;
//     }
//     prev = temp;
//     poly1 = poly1->next;
// }

// while(poly2 != NULL) {
//     temp = createNode(-poly2->coef, poly2->exp);
//     if(result == NULL) {
//         result = temp;
//     } else {
//         prev->next = temp;
//     }
//     prev = temp;
//     poly2 = poly2->next;
// }

// return result;
// }

// Node* multiplyPolynomials(Node* poly1, Node* poly2) {
//     Node* result = NULL;
//     Node* temp = NULL;
//     Node* prev = NULL;

//     while(poly1 != NULL) {
//         Node* temp2 = poly2;
//         while(temp2 != NULL) {
//             int coef = poly1->coef * temp2->coef;
//             int exp = poly1->exp + temp2->exp;

//             // Find the term in the result polynomial with the same exponent
//             prev = NULL;
//             temp = result;
//             while(temp != NULL && temp->exp >= exp) {
//                 if(temp->exp == exp) {
//                     break;
//                 }
//                 prev = temp;
//                 temp = temp->next;
//             }

//             // If a term with the same exponent exists, add the coefficients
//             if(temp != NULL && temp->exp == exp) {
//                 temp->coef += coef;
//             } else { // Otherwise, insert the new term in the correct position
//                 temp = createNode(coef, exp);
//                 if(prev == NULL) {
//                     temp->next = result;
//                     result = temp;
//                 } else {
//                     temp->next = prev->next;
//                     prev->next = temp;
//                 }
//             }

//             temp2 = temp2->next;
//         }
//         poly1 = poly1->next;
//     }

//     return result;
// }



// void printPolynomial(Node* poly) {
// while(poly != NULL) {
// printf("%dx^%d", poly->coef, poly->exp);
// poly = poly->next;
// if(poly != NULL) {
// printf(" + ");
// }
// }
// printf("\n");
// }

// int main() {
// // Example usage
// Node* poly1 = createNode(5, 2);
// poly1->next = createNode(-2, 1);
// poly1->next->next = createNode(3, 0);
// printf("Polynomial 1: ");
// printPolynomial(poly1);

// Node* poly2 = createNode(6, 1);
// poly2->next = createNode(-4, 0);
// printf("Polynomial 2: ");
// printPolynomial(poly2);

// Node* sum = addPolynomials(poly1, poly2);
// printf("Sum: ");
// printPolynomial(sum);

// Node* diff = subtractPolynomials(poly1, poly2);
// printf("Difference: ");
// printPolynomial(diff);

// Node* prod = multiplyPolynomials(poly1, poly2);
// printf("Product: ");
// printPolynomial(prod);

// return 0;
// }