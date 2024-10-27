#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} node;

struct node *start;
void insertBeginning();
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
    start = NULL;
    printf("number of nodes :");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("enter data %d:", i);
        scanf("%d", &new->data);
        if (start == NULL)
        {
            new->next = NULL;
            start = new;
        }
        else
        {
            new->next = start;
            start = new;
        }
    }
    printf("created \n");
}

void search()
{

    struct node *ptr = NULL;

    if (start == NULL)
    {
        printf("stack is empty:");
    }
    else
    {
        int el, pos = 1, flag = 0;
        printf("enter value to search:");
        scanf("%d", &el);
        ptr = start;
        while (ptr != NULL)
        {
            if (ptr->data == el)
            {
                printf("%d found at position %d", el, pos);
                flag = 1;
                break;
            }
            pos += 1;
            ptr = ptr->next;
        }
        if (flag == 0)
        {
            printf("element not found!\n");
        }
    }
}

void insertBeginning(int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        ptr->data = data;
        ptr->next = NULL;
        start = ptr;
    }
    else
    {
        ptr->data = data;
        ptr->next = start;
        start = ptr;
    }
    printf("\nItem inserted at begining");
}
void insertEnd(int data)
{
    if (start == NULL)
    {
        insertBeginning(data);
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        struct node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new->data = data;
        ptr->next = new;
        new->next = NULL;
    }
}
void insertAtPosition(int data, int pos)
{
    // Check for invalid position
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1 || start == NULL)
    {
        insertBeginning(data);
        printf("inserted");
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
    ptr->next = newNode;
    printf("inserted");
}

void deleteBeginning()
{
    if (start == NULL)
    {
        printf("list is empty..");
    }
    else
    {
        struct node *ptr = start;
        start = start->next;
        printf("%d deleted", ptr->data);
        free(ptr);
    }
}
void deleteEnd()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return; // Exit if the list is empty
    }

    if (start->next == NULL)
    {
        // Only one node
        printf("%d deleted\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    struct node *ptr = start;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }

    printf("%d deleted\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
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
    struct node *preptr = NULL;
    int i = 1;
    while (ptr != NULL && i < pos)
    {
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    printf("%d deleted\n", ptr->data);
    preptr->next = ptr->next;
    free(ptr);
}

void display()
{

    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {

        struct node *temp = start;
        printf("linked list \n************\n");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
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
        printf("9. Exit\n");
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
            if (start == NULL)
            {
                printf("list is empty");
                break;
            }
            else
            {
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            }

        case 8:
            printf("Linked List: ");
            display();
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
