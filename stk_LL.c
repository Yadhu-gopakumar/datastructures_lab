#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void dsply();
void search();
typedef struct node
{
    int data;
    struct node *next;
} node;
struct node *start;
int main()
{
    int ch;
    do
    {
        printf("\n-----------------------------");
        printf("\n\tMENU");
        printf("\n\t----");
        printf("\n\t1.PUSH");
        printf("\n\t2.POP");
        printf("\n\t3.DISPLAY");
        printf("\n\t4.SEARCH");
        printf("\n\t5.EXIT");
        printf("\nenter your option\n:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            dsply();
            break;
        }
        case 4:
        {
            search();
            break;
        }
        case 5:
        {
            printf("EXIT..");
            break;
        }
        default:
            printf("\ninvalid option..\n");
        }
    } while (ch != 5);

    return 0;
}

void search()
{

    node *ptr = NULL;

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

void push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVRFLOW..");
    }
    else
    {
        printf("enter value to push:");
        scanf("%d", &val);
        if (start == NULL)
        {
            ptr->data = val;
            ptr->next = NULL;
            start = ptr;
        }
        else
        {
            ptr->data = val;
            ptr->next = start;
            start = ptr;
        }
        printf("\nItem pushed to stack");
    }
}
void pop()
{
    int item;
    struct node *ptr;
    if (start == NULL)
    {
        printf("underflow..");
    }
    else
    {
        item = start->data;
        ptr = start;
        start = start->next;
        free(ptr);
        printf("\n%d popped", item);
    }
}
void dsply()
{
    int i;
    struct node *ptr;
    ptr = start;
    if (ptr == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        printf("\tSTACK\n\t************\n");
        while (ptr != NULL)
        {
            printf(" %d |", ptr->data);
            ptr = ptr->next;
        }
    }
}
