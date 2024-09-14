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
    printf("your data has been stored");
}

void search(student s[], int rollno)
{
    FILE *ptr;

    ptr = fopen("studentdata.txt", "r");
    for (int i = 0; i < 20; i++)
    {
        fscanf(ptr, "%[^,],%d,%f\n", s[i].name, &s[i].no, &s[i].per);
        if (rollno == s[i].no)
        {
            printf("name = %s, roll no. = %d, percentage = %.2f, \n", s[i].name, s[i].no, s[i].per);
        }
    }

    fclose(ptr);
}

int main()
{
    student s[50];
    int n;
    char input[20];
    int rollno;

    printf("type 'dataentry' to enter new student data\n");
    printf("or\n");
    printf("type 'search' to search student data\n");

    scanf("%s", input);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    if (strcmp(input, "dataentry") == 0)
    {
        dataentry(s);
    }
    else if (strcmp(input, "search") == 0)
    {
        printf("enter the roll number of the student\n");
        scanf("%d", &rollno);

        search(s, rollno);
    }

    return 0;
}