#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *tail = NULL;

void insertBeginning(int data);
void insertEnd(int data);
void insertAtPosition(int data, int position);
void deleteBeginning();
void deleteEnd();
void deleteAtPosition(int pos);
void display();
void search();
void create();

void create()
{
    int n;
    printf("Number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data %d: ", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        newNode->prev = NULL;

        if (start == NULL)
        {

            start = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
    }
    printf("List created.\n");
}

void search()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int el, pos = 1, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &el);

    struct node *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data == el)
        {
            printf("%d found at position %d.\n", el, pos);
            found = 1;
            break;
        }
        pos++;
        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Element not found!\n");
    }
}

void insertBeginning(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = start;
    newNode->prev = NULL;

    if (start != NULL)
    {
        start->prev = newNode;
    }
    start = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }

    printf("Item inserted at beginning.\n");
}

void insertEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (start == NULL)
    {

        newNode->prev = NULL;
        start = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    printf("Item inserted at end.\n");
}

void insertAtPosition(int data, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning(data);
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    struct node *ptr = start;
    int index = 1;

    while (ptr != NULL && index < pos - 1)
    {
        ptr = ptr->next;
        index++;
    }

    if (ptr == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
    newNode->prev = ptr;

    if (newNode->next == NULL)
    {

        tail = newNode;
    }

    printf("Item inserted at position %d.\n", pos);
}

void deleteBeginning()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = start;
    start = start->next;
    if (start != NULL)
    {
        start->prev = NULL;
    }
    else
    {

        tail = NULL;
    }

    printf("%d deleted from the beginning.\n", ptr->data);
    free(ptr);
}

void deleteEnd()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (start->next == NULL)
    {

        printf("%d deleted from the end.\n", start->data);
        free(start);
        start = NULL;
        tail = NULL;
        return;
    }

    struct node *ptr = tail;
    tail = tail->prev;
    if (tail != NULL)
    {
        tail->next = NULL;
    }

    printf("%d deleted from the end.\n", ptr->data);
    free(ptr);
}

void deleteAtPosition(int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    struct node *ptr = start;
    int index = 1;

    while (ptr != NULL && index < pos)
    {
        ptr = ptr->next;
        index++;
    }

    if (ptr == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("%d deleted from position %d.\n", ptr->data, pos);

    if (ptr->prev != NULL)
    {
        ptr->prev->next = ptr->next;
    }
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
}

void display()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = start;
    printf("Forward traversal: NULL -> ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Reverse traversal
    printf("Reverse traversal: NULL -> ");
    temp = tail; // Start from the tail
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\n---------------\n Menu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Display List\n");
        printf("9. Search Element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertBeginning(data);
            break;
        case 3:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertEnd(data);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(data, pos);
            break;
        case 5:
            deleteBeginning();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 8:
            display();
            break;
        case 9:
            search();
            break;
        case 10:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
