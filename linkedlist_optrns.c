#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int n);
void display(node*start);
node *insert_beg(node*start);
node *insert_end(node*start);
node *insert_before(node*start);
node *insert_after(node*start);
node *delete_beg(node*start);
node *delete_end(node*start);
node *delete_node(node*start);

int main()
{   int n,ch;
    node *start=NULL;
    do {
        printf("\n------------------------------------");
        printf("\n\t***MENU***");
        printf("\n\t----------");
        printf("\n1).Create a linked list");
        printf("\n2).Display the list");
        printf("\n3).Add a node at begening");
        printf("\n4).Add a node at end");
        printf("\n5).Add a node before a given node");
        printf("\n6).Add a node after a given node");
        printf("\n7).Delete a node from begening");
        printf("\n8).Delete a given node");
        printf("\n9).Delete a node from end");
        printf("\n10).exit");
        printf("\n\t¤¤ ENTER YOUR OPTION=");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("¤¤ How many nodes\n\t:");
            scanf("%d",&n);
            start=create(n);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start=insert_beg(start);
            break;
        case 4:
            start=insert_end(start);
            break;
        case 5:
            start=insert_before(start);
            break;
        case 6:
            start=insert_after(start);
            break;
        case 7:
            start=delete_beg(start);
            break;
        case 8:
            start=delete_node(start);
            break;
        case 9:
            start=delete_end(start);
            break;
        case 10:
            printf("\nEXIT");
            break;
        default:
            printf("\n >>>ENTER A VALID OPTION...!");
        }

    } while(ch!=10);
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
        printf("¤¤ Enter the %d'th data:",i+1);
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
    printf("\t------------------\n:\n");
    while(ptr!= NULL)
    {   printf("(%d]-->",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
node *insert_beg(node*start)
{   int val;
    node*new_node;
    printf("\n¤¤ Enter data=");
    scanf("%d",&val);
    new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=start;
    start=new_node;
    return start;

}
node *insert_end(node*start)
{
    node*new_node;
    node*ptr;
    int val;
    printf("¤¤ Enter your data");
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
    return start;
}
node *insert_before(node*start)
{
    node*new_node;
    node*pre_ptr;
    node*ptr;
    int val,item;
    printf("¤¤ Enter your data");
    scanf("%d",&item);
    printf("¤¤ Enter the value before which the data has to be inserted\n:");
    scanf("%d",&val);
    new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    ptr=start;
    pre_ptr=ptr;
    while(ptr->data!= val)
    {   pre_ptr=ptr;
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next= ptr;
    return start;


}
node *insert_after(node*start)
{
    node*new_node;
    node*pre_ptr;
    node*ptr;
    int val,item;
    printf("¤¤ Enter your data\n:");
    scanf("%d",&item);
    printf("¤¤ Enter the value before which the data has to be inserted\n:");
    scanf("%d",&val);
    new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    ptr=start;
    pre_ptr=ptr;
    while(pre_ptr->data!= val)
    {   pre_ptr=ptr;
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next= ptr;
    return start;

}
node *delete_beg(node*start)
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
        printf("\nfirst node deleted",item);
    }
    return start;
}

node *delete_node(node*start)
{   int item;
    struct node*ptr;
    struct node*pre_ptr;
    if(start==NULL)
    {

        printf("underflow..");
    }
    else 
    {
        printf("¤¤ enter the element to delete\n:");
        scanf("%d",&item);
        ptr=start;
        pre_ptr=ptr;
        while(ptr->data!=item)
        {
            pre_ptr=ptr;
            ptr=ptr->next;
        }
        pre_ptr->next=ptr->next;
        free(ptr);
        printf("given node %d deleted\n",item);
       }
    return start;
}
node *delete_end(node*start)
{
    int item;
    struct node*ptr;
    struct node*pre_ptr;
    if(start==NULL)
    {

        printf("underflow..");
    }
    else {
        ptr=start;
        while(ptr->next!=NULL)
        {
            pre_ptr=ptr;
            ptr=ptr->next;
        }
        pre_ptr->next=NULL;
        free(ptr);

        printf("\n last node deleted");
    }
    return start;
}
    