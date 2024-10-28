#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *link;
};

struct node* createNode(int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->num = num;
    newNode->link = NULL;
    return newNode;
}

struct node* getData() {
    int n, val;
    struct node *head = NULL, *tail = NULL;
    printf("Enter the Number of Elements: ");
    scanf("%d", &n);
    printf("Enter the Elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct node *newNode = createNode(val);
        if (!head) head = tail = newNode;
        else tail = tail->link = newNode;
    }
    return head;
}

struct node* mergeLists(struct node *head1, struct node *head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    struct node *mergedHead = NULL, **tail = &mergedHead;

    while (head1 && head2) {
        if (head1->num < head2->num) {
            *tail = head1;
            head1 = head1->link;
        } else {
            *tail = head2;
            head2 = head2->link;
        }
        tail = &(*tail)->link;
    }
    *tail = head1 ? head1 : head2;
    return mergedHead;
}

void sortList(struct node *head) {
    if (!head) return;

    struct node *temp1, *temp2;
    int temp;

    for (temp1 = head; temp1 != NULL; temp1 = temp1->link) {
        for (temp2 = temp1->link; temp2 != NULL; temp2 = temp2->link) {
            if (temp1->num > temp2->num) {
                // Swap values
                temp = temp1->num;
                temp1->num = temp2->num;
                temp2->num = temp;
            }
        }
    }
}

void printList(struct node *head) {
    while (head) {
        printf("%d\t", head->num);
        head = head->link;
    }
    printf("\n");
}

void freeNodes(struct node *head) {
    struct node *temp;
    while (head) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    printf("Enter data for the first linked list:\n");
    struct node *head1 = getData();

    printf("Enter data for the second linked list:\n");
    struct node *head2 = getData();

    struct node *mergedHead = mergeLists(head1, head2);

    sortList(mergedHead);

    printf("Sorted merged list: ");
    printList(mergedHead);

    freeNodes(mergedHead);

    return 0;
}
