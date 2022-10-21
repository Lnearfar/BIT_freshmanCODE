/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include "stdio.h"  
#include "stdlib.h" 
  
struct node  
{   
    int data;  
    struct node * next;  
} ;  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE );  
void createList(PNODE);  
void deployList(PNODE); 
  
int main ( )  
{

    PNODE head;  
  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    createList(head);// 这是你要完成的函数  
    deployList(head);// 这是你要完成的函数  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}  

int N=0;
void createList(PNODE head)
{
    int num=1;
    PNODE p,present=head;
    while(num!=0)
    {
        scanf("%d",&num);
        if(num==0) break;
        else
        {
            p=malloc(sizeof(PNODE));
            p->data=num;
            present->next=p;
            p->next=NULL;
            present=p;
            N++;
        }
    }
}

void deployList(PNODE head)
{
    PNODE present=head->next,prev=head,last=head;
    for(int i=0;i<N;i++)
    {
        last=last->next;
    }

    for(int i=0;i<N;i++)
    {
        if(present->data%2==1)
        {
            prev->next=present->next;
            last->next=present;
            present->next=NULL;
            last=present;
            present=prev->next;
        }
        else continue;
    }
}
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 
