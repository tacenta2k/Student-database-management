#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void add(SLL **head)
{
    int roll = 1;
    SLL *current;
    SLL *new_student;

    /* Try roll numbers starting at 1 until an unused one is found. */
    while (1) {
        current = *head;
        while (current != NULL && current->rollno != roll)
            current = current->next;
        if (current == NULL)
            break;
        roll++;
    }

    new_student = malloc(sizeof(SLL));
    if (new_student == NULL) {
        printf("Could not create a student record.\n");
        return;
    }

    new_student->rollno = roll;
    printf("Enter name and percentage: ");
    if (scanf("%49s %f", new_student->name, &new_student->percentage) != 2) {
        printf("Invalid input. Record was not added.\n");
        free(new_student);
        return;
    }

    while (new_student->percentage < 0 || new_student->percentage > 100) {
        printf("Percentage must be from 0 to 100. Enter it again: ");
        if (scanf("%f", &new_student->percentage) != 1) {
            free(new_student);
            return;
        }
    }

    new_student->next = NULL;
    if (*head == NULL) {
        *head = new_student;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_student;
    }

    printf("Record added with roll number %d.\n", roll);
}
