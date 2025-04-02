// #include<stdio.h>
// int main() {
//     int i, j, n, arr1[10], arr2[10], arr3[10];
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     printf("Enter the elements of the first array: ");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr1[i]);
//     }
//     printf("Enter the elements of the second array: ");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr2[i]);
//     }
//     for (i = 0; i < n; i++) {
//         arr3[i] = arr1[i] + arr2[i];
//     }
//     printf("The parallel array is: ");
//     for (i = 0; i < n; i++) {
//         printf("%d ", arr3[i]);
//     }
//     printf("\n");
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main()
{
    char names[][50] = {"Alice", "Bob", "Charlie"};
    int ages[] = {25, 30, 35};
    int grades[] = {85, 90, 95};

    int numStudents = sizeof(ages) / sizeof(ages[0]);

    printf("Student Data:\n");
    printf("Name\t\tAge\tGrade\n");
    printf("----------------------------\n");
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