#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;
int size = 0, maxsize;

void enque();
void deque();
void display();

void enque()
{
    if (size == maxsize)
    {
        printf("Queue is full\n");
    }
    else
    {
        node *new = (node *)malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &new->data);
        new->next = NULL;

        if (front == NULL) // First node
        {
            front = rear = new;
            rear->next = front; // Circular link
        }
        else
        {
            rear->next = new;
            rear = new;
            rear->next = front; // Maintain circular link
        }
        size++;
        printf("-- Value inserted\n");
        display();
    }
}

void deque()
{
    if (size == 0)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear) // Only one node
    {
        free(front);
        front = rear = NULL;
        size = 0;
        printf("-- Deleted last element\n");
    }
    else
    {
        node *temp = front;
        front = front->next;
        rear->next = front; // Maintain circular link
        free(temp);
        size--;
        printf("-- Deleted element\n");
    }
    display();
}

void display()
{
    if (size == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *ptr = front;
        printf("Queue elements: ");
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != front); // Stop when we loop back to the front
        printf("(back to front)\n");
    }
}

int main()
{
    int ch;
    printf("Enter max size of the queue: ");
    scanf("%d", &maxsize);
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}
