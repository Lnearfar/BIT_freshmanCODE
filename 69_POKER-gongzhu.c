#include <stdio.h>
#include <string.h>

struct PLAYER
{
    int num;
    char cards[52][4];
} player[4];

//to judge whether the game can continue
int play()
{
    for (int i = 0; i < 4; i++)
    {
        if (player[i].num != 0)
            return 1;
    }
    return 0;
}

//reset the player arrays
void clear()
{
    for (int i = 0; i < 4; i++)
    {
        memset(player[i].cards, '\0', sizeof(player[i].cards));
    }
}

//to deal the cards one by one
void Deal()
{
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &(player[i].num));
        getchar();
        for (int j = 0; j < player[i].num; j++)
        {
            scanf("%s", &(player[i].cards[j]));
            getchar();
        }
    }
}

//use this function to show how many points can player get when there is no one have all hearts
int point(char *s)
{

    if (strcmp(s, "H1") == 0)
        return -50;
    if (strcmp(s, "H2") == 0)
        return -2;
    if (strcmp(s, "H3") == 0)
        return -3;
    if (strcmp(s, "H4") == 0)
        return -4;
    if (strcmp(s, "H5") == 0)
        return -5;
    if (strcmp(s, "H6") == 0)
        return -6;
    if (strcmp(s, "H7") == 0)
        return -7;
    if (strcmp(s, "H8") == 0)
        return -8;
    if (strcmp(s, "H9") == 0)
        return -9;
    if (strcmp(s, "H10") == 0)
        return -10;
    if (strcmp(s, "H11") == 0)
        return -20;
    if (strcmp(s, "H12") == 0)
        return -30;
    if (strcmp(s, "H13") == 0)
        return -40;
    if (strcmp(s, "S12") == 0)
        return -100;
    if (strcmp(s, "D11") == 0)
        return 100;
    else
        return 0;
}

//judge whether player k has the card s
//if player k has s,return 1,but when s is C10,return 1 for convinience
int judge(char *s, int i)
{
    for (int j = 0; j < player[i].num; j++)
    {
        if (strcmp(s, player[i].cards[j]) == 0)
        {
            if (strcmp(s, "C10") == 0)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
    }
    if (strcmp(s, "C10") == 0)
    {
        return 1;
    }
    else
        return 0;
}

//if heartinone is true return the subscript of the lucky player
//else return -1
int HeartInOne()
{
    for (int i = 0; i < 4; i++)
    {
        int count = 0;
        for (int j = 0; j < player[i].num; j++)
        {
            if (player[i].cards[j][0] == 'H')
                count++;
        }
        if (count == 13)
            return i;
    }
    return -1;
}

//calculate player i 's point and use the (int ) result to return
int calculate(int i)
{
    int result = 0;
    if (HeartInOne() >= 0) //
    {
        if (HeartInOne() == i)
        {
            if (judge("S12", i) && judge("D11", i))
            {
                return judge("C10", i) * 500;
            }
            else
            {
                result += 200;
                if (judge("S12", i))
                    return judge("C10", i) * (result - 100);
                if (judge("D11", i))
                    return judge("C10", i) * (result + 100);
                return judge("C10", i) * (result);
            }
        }
        else
        {
            if (player[i].num == 1 && judge("C10", i) == 2)
                return 50;

            if (judge("S12", i))
                result -= 100;
            if (judge("D11", i))
                result += 100;
            return judge("C10", i) * (result);
        }
    }
    else
    {
        if (player[i].num == 1 && judge("C10", i) == 2)
            return 50;
        else
        {
            for (int j = 0; j < player[i].num; j++)
            {
                result += point(player[i].cards[j]);
            }
        }
        return judge("C10", i) * (result);
    }
}

int main()
{
    while (1) //if play() return 0,it means no card have dealed
    {
        clear(); //reset the player[4]
        Deal();
        if (play() == 0)
        {
            return 0;
        }
        //to calculate the points
        for (int i = 0; i < 4; i++)
        {
            int points = calculate(i);
            if (points > 0)
                printf("+%d", points);
            else
                printf("%d", points);
            if (i == 3)
                printf("\n");
            else
                printf(" ");
        }
    }
}