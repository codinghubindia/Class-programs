#include<stdio.h>
#include<stdlib.h>

struct node {
    int num;
    struct node *link;
};

void printRev(struct node *head) {
    if(head == NULL) return;

    printRev(head->link);
    printf("%d\t", head->num);
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
    printf("In reverse Order: ");
    printRev(head);
    freeNodes(head);
}