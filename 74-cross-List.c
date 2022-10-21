/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include "stdio.h"  
#include "stdlib.h"  
  
struct node  
{   int data;  
    struct node * next;  
} ;  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE );  
void createList(PNODE);  
void deployList(PNODE head1,PNODE head2,PNODE head3);  
  
int main ( )  
{   int num=1;  
    PNODE head1,head2,head3;  
  
    head1 = (PNODE)malloc( sizeof(NODE) );  
    head1->next = NULL;  
    head1->data = -1;  
      
    head2 = (PNODE)malloc( sizeof(NODE) );  
    head2->next = NULL;  
    head2->data = -1;  
  
    head3 = (PNODE)malloc( sizeof(NODE) );  
    head3->next = NULL;  
    head3->data = -1;  
  
    createList(head1);// 这是你要完成的函数  
    createList(head2);// 这是你要完成的函数  
    deployList(head1,head2,head3);// 这是你要完成的函数  
    outlist( head3 );  
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

void createList(PNODE head)
{
    int num=1;
    PNODE prev=head,p;
    while(num!=0)
    {
        scanf("%d",&num);
        if(num!=0)
        {
            p=malloc(sizeof(PNODE));
            p->data=num;
            prev->next=p;
            p->next=NULL;
            prev=p;
        }
        else break;
    }
}


void deployList(PNODE head1,PNODE head2,PNODE head3)
{
    PNODE p1=head1->next,p2=head2->next,p3=head3;
    while(p1!=NULL&&p2!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3->next->next=p2;
        p3=p2;
        p2=p2->next;
    }

    if(p1==NULL)
    {
        p3->next=p2;
    }
    else p3->next=p1;
}



  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  