/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
void outlist(PNODE);
void sortlist(PNODE, int);

int main()
{
    int num = 1;
    PNODE head;

    head = (PNODE)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;

    while (num != 0)
    {
        scanf("%d", &num);
        if (num != 0)
            sortlist(head, num);
    }
    outlist(head);
    return 0;
}
//head -1  next

void outlist(PNODE head)
{
    PNODE p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/* This is an example for list. Please programme your code like it. */

void sortlist(PNODE h, int num)
{
    PNODE p, plst;
    p = h;
    while (p != NULL && p->data <= num)
    {
        if (p->data == num)
        {
            return ;
        }
        else
        {
            plst = p;
            p = p->next;
        }
    }              //p->data>num or p==NULL(that is bad!)
    if (p == NULL) //insert to the last one
    {
        p = malloc(sizeof(NODE));
        plst->next = p;
        p->next = NULL;
        p->data = num;
    }
    else
    {
        PNODE ptemp = malloc(sizeof(NODE));
        plst->next = ptemp;
        ptemp->next = p;
        ptemp->data = num;
    }
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */