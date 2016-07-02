#include <stdio.h>
#include<stdlib.h>
#define queue 5
void add(int item,int *rear,int *q,int *count)
{
    if(*count==queue)
    {
        printf("\n queue overflow\n");
        return;
    
    }
    (*rear)=(*rear+1)%queue;
    q[*rear]=item;
    (*count)++;
}
void display(int front,int q[],int count)
{int i;
    if(count==0)
    {
        printf("\n queue empty\n");
        return;
        
    }
    for(i=1;i<=count;i++)
    
{
    printf("\n%d-",q[front]);
    front=(front+1)%queue;
}
}
int removes(int *front,int *q,int *count)
{
    int item;
    if(*count==0)
    {
        //printf("\n queue empty");
        return -1;
    }
    item=q[*front];
    (*front)=(*front+1)%queue;
    (*count)--;
    return item;
}
int main()
{
    int item,front,rear,ch,q[queue],deleted,count;
    front=0;
    rear=-1;
    count=0;
    while(1)
    {
        printf("\n1.add\n2.display\n3.delete\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n nenter element to enter\n");
            scanf("%d",&item);
            add(item,&rear,q,&count);
            break;
            case 2:display(front,q,count);
            break;
            case 3:deleted=removes(&front,q,&count);
            if(deleted==-1)
            {
                printf("\n queue empty");
            }
else
                   printf("\n item deleted is %d",deleted);
                   break;
                   default:exit(0);
        }
    }
   
    return 0;
}



