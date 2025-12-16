#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int f = -1, r = -1;
int queue[MAX];

void Insert(int ele) {
    if (r == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (f == -1) f = 0;
        queue[++r] = ele;

    }
}

void pop() {
    if (f == -1 || f > r) {
        printf("Queue Underflow!\n");
    } else {
        int deleted = queue[f++];
        printf(" %d is poped\n", deleted);
        if (f > r) {

            f = r = -1;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty!\n");
    } else {

        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {

        printf("1. Insert\n2. pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                Insert(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Thank you");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
