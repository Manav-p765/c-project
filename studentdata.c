#include <stdio.h>
#include <string.h>

typedef struct student
{
    int no;
    float per;
    char name[10];
} student;

void dataentry(student s[])
{
    for (int i = 0; i < 5; i++)
    {

        printf("enter your name\n");
        scanf("%s", &s[i].name);
        printf("enter your roll no\n");
        scanf("%d", &s[i].no);
        printf("enter your percentage\n");
        scanf("%f", &s[i].per);
    }
}

void search(student s[], int rollno)
{
    int num = 0;
    for (int i = 0; i < 5; i++)
    {
        if (rollno = s[i].no)
        {
            num = i;
        }
    }
    printf("name = %s, roll no. = %d, percentage = %.2f, \n", s[num].name, s[num].no, s[num].per);
}

int main()
{
    student s[5];
    int n;
    dataentry(s);

    int rollno;
    printf("enter your roll no\n");
    scanf("%d", rollno);

    search(s, rollno);

    return 0;
}