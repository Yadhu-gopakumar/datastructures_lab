#include<stdio.h>
int q[100],max,ch,val,i,front=-1,rear=-1;
void insert();
void dlte();
void peak();
void display();
int main()
{
    printf("enter the size of QUEUE[max=100]\n:");
    scanf("%d",&max);
    printf("\n\tQUEUE OPERATIONS");
    printf("\n\t----------------");
    printf("\n\t1.Insert\n\t2.Delete\n\t3.Peak\n\t4.Display\n\t5.EXIT");
    do
    {
        printf("\nenter your option:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        {   insert();
            break;
        }
        case 2:
        {   dlte();
            break;
        }
        case 3:
        {   peak();
            break;
        }
        case 4:
        {   display();

            break;
        }
        case 5:
        {   printf("\n EXIT...");
            break;

        }
        default:
        {   printf("\nENTER A VALID OPTION(1/2/3/4/5))!!!");

        }
        }
    } while(ch!=5);
    return 0;
}
void insert()
{

    if(rear==max-1)
    {   printf("\n\tOVERFLOW..!");
    }
    else
    {
        printf("\nenter the elemnt to insert");
        scanf("%d",&val);
        if(front==-1&&rear==-1)
        {   front=rear=0;
            q[rear]=val;
        }
        else {
            rear++;
            q[rear]=val;
        }
        printf("\telement inserted= [%d]",val);
    }
}
void dlte()
{
    if(front==-1||front>rear)
        printf("\n\tUNDERFLOW..!");
    else
    {
        val=q[front];
        printf("\n\telement deleted is [%d]",val);
        front++;

    }


}
void peak()
{
    if(front==-1||front>rear)
    {   printf("\n\t QUEUE IS EMPTY...!");
    }
    else
    {
        printf("\nQUEUE[FRONT]=[%d]",q[front]);
    }
}
void display()
{
    if(front==-1||front>rear)
    {   printf("\n\t QUEUE IS EMPTY...!");
    }
    else
    {   printf("\n>>QUEUE[%d]:",max);
        for(i=front; i<=rear; i++)
        {   printf("[%d],",q[i]);
        }
    }
}