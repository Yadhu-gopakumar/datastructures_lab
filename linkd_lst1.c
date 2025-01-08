#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *top = NULL;
int count = 1;

int empty()
{
    if (top == NULL)
    {
        printf("list is empty");
        return 1;
    }
    else
    {
        return 0;
    }
}
void show()
{
    if (!empty())
    {
        node *temp = top;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void insertbeg()
{

    printf("enter elemnt to insert begining");
    node *new = (node *)malloc(sizeof(node));
    scanf("%d", &new->data);
    new->next = NULL;
    if (top == NULL)
    {
        top = new;
    }
    else
    {
        new->next = top;
        top = new;
    }
    count += 1;
    show();
}

void insertpos(int pos)
{
    printf("enter elemnt to insert at %d",pos);
    node *new = (node *)malloc(sizeof(node));
    scanf("%d", &new->data);
    new->next = NULL;
    node *temp = top;
    node *pre = NULL;
    int poss = 1;
    while (temp != NULL)
    {
        if (poss == pos)
        {
            break;
        }
        pre = temp;
        temp = temp->next;
        poss += 1;
    }
    pre->next = new;
    new->next = temp;
    count += 1;

    show();
}
void deletebeg()
{
    if (!empty())
    {

        printf("%d remeoved from beg", top->data);
        node *temp = top;
        top = top->next;
        free(temp);
        count-=1;

        show();
    }
}
void deletepos(int pos)
{
    if (!empty())
    {
        node *temp = top;
        node *pre = NULL;
        int p=1;
        while (temp != NULL)
        {   if(p==pos){break;}
            pre = temp;
            temp = temp->next;
            p+=1;
        }
        
        printf("%d remeoved from list:", temp->data);
        if(pos!=count){
            pre->next=temp->next;
        }
        else{
        pre->next = NULL;
        }
        free(temp);
        count-=1;
        show();
    }
}

int main()
{
    int i, choice;

    do
    {
        // Menu-driven program
        printf("\n1.insert\n2. delete\n3. show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int pos;
            printf("enter pos:");
            scanf("%d", &pos);

            if (pos >= count + 1|| pos<1)
            {
                printf("invalid position");
            }
            else if (pos == 1)
            {
                insertbeg();
            }
            else
            {
                insertpos(pos);
            }

            break;
        case 2:
           printf("enter pos:");
            scanf("%d", &pos);

            if (pos >= count + 1|| pos<1)
            {
                printf("invalid position");
            }
            else if (pos == 1)
            {
                deletebeg();
            }
            else
            {
                deletepos(pos);
            }

            break;

        case 3:
            show();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
