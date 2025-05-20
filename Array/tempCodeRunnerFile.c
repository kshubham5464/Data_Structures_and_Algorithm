
#include <stdio.h>
#include <string.h>

int main()
{
    char names[][50] = {"Shubham", "Piyush", "Ankit"};
    int ages[] = {25, 30, 35};
    int grades[] = {85, 90, 95};

    int numStudents = sizeof(ages) / sizeof(ages[0]);

    printf("Student Data:\n");
    printf("Name\t\tAge\tGrade\n");
    printf("------------------------------\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("%s\t\t%d\t%d\n", names[i], ages[i], grades[i]);
    }

    char targetName[50];
    printf("\nEnter the name of the student to find their grade: ");
    scanf("%s", targetName);

    int found = 0;
    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(names[i], targetName) == 0)
        {
            printf("Grade of %s is: %d\n", targetName, grades[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found!\n");
    }

    return 0;
}



