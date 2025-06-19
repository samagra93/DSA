#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (!poly) {
        return newNode;
    }
    struct Node* temp = poly;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return poly;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* sum = NULL;
    struct Node* temp = NULL;
    
    while (poly1 && poly2) {
        struct Node* newNode;

        if (poly1->exp > poly2->exp) {
            newNode = createNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            newNode = createNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            newNode = createNode(poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (!sum) {
            sum = newNode;
            temp = sum;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    while (poly1) {
        struct Node* newNode = createNode(poly1->coeff, poly1->exp);
        temp->next = newNode;
        temp = newNode;
        poly1 = poly1->next;
    }

    while (poly2) {
        struct Node* newNode = createNode(poly2->coeff, poly2->exp);
        temp->next = newNode;
        temp = newNode;
        poly2 = poly2->next;
    }
    return sum;
}

void printPoly(struct Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    
    poly1 = insertNode(poly1, 5, 2);
    poly1 = insertNode(poly1, 4, 1);
    poly1 = insertNode(poly1, 2, 0);

    poly2 = insertNode(poly2, 5, 1);
    poly2 = insertNode(poly2, 5, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);
    printf("Polynomial 2: ");
    printPoly(poly2);
    
    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Final Sum: ");
    printPoly(sum);

    return 0;
}
