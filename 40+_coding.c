#include<stdio.h>
#include<string.h>
int main()
{
    int N, l, i, j, k, t, signal,s[100];
    long int count;
    char a[1000][11], cnt[11];
    scanf("%d", &N);
    for ( i = 0; i < N; i++) /*input N arr*/
    {
        s[i]=1;
        scanf("%s", a[i]);
        for(j=0;j<=10&&a[i][j]!='\0';j++)
        {
            if(a[i][j]<=96||a[i][j]>=123||(a[i][j+1]<=a[i][j])&&a[i][j+1]!='\0')
            {
                s[i]=0;
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        count=1;
        if(s[i]==0)
        {
            printf("0\n");
            continue;
        }
        cnt[0] = 'a';
        cnt[1] = '\0';
        l = strlen(a[i]);
        for (j = 1; j <= l; j++)
        {
            do
            {
                if (strcmp(a[i], cnt) == 0)
                {
                    printf("%d\n", count);
                    break;
                }
                else /*carry +1*/
                {
                    count++;
                    signal = 0;
                    for (k = j - 1; k >= 0; k--)
                    {
                        if (cnt[k] != 122 - (j - 1 - k))
                        {
                            signal = 1;
                            cnt[k]++;
                            for (t = k + 1; t <= j - 1; t++)
                            {
                                cnt[t] = cnt[k] + (t - k);
                            }
                            break;
                        }
                    }
                }
            } while (signal == 1);
            for (k = 0; k <= j; k++)
            {
                cnt[k] = 'a' + k;
            }
            cnt[j+1]='\0';
        }
    }
    return 0;
}