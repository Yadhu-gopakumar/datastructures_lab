#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *create(int n);
void display(node*start);
int main()
{   int n;
    node *start=NULL;
    printf("How many nodes\n\t:");
    scanf("%d",&n);
    start=create(n);
    display(start);
    return 0;
}
node *create(int n)
{
    int i;
    node*start=NULL;
    node*new_node= NULL;
    node*ptr= NULL;
    for(i=0; i<n; i++)
    {
        new_node=(node*)malloc(sizeof(node));
        printf("Enter the %d'th data:",i+1);
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
void display(node*start)
{

    node*ptr=start;
    printf("\n\t--LINKED LIST IS--\n");
    printf("\t------------------\n:");
    while(ptr!= NULL)
    {   printf("(%d]--->",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}