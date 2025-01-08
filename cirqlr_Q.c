#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

int enqueue(int data) {
    // Check for queue overflow
    if ((rear + 1) % MAX == front) {
        printf("\nOverflow: Queue is full\n");
        return 0;
    }

    // If queue is initially empty
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        // Increment rear in a circular manner
        rear = (rear + 1) % MAX;
    }

    queue[rear] = data;
    printf("\nAdded => %d\n", data);
    return 1;
}

int dequeue() {
    if (front == -1) {
        printf("\nUnderflow: Queue is empty\n");
        return 0;
    }

    int value = queue[front];

    // If there's only one element in the queue
    if (front == rear) {
        front = rear = -1;
    } else {
        // Increment front in a circular manner
        front = (front + 1) % MAX;
    }

    printf("\nDeleted => %d\n", value);
    return value;
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nThe latest queue: ");
    int i = front;
    while (1) {
        printf("[%d] ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int data, choice;

    do {
        printf("--------------------------------");
        printf("\n\tCIRCULAR QUEUE\n\t--------------");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nSelect operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("\nInvalid operation\n");
        }
    } while (choice != 4);

    return 0;
}
