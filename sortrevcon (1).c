#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;


void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void display(struct Node *head) {
    if (head == NULL) {
        printf("List Empty!\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;
    if (head == NULL) return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


void concatenate() {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert in List1\n2. Insert in List2\n3. Display List1\n4. Display List2\n");
        printf("5. Sort List1\n6. Reverse List1\n7. Concatenate Lists\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&head1, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&head2, val);
                break;
            case 3:
                display(head1);
                break;
            case 4:
                display(head2);
                break;
            case 5:
                sortList(head1);
                printf("List Sorted!\n");
                break;
            case 6:
                head1 = reverseList(head1);
                printf("List Reversed!\n");
                break;
            case 7:
                concatenate();
                printf("Concatenated! Updated List1: ");
                display(head1);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
}
