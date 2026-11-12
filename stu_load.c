#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void load(SLL **head)
{
    FILE *file = fopen("student.dat", "r");
    int roll;
    char name[50];
    float percentage;

    if (file == NULL)
        return;

    while (fscanf(file, "%d %49s %f", &roll, name, &percentage) == 3) {
        SLL *new_student = malloc(sizeof(SLL));
        SLL *last;

        if (new_student == NULL) {
            printf("Could not load more records.\n");
            break;
        }

        new_student->rollno = roll;
        snprintf(new_student->name, sizeof(new_student->name), "%s", name);
        new_student->percentage = percentage;
        new_student->next = NULL;

        if (*head == NULL) {
            *head = new_student;
        } else {
            last = *head;
            while (last->next != NULL)
                last = last->next;
            last->next = new_student;
        }
    }

    fclose(file);
}
