#include<stdio.h>
int stk[50],ch,max,top,val,i;
void push();
void pop();
void peak();
void display();
int main()
{   top=-1;
    printf("enter the size of stack[max=50]\n:");
    scanf("%d",&max);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n------------------------------");
    printf("\n\t1.Push\n\t2.Pop\n\t3.Peak\n\t4.Display\n\t5.Exit");
    do
    {
        printf("\n\nenter choice=");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        {   push();
            break;
        }
        case 2:
        {   pop();
            break;
        }
        case 3:
        {
            peak();
            break;
        }
        case 4:
        {   display();
            break;
        }
        case 5:
        {
            printf("\n\t EXIT...");
            break;
        }
        default:
        {   printf("\n PLEASE ENTER VALID CHOICE(1/2/3/4/5)");
            break;
        }

        }
    }     while(ch!=5);



    return 0;
}
void push()
{   if(top==max-1)
    {   printf("\t..OVERFLOW...!");
    }
    else
    {   printf("enter the elemnt to push:");
        scanf("%d",&val);
        top=top+1;
        stk[top]=val;
        printf("pushed elemnt is [%d]",val);
    }
}
void pop()
{   if(top==-1)
    {   printf("\t..UNDERFLOW..!");
    }
    else
    {   printf("popped elemnt is:[%d]",stk[top]);
        top--;
    }

}
void peak()
{
    if(top==-1)
    {   printf("..STACK IS EMPTY..!");
    }
    else
    {   val=stk[top];
        printf("peak element is[%d]",val);
    }
}
void display()
{
    if(top==-1)
    {   printf("..STACK IS EMPTY..!");
    }
    else
    {   printf(" elements in stack\n");
        printf("STACK[%d]:",max);
        for(i=0; i<=top; i++)
        {
            printf("[%d],",stk[i]);
        }
    }
}