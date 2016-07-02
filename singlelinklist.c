#include <stdio.h>
#include<stdlib.h>

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
NODE insert(int item,NODE first)
{
NODE temp;
Malloc(temp,1,struct node);
temp->info=item;
temp->link=first;
return temp;//always return the start one
}
NODE display(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("\n empty\n");
return;
}
temp=first;
while(temp!=NULL)
{
printf("%d->",temp->info);
temp=temp->link;
}
printf("\n");
}
NODE delete(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("\ncannot delete list empty\n");
return first;
}
temp=first;
temp=temp->link;
printf("\n item deleted is %d\n",first->info);
free(first);
return temp;
}
NODE insertrear(int item,NODE first)
{
NODE temp,curr;
Malloc(temp,1,struct node);
temp->info=item;
temp->link=NULL;
if(first==NULL)
{
return temp;
}
curr=first;
while(curr->link!=NULL)
{
curr=curr->link;
}
curr->link=temp;
return first;
}
NODE deleterear(NODE first)
{
NODE temp,prev;
if(first==NULL)
{
printf("\n list empty\n");
return NULL;
}
if(first->link==NULL)
{
printf("\n item deleted is %d\n",first->info);
free(first);
return NULL;
}
temp=first;
prev=NULL;
while(first->link!=NULL)
{
prev=first;
first=first->link;
}
printf("\n item deletedd is %d\n",first->info);
free(first);
prev->link=NULL;
return temp;
}
void search(int key,NODE first)
{
int count=1;
if(first==NULL)
{
printf("\n list empty");
return;
}
NODE curr;
curr=first;
while(curr!=NULL)
{
if(key==curr->info)
{
printf("\n match found at %d",count);

break;
}
curr=curr->link;
count++;
}
if(curr==NULL)
{
printf("\n unsuccesfull\n");
return;
}
printf("\n finished searching\n");
}
NODE deletekey(int ele,NODE first)
{
NODE temp;
if(first==NULL)
{
printf("\n empty list \n");
return first;
}
if(ele==first->info)
{
temp=first;
first=first->link;
free(temp);
return first;
}
NODE prev;
temp=first;
while(temp!=NULL)
{
if(ele==temp->info)
break;
prev=temp;
temp=temp->link;
}
if(temp==NULL)
{
printf("\n key element not found to delete\n");
return first;
}
prev->link=temp->link;
free(temp);
return first;
}
NODE insertpos(NODE first,int n,int item)
{
int count=2;
NODE temp,curr;
Malloc(temp,1,struct node);
temp->info=item;
temp->link=first;
curr=first;
if(n==1)
{
return insert(item,first);
}
while(count!=n && curr!=NULL)
{
curr=curr->link;
count++;
}
if(curr==NULL)
{
printf("\n inavlid retry\n");
return first;
}
temp->link=curr->link;
curr->link=temp;
return first;
}
NODE deletepos(NODE first,int n)
{
NODE temp,prev;
int count=1;
if(first==NULL)
{
printf("list empty");
return first;
}
if(n==1)
{
return delete(first);
}
temp=first;
while(count!=n && temp!=NULL)
{
prev=temp;
temp=temp->link;
count++;
}
if(temp==NULL)
{
printf("\n invalid\n");
return first;
}
prev->link=temp->link;
free(temp);
return first;
}
NODE reverse(NODE first)
{
NODE temp,curr;
curr=NULL;
while(first!=NULL)
{
temp=first->link;
first->link=curr;
curr=first;
first=temp;
}
return curr;
}
int main()
{
NODE first=NULL;
NODE sec=NULL;
int item,ch,key,ele,posi;
while(1)
{
printf("1.addfront\n2.display\n3.delete\n4.addrear\n5.deleterear\n6.search\n7.delete specific\n8.reverse\n9.insert at pos\n10.deletepos\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n enter data");
          scanf("%d",&item);
       first=insert(item,first);
       break;
case 2:display(first);
       break;
case 3:first=delete(first);
       break;
case 4:printf("\n enter data");
          scanf("%d",&item);
first=insertrear(item,first);
break;
case 5:first=deleterear(first);
       break;
case 6:printf("\n enter item to search\n");
       scanf("%d",&key);
       search(key,first);
       break;
case 7:printf("\nenter element to delete\n");
      scanf("%d",&ele);
       first=deletekey(ele,first);
       break;
case 8:first=reverse(first);
display(first);
       break;
case 9:printf("\n enter position \n");
       scanf("%d",&posi);
       printf("\n enter info part\n");
       scanf("%d",&item);
       first=insertpos(first,posi,item);
       break;
case 10:printf("\n enter position \n");
       scanf("%d",&posi);
       first=deletepos(first,posi);
        break;
default:exit(0);
}
}
return 0;
}
