#include<stdio.h>
#include<stdlib.h>

struct node {
    int num;
    struct node *link;
};

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void printPrime(struct node *head) {
    struct node *temp;
    temp = head;
    printf("Prime Numbers: ");
    while(temp != NULL) {
        if(isPrime(temp->num)){
            printf("%d\t", temp->num);
        }
        temp = temp->link;
    }
    printf("\n");
    return;
}

void getData(struct node **head) {
    int n;
    struct node *newNode;
    struct node *temp;
    printf("Enter the Number of Elements: ");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    for(int i = 0; i < n; i++) {
        newNode = (struct node*) malloc(sizeof(struct node));
        scanf("%d", &newNode->num);
        newNode->link = NULL;
        if(*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while(temp->link != NULL) temp = temp->link;
            temp->link = newNode;
        }
    }
}

void freeNodes(struct node *head) {
    struct node *temp1, *temp2;
    temp1 = head;
    while(temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->link;
        free(temp2);
    }
    return;    
}


int main() {
    struct node *head = NULL;
    getData(&head);
    printPrime(head);
    freeNodes(head);
    return 0;
}