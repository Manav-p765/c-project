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

        printf("enter student name\n");
        scanf("%s", &s[i].name);
        printf("enter student roll no\n");
        scanf("%d", &s[i].no);
        printf("enter student percentage\n");
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

void search(student s[])
{
    FILE *ptr;
    int rollno;

    ptr = fopen("studentdata.txt", "r");

    printf("enter the roll number of the student\n");
    scanf("%d", &rollno);

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
    int command = -1;
    char input1[20];

    while (1)
    {
        printf("Enter command (dataentry, search, or exit):\n ");
        fgets(input, sizeof(input), stdin);

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "dataentry") == 0)
        {
            command = 1;
        }
        else if (strcmp(input, "search") == 0)
        {
            command = 2;
        }
        else if (strcmp(input, "exit") == 0)
        {
            command = 0;
        }

        switch (command)
        {
        case 1:

            while (1)
            {
                dataentry(s);
                printf("enter 'save' to save data or press enter to add another student\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                fgets(input1, sizeof(input1), stdin);

                size_t len = strlen(input1);
                if (len > 0 && input1[len - 1] == '\n')
                {
                    input1[len - 1] = '\0';
                }
                if ((strcmp(input1, "save") == 0))
                {
                    break;
                }
                else
                {
                    printf("next student\n");
                }
            }
            break;

        case 2:
            search(s);
            break;
        case 0:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid command. Please try again.\n");
            break;
        }
    }
    return 0;
}