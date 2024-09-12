#include <stdio.h>
#include <string.h>

typedef struct student
{
    int no;
    float per;
    char name[10];
} student;

void display(student s)
{
    printf("name = %s, roll no. = %d, percentage = %f, \n", s.name, s.no, s.per);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("name = %s, roll no. = %d, percentage = %f, \n",s[i].name,s[i].no,s[i].per);
    // }
}

int main()
{
    student s[5];
    for (int i = 0; i < 5; i++)
    {

        printf("enter your name");
        scanf("%s", &s[i].name);
        printf("enter your roll no");
        scanf("%d", &s[i].no);
        printf("enter your percentage ");
        scanf("%f", &s[i].per);
    }

    return 0;
}