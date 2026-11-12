#include <stdio.h>
#include "student.h"

void show(SLL *head)
{
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    printf("---------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "Roll No.", "Name", "Percentage");
    printf("---------------------------------------------\n");

    while (head != NULL) {
        printf("%-10d %-20s %-10.2f\n", head->rollno,
               head->name, head->percentage);
        head = head->next;
    }

    printf("---------------------------------------------\n");
}
