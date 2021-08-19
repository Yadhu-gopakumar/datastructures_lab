#include<stdio.h>
#include<conio.h>
#define MAX 5

int queue[MAX],front=-1,rear=-1;

int enqueue(int data)
{
    if(front==0 && rear==MAX-1||front==rear+1)
    {
        printf("\noverflow");

        return 0;
    }
    if(front==-1&& rear==-1)
    {
        front=rear=0;
    }
    else {
        rear++;
    }
    queue[rear]=data;
    printf("\nadded=>%d\n",data);

}

int dequeue()
{
    if(front==-1)
    {
        printf("\nunderflow\n");
        return 0;
    }
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        int value=queue[front];
        front++;
        printf("\nDeleted=>%d\n",value);
    }
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty\n");
    } else {
        printf("\nThe latest queue\n=");

        for(i=front; i<=rear; i++)
        {
            printf("[%d],",queue[i]);
        }
        printf("\n");
    }
}
int main()

{
    int data,choice;
    clrscr();
    do {
        printf("--------------------------------");
        printf("\n\tCIRCULAR QUEUE\n\t--------------");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nSELECT OPERATION:");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            printf("\nEnter data =>");
            scanf("%d",&data);
            enqueue(data);
            break;

        case 2:

            dequeue();
            break;


        case 3:

            display();
            break;
        case 4:
            printf("EXIT..\n");
            break;

        default:
            printf("\nInvalid operation\n");
        }

    } while(choice!=4);

}