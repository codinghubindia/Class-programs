#include<stdio.h>
#include<stdlib.h>

struct node {
    int num;
    struct node *link;
};

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d\t", head->num);
        head = head->link;
    }
    printf("\n");
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

void concatenate(struct node **head1, struct node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct node *temp = *head1;
        while (temp->link != NULL) temp = temp->link;
        temp->link = head2;
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
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter data for the first linked list:\n");
    getData(&head1);

    printf("Enter data for the second linked list:\n");
    getData(&head2);

    concatenate(&head1, head2);

    printf("Concatenated list: ");
    printList(head1);

    freeNodes(head1);

    return 0;
}
