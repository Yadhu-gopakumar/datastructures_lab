#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *createQ(int n);
void display(node*start);
node *insertQ(node*start);
node *deleteQ(node*start);

int main()
{   int n,ch;
    node *start=NULL;
    do {
        printf("\n------------------------------------");
        printf("\n\t***MENU***");
        printf("\n\t----------");
        printf("\n1).Create queue");
        printf("\n2).Display the queue");
        printf("\n3).insert element");
        printf("\n4).Delete element");
        printf("\n5).exit");
        printf("\n\t¤¤ ENTER YOUR OPTION=");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("¤¤ Enter the size of queue\n\t:");
            scanf("%d",&n);
            start=createQ(n);
            break;
        case 2:
            displayQ(start);
            break;
        case 3:
            start=insertQ(start);
            break;
        case 4:
            start=deleteQ(start);
            break;
        case 5:
            printf("\nEXIT");
            break;
        default:
            printf("\n >>>ENTER A VALID OPTION...!");
        }

    } while(ch!=5);
    return 0;
}
node *createQ(int n)
{
    int i;
    node*start=NULL;
    node*new_node= NULL;
    node*ptr= NULL;
    for(i=0; i<n; i++)
    {
        new_node=(node*)malloc(sizeof(node));
        printf("¤¤ Enter the %d'th Queue element:",i+1);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(start==NULL)
        {   start=new_node;
        }
        else {
            ptr=start;
            while(ptr->next!=NULL)
            {   ptr=ptr->next;
            }
            ptr->next=new_node;
        }
    }
    return start;
}
void displayQ(node*start)
{

    node*ptr=start;
    printf("\n\t--QUEUE IS--\n");
    printf("\t------------\n:\n");
    while(ptr!= NULL)
    {   printf("[%d],",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
node *insertQ(node*start)
{
    node*new_node;
    node*ptr;
    int val;
    printf("¤¤ Enter your data\n:");
    scanf("%d",&val);
    new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    ptr=start;
    while(ptr->next!= NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next= NULL;
    printf("element %d inserted into queue\n:",val);
    return start;
}
node *deleteQ(node*start)
{
    int item;
    struct node*ptr;
    if(start==NULL) {
        printf("underflow..");
    }
    else {
        item=start-> data;
        ptr=start;
        start=start->next;
        free(ptr);
        printf("\nelemet %d deleted from queue",item);
    }
    return start;
}


    