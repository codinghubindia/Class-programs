#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *link;
};

struct node* createNode(int coeff, int exp) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;
    return newNode;
}

void getPolynomial(struct node **head) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient and exponent):\n");

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        printf("Enter the term (coefficient and exponent):\n");
        scanf("%d %d", &coeff, &exp);
        struct node *newNode = createNode(coeff, exp);
        
        if (*head == NULL || (*head)->exp > exp) {
            newNode->link = *head;
            *head = newNode;
        } else {
            struct node *temp = *head;
            while (temp->link != NULL && temp->link->exp <= exp) {
                temp = temp->link;
            }
            if (temp->exp == exp) {
                temp->coeff += coeff;
                free(newNode);
            } else {
                newNode->link = temp->link;
                temp->link = newNode;
            }
        }
    }
}

struct node* addPolynomials(struct node *poly1, struct node *poly2) {
    struct node *result = NULL;

    while (poly1 || poly2) {
        int coeff = 0, exp;
        if (!poly1) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->link;
        } else if (!poly2) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->link;
        } else if (poly1->exp > poly2->exp) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->link;
        } else if (poly1->exp < poly2->exp) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->link;
        } else {
            coeff = poly1->coeff + poly2->coeff;
            exp = poly1->exp;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        
        if (coeff != 0) {
            struct node* newNode = createNode(coeff, exp);
            newNode->link = result;
            result = newNode;
        }
    }
    
    return result;
}

void printPolynomial(struct node *head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->link;
        if (head) printf(" + ");
    }
    printf("\n");
}

void freeNodes(struct node *head) {
    while (head) {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    struct node *poly1 = NULL, *poly2 = NULL;
    
    printf("Enter first polynomial:\n");
    getPolynomial(&poly1);
    
    printf("Enter second polynomial:\n");
    getPolynomial(&poly2);
    
    struct node *result = addPolynomials(poly1, poly2);
    
    printf("Resultant Polynomial: ");
    printPolynomial(result);
    
    freeNodes(poly1);
    freeNodes(poly2);
    freeNodes(result);
    
    return 0;
}
