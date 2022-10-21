/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//swap the pointer array 's pointng position
/*void swap(int **a,int **b)
{
    int *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}*/

// output the pa[]
//sort from small to big numbers

int resort(int *pa[], int num)
{
    for (int i = num - 1; i >= 1; i--)
    {
        int max = 0;
        for (int j = 1; j <= i; j++)
        {
            if (*pa[j] > *pa[max])
            {
                max = j;
            }
        }
        //swap
        if (i != max)
        {
            //swap(pa[i],pa[max]);
            int *temp = pa[i];
            pa[i] = pa[max];
            pa[max] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    int a[100];
    int num;

    int *pa[100]; //create the pa[]
    scanf("%d", &num);

    int i = 0;
    for (i = 0; i < num; i++) //memset pa=&a
    {
        scanf("%d", &a[i]);
        pa[i] = &a[i];
    }

    resort(pa, num);

    for (i = 0; i < num; i++)
    {
        printf("%d\n", *pa[i]);
    }
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */