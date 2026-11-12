#include <stdio.h>
#include "student.h"

void save(SLL *head)
{
    FILE *file = fopen("student.dat", "w");

    if (file == NULL) {
        printf("Could not open student.dat for saving.\n");
        return;
    }

    while (head != NULL) {
        fprintf(file, "%d %s %.2f\n", head->rollno,
                head->name, head->percentage);
        head = head->next;
    }

    fclose(file);
    printf("Records saved.\n");
}
