#include <stdio.h>
#include <string.h>
struct stu
{
    int sid;
    char name[40];
    int score;
};
int main()
{
    struct stu imf;
    FILE *fp = fopen("slist.dat", "r");
    int stuID;
    scanf("%d", &stuID);

    while (1)
    {
        fread(&imf, sizeof(imf), 1, fp);
        if (imf.sid == stuID)
        {
            printf("<学号>%d<姓名>%s<成绩>%d\n", imf.sid, imf.name, imf.score);
            break;
        }
    }

    fclose(fp);
    return 0;
}