#include<stdio.h>
#include<stdlib.h>

struct node {
    int num;
    struct node *link;
};

void printEvenIndex(struct node *head) {
    int index = 0;
    while (head != NULL) {
        if (index % 2 == 0)
            printf("%d\t", head->num);
        head = head->link;
        index++;
    }
}

void getData(struct node **head) {
    int n;
    printf("Enter the Number of Elements: ");
    scanf("%d", &n);
    printf("Enter the Elements\n");

    for (int i = 0; i < n; i++) {
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        scanf("%d", &newNode->num);
        newNode->link = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            struct node *temp = *head;
            while (temp->link != NULL) temp = temp->link;
            temp->link = newNode;
        }
    }
}

void freeNodes(struct node *head) {
    while (head != NULL) {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    getData(&head);
    printf("Elements at even index: ");
    printEvenIndex(head);
    freeNodes(head);
}