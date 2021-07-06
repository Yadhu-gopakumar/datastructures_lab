#include<stdio.h>
int main()
{   int a[10],n,i,val,pos=-1,beg,end,mid;
    printf("enter the limit\n=");
    scanf("%d",&n);
    printf("enter the elmnts in ascending order\n=");
    for(i=1; i<=n; i++)
    {   scanf("%d",&a[i]);
    }
    printf("ARRAY IS\n=");
    for(i=1; i<=n; i++)
    {   printf("[%d],",a[i]);
    }
    printf("\n\nenter the elment to be search\n=");
    scanf("%d",&val);
    beg=1;
    end=n;
    pos=-1;
    while(beg<=end)
    {   mid=(beg+end)/2;
        if(a[mid]==val)
        {   pos=mid;
            printf("[%d] found at position %d",val,pos);
            break;
        }

        else
        {   if(a[mid]>val)
                end=mid-1;
            else
                beg=mid+1;
        }
    }
    if(pos==-1)
        printf("\nelement not found!!!\n");
    return 0;
}