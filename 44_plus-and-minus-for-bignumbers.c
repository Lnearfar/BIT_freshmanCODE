#include <stdio.h>
#include <string.h>
int main()
{
    int N, i, j, k, c[501], t, signal, p, sign; // c为借位或进位的标志数组
    char anwser[501];
    anwser[500] = '\0';
    char number[1001];
    scanf("%d", &N);
    for (p = 0; p < N; p++)
    {
        scanf("%s", number);
        int L = strlen(number);
        for (j = 0; number[j] != '+' && number[j] != '-'; j++)
            ; /*找到符号的位置j*/
        int l1 = j;
        int l2 = L - 1 - j; // l1表示前部分数组长度，l2表示后部分数组长度
        //计算加法
        if (number[j] == '+')
        {
            for (i = 0; i <= 499; i++) /*给结果anwser数组和进位标志数组c初始化*/
            {
                if (anwser[i] != '0')
                    anwser[i] = '0';
                if (c[i] != 0)
                    c[i] = 0;
            }
            for (k = 0; k < l2; k++) /*将长为l2的数组复制到anwser中*，anwser[0]是末尾，就是anwser是反向排序的*/
            {
                anwser[k] = number[L - 1 - k];
            }
            c[0] = 0;
            for (k = 0; k < l1; k++) /*将长为l1的数组加到answer上*/
            {
                if (number[l1 - 1 - k] + anwser[k] + c[k] - 96 >= 10) //从右往左第k位需要进位
                {
                    c[k + 1] = 1;                                           /*将进位暂时存到c数组中*/
                    anwser[k] = number[l1 - 1 - k] + anwser[k] + c[k] - 58; /*存的还是对应数的字符*/
                }
                else
                {
                    c[k + 1] = 0;
                    anwser[k] = number[l1 - 1 - k] + anwser[k] + c[k] - 48;
                }
            }
            for (t = k; c[t] == 1 && t <= 499; t++) /*计算进位*/
            {
                if (anwser[t] == '9')
                {
                    c[t + 1] = 1;
                    anwser[t] = '0';
                }
                else
                    anwser[t] += 1;
            }
            for (t = 499; anwser[t] == '0' && t >= -1; t--)
                ; /*找到第一个非0*/
            if (t == -1)
            {
                printf("0\n");
                continue;
            }
            else
            {
                for (j = t; j >= 0; j--)
                    printf("%c", anwser[j]);
                printf("\n");
            } /*输出计算结果*/
        }
        //计算减法
        else
        {
            sign = 1;                  // sign用来判断借位标志数组是否还需要工作
            char js[500], bj[500];     // bj为被减数，js为减数
            for (i = 0; i <= 499; i++) /*给c[i]初始化*/
            {
                if (c[i] != 0)
                    c[i] = 0;
            }
            //接下来比较两数大小
            if (l1 == l2)
            {
                for (i = 0; number[i] == number[l1 + 1 + i] && i < l1; i++)
                    ;
                if (i == l1)
                {
                    printf("0\n");
                    continue;
                } /*两数相等*/
                else if (number[i] < number[l1 + 1 + i])
                    signal = 0; // signal=0说明number前面部分的数字小，反之number前面部分的数字大
                else
                    signal = 1;
            }
            if (l1 > l2 || signal == 1)
            {
                signal = 1;
                for (i = 0; i < l1; i++)
                    bj[i] = number[i];
                for (i = 0; i < l2; i++)
                    js[i] = number[l1 + 1 + i];
                bj[l1] = '\0';
                js[l2] = '\0';
            }
            if (l1 < l2 || signal == 0)
            {
                signal = 0;
                for (i = 0; i < l1; i++)
                    js[i] = number[i];
                for (i = 0; i < l2; i++)
                    bj[i] = number[l1 + 1 + i];
                bj[l2] = '\0';
                js[l1] = '\0';
            } /*下面计算bj被减数）-js（减数）*/
            int B = strlen(bj);
            int J = strlen(js);
            c[B - 1] = 0;
            for (t = 0; t < J; t++) /*开始算进位*/
            {
                if (bj[B - 1 - t] - c[B - 1 - t] < js[J - 1 - t]) /*需要借一位*/
                {
                    bj[B - 1 - t] = bj[B - 1 - t] + 58 - c[B - 1 - t] - js[J - 1 - t];
                    c[B - 2 - t] = 1;
                }
                else //直接算
                {
                    bj[B - 1 - t] = bj[B - 1 - t] + 48 - c[B - 1 - t] - js[J - 1 - t];
                    if (B == J && t == J - 1)
                        sign = 0; /*如果出现B=J且算到了最后一位，这时候被减数就是结果，不用在*/
                    /*进行补借位的操作，故让sign为0，表示结束*/
                    else
                        c[B - 2 - t] = 0;
                }
            }
            for (t = J; sign != 0 && t <= B && c[B - 1 - t] == 1; t++) //将前面的借位算完
            {
                if (bj[B - 1 - t] == '0')
                {
                    c[B - 2 - t] = 1;
                    bj[B - 1 - t] = '9';
                }
                else
                {
                    bj[B - 1 - t] -= 1;
                    c[B - 2 - t] = 0;
                }
            }
            for (t = 0; t <= (B - 1) && (bj[t] == '0'); t++)
                ; //找到第一个非0
            /*分符号输出*/
            if (signal == 0) //值为-
            {
                printf("-");
                for (i = t; i <= B - 1; i++)
                    printf("%c", bj[i]);
                printf("\n");
                continue;
            }
            else //值为+
            {
                for (i = t; i <= B - 1; i++)
                    printf("%c", bj[i]);
                printf("\n");
                continue;
            }
        }
    }
    return 0;
}