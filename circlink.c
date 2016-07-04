#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//#define queue 5
#define Malloc(q,n,type)\
q=(type*)malloc(n*sizeof(type));\
if(q==NULL)\
{printf("insufficient memory");\
exit(0);\
}      
struct node
{
int info;
struct node *link;
};
typedef struct node* NODE;
NODE insertfront(NODE last,int item)
{
NODE temp;
Malloc(temp,1,struct node);
temp->info=item;
if(last==NULL)
last=temp;
else
temp->link=last->link;
last->link=temp;
return last;
}
NODE insertrear(NODE last,int item)
{
NODE temp;
Malloc(temp,1,struct node);
temp->info=item;
if(last==NULL)
last=temp;
else
temp->link=last->link;
last->link=temp;
return temp;
}
void display(NODE last)
{
if(last==NULL)
{
printf("\n empty\n");
return;
}
NODE temp=last->link;
while(temp!=last)
{
printf("%d->",temp->info);
temp=temp->link;
}
printf("%d",temp->info);
printf("\n");
}
NODE deletefront(NODE last)
{
NODE temp;
if(last==NULL)
{
printf("\n empty\n");
return last;
}
if(last->link==last)
{
free(last);
return NULL;
}
temp=last->link;
last->link=temp->link;
free(temp);
return last;
}
NODE deleterear(NODE last)
{
NODE temp;
if(last==NULL)
{
printf("\n empty\n");
return last;
}
if(last->link==last)
{
free(last);
return NULL;
}
temp=last->link;
while(temp->link!=last)
{
temp=temp->link;
}
temp->link=last->link;
free(last);
return temp;
}
void search(NODE last,int key)
{
NODE temp;
bool flag=false;
if(last==NULL)
{
printf("\n list empty\n");
return;
}
int count=1;
temp=last->link;
while(temp!=last)
{
if(key==temp->info)
{
flag=true;
break;
}
temp=temp->link;
count++;
}
if(key==last->info)
{
flag=true;
printf("\n found at %d\n",count);
return;
}
if(flag)
{
printf("\nfound at %d\n",count);
return;
}
else
printf("\n not found \n");
}
NODE deletespecific(NODE last,int item)
{
NODE prev;
if(last==NULL)
{
printf("\n empty\n");
return last;
}
NODE temp=last->link;
bool flag=false;
if(item==last->info)
{
flag=true;
return deleterear(last);
}
if(item==temp->info)
{
flag=true;
return deletefront(last);
}
while(temp->link!=last)
{
prev=temp;
temp=temp->link;
if(item==temp->info)
{
flag=true;
break;
}
}
if(!flag)
{
printf("\n invalid entry\n");
return last;
}
prev->link=temp->link;
free(temp);
return last;
}
NODE reverse(NODE last)
{
if(last==NULL)
{
printf("\n empty \n");
return last;
}
NODE temp,curr,x,x1;
x1=last->link;
curr=last;
temp=last->link;
while(temp!=last)
{
x=curr;
curr=temp;
temp=temp->link;
curr->link=x;
}
last->link=curr;
return x1;
}
NODE insertpos(NODE last,int pos,int item)
{
NODE temp,curr;
int count=1,n;
bool flag=false;
Malloc(temp,1,struct node);
temp->info=item;
if(pos==1)
{
flag=true;
return insertfront(last,item);
}
curr=last->link;
while(curr!=last)
{
if(count==pos-1)
{
flag=true;
break;
}
curr=curr->link;
count++;
}
if(pos==count+1)
{
flag=true;
return insertrear(last,item);
}
if(!flag)
{
printf("\n invalid entry\n");
return last;
}
temp->link=curr->link;
curr->link=temp;
return last;
}
NODE deletepos(NODE last,int pos)
{
NODE temp,prev;
int count=1;
bool flag=false;
if(last==NULL)
{
printf("\n empty\n");
return last;
}
if(pos==1)
{
flag=true;
return deletefront(last);
}
prev=last->link;
temp=last->link;

while(temp->link!=last)
{
prev=temp;
temp=temp->link;
count++;
if(pos==count)
{
flag=true;
break;
}
}
if(pos==count+1)
{
flag=true;
return deleterear(last);
}
if(!flag)
{
printf("\n invalid entry\n");
return last;
}
prev->link=temp->link;
free(temp);
return last;
}





int main()
{
NODE last=NULL;
int item,ch,key,ele,posi,pos;
while(1)
{
printf("\n");
printf("1.addfront\n2.display\n3.addrear\n4.deletefront\n5.deleterear\n6.search\n7.delete specific\n8.reverse\n9.insert at pos\n10.deletepos\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n enter data\n");
          scanf("%d",&item);
       last=insertfront(last,item);
       break;
case 2:display(last);
       break;
case 3:printf("\n enter data\n");
       scanf("%d",&item);
       last=insertrear(last,item);
       break;
case 4:last=deletefront(last);
       break;
case 5:last=deleterear(last);
       break;
default:exit(0);
case 6:printf("\n enter element to search \n");
       scanf("%d",&key);
       search(last,key);
       break;
case 7:printf("\n enter item to be deleted\n");
       scanf("%d",&item);
       last=deletespecific(last,item);
       break;
case 8:last=reverse(last);
       break;
case 9:printf("\n enter the pos \n");
       scanf("%d",&pos);
       printf("\n enter the item\n");
       scanf("%d",&item);
       last=insertpos(last,pos,item);
       break;
case 10:printf("\n enter position\n");
        scanf("%d",&pos);
        last=deletepos(last,pos);
break;
}
}
return 0;
}
