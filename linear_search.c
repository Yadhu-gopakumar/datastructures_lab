#include<stdio.h>
int main()
{
    int a[25],n,i,val,pos=-1;
    printf("enter the limit\n=");
    scanf("%d",&n);
    printf("enter the elements\n=");
    for(i=1; i<=n; i++)
    {   scanf("%d",&a[i]);
    }
    printf("entered array is\n");
    for(i=1; i<=n; i++)
        printf("[%d],",a[i]);
    printf("\nenter the element to be search\n=");
    scanf("%d",&val);
    for(i=1; i<=n; i++)
    {   if(a[i]==val)
        {   pos=i;
            break;
        }

    }
    if(pos!=-1)
    {   printf("%d found at %d th position",val,pos);
    }
    else
    {   printf("element not found!!");
    }
    return 0;
}