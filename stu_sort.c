#include <stdio.h>
#include <string.h>
#include "student.h"

void sort(SLL *head, char choice)
{
    SLL *first;
    int changed;

    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    if (choice != 'n' && choice != 'N' && choice != 'p' && choice != 'P') {
        printf("Choose n or p.\n");
        return;
    }

    do {
        changed = 0;
        first = head;
        while (first->next != NULL) {
            SLL *second = first->next;
            int swap = 0;
            int saved_roll;
            char saved_name[50];
            float saved_percentage;

            if ((choice == 'n' || choice == 'N') &&
                strcmp(first->name, second->name) > 0)
                swap = 1;
            if ((choice == 'p' || choice == 'P') &&
                first->percentage < second->percentage)
                swap = 1;

            if (swap) {
                saved_roll = first->rollno;
                strcpy(saved_name, first->name);
                saved_percentage = first->percentage;

                first->rollno = second->rollno;
                strcpy(first->name, second->name);
                first->percentage = second->percentage;

                second->rollno = saved_roll;
                strcpy(second->name, saved_name);
                second->percentage = saved_percentage;
                changed = 1;
            }
            first = first->next;
        }
    } while (changed);

    printf("List sorted.\n");
}
