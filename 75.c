/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

NODE *find(NODE *, int *);
void outputring(NODE *);
void change(int, int, NODE *);

void outputring(NODE *pring)
{
	NODE *p;
	p = pring;
	if (p == NULL)
		printf("NULL");
	else
		do
		{
			printf("%d", p->data);
			p = p->next;
		} while (p != pring);
	printf("\n");
	return;
}

int main()
{
	int n, m;
	NODE *head, *pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc(sizeof(NODE));
	head->next = NULL;
	head->data = -1;

	change(n, m, head);
	pring = find(head, &n);
	printf("ring=%d\n", n);
	outputring(pring);

	return 0;
}
// start

#include <string.h>
int p1, p2;
void change(int n, int m, NODE *head)
{
	int a[2000], last[2000];
	memset(a, 0, sizeof(a));
	memset(last, 0, sizeof(last));

	p1 = 0;
	p2 = 0;
	int flag = 0;
	int num = n;

	for (int i = 0;; i++)
	{
		a[i] = num / m;
		last[i] = num % m;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[i] && last[i] == last[j])
			{
				p1 = j;
				p2 = i;

				flag = 1;
				break;
			}
		}
		num = last[i] * 10;
		if (!num)
		{
			p1 = i + 1;
			break;
		}
		if (flag == 1)
			break;
	}
	NODE *r = head;
	for (int i = 0; i < p1; i++)
	{
		NODE *q = (NODE *)malloc(sizeof(NODE));
		q->data = a[i];
		q->next = NULL;
		r->next = q;
		r = q;
	}
	if (flag == 1)
	{
		NODE *R = r;
		for (int i = p1; i < p2; i++)
		{
			NODE *q = (NODE *)malloc(sizeof(NODE));
			q->data = a[i];
			q->next = NULL;
			r->next = q;
			r = q;
		}
		r->next = R->next;
	}
}
NODE *find(NODE *head, int *n)
{
	if (p2 > p1)
	{
		NODE *p = head->next;
		*n = p2 - p1;
		for (int i = 0; i < p1; i++)
			p = p->next;
		return p;
	}
	else
	{
		*n = 0;
		return NULL;
	}
}