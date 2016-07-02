#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define Malloc(q,n,type)\
q=(type*)malloc(n*sizeof(type));\
if(q==NULL)\
{printf("insufficient memory");\
exit(0);\
}      
#define Realloc(q,n,type)\
q=(type*)realloc(q,n*sizeof(type));\
if(q==NULL)\
{printf("insufficient memory");\
exit(0);\
} 
int stacksize=1;
void push(int item,int *top,int **s)
    {
    if(*top==stacksize-1)
        {
        stacksize++;
        Realloc(*s,stacksize,int);
    }
    (*s)[++(*top)]=item;
}
void pop(int *s,int *s)
    {
    if(*top==-1)
        {
        return;
    }
    else
       s[(*top)--]; 
}
/*void display(int top,int *s)
    {
    int max=-999999;
    int i;
    if(top==-1)
        {
        return;
    }
    else
        {
        for(i=0;i<=top;i++)
            {
//printf("%d->",s[i]);
            if(s[i]>max)
                {
                max=s[i];
            }
        }
        printf("%d\n",max);
    }
        
}*/void display(int top,int *s)
{
int i;
if(top==-1)
{
return;
}
else
{
for(i=0;i<=top;i++)
{
printf("%d->",s[i]);
}
}
}
int main() {
    int top,*a,item,n,ch;
    top=-1;
    Malloc(a,1,int);
    scanf("%d",&n);
    while(n!=0)
        {
        scanf("%d",&ch);
        switch(ch)
            {
            case 1:scanf("%d",&item);
                    push(item,&top,&a);
            n--;
            break;
            case 2:pop(a,&top);
            n--;
            break;
            case 3:display(top,a);
            n--;
                   break;
            default:exit(0);
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

