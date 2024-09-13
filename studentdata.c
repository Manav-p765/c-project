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
    FILE *ptr;
    ptr = fopen("studentdata.txt", "a");
    for (int i = 0; i < 1; i++)
    {

        printf("enter your name\n");
        scanf("%s", &s[i].name);
        printf("enter your roll no\n");
        scanf("%d", &s[i].no);
        printf("enter your percentage\n");
        scanf("%f", &s[i].per);

        fprintf(ptr, "%s", s[i].name);
        fprintf(ptr, "%s", ",");
        fprintf(ptr, "%d", s[i].no);
        fprintf(ptr, "%s", ",");
        fprintf(ptr, "%.2f\n", s[i].per);
        // fprintf(ptr, "%c", "\n");
    }
    fclose(ptr);
}

int search(student s[], int rollno, int num)
{
    FILE *ptr1;

    ptr1 = fopen("studentdata.txt", "r");
    for (int i = 0; i < 20; i++)
    {
        fscanf(ptr1, "%d", s[i].no);
        if (rollno == s[i].no)
        {
            return num = i - 1;
        }
    }

    fclose(ptr1);
}

int main()
{
    student s[50];
    int n;
    int num = 0;

    dataentry(s);

    int rollno;
    printf("enter your roll no\n");
    scanf("%d", rollno);

    search(s, rollno, num);

    printf("name = %s, roll no. = %d, percentage = %.2f, \n", s[num].name, s[num].no, s[num].per);

    return 0;
}