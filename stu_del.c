#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static void delete_by_roll(SLL **head, int roll, const char *name)
{
    SLL *current = *head;
    SLL *previous = NULL;

    while (current != NULL) {
        if (current->rollno == roll &&
            (name == NULL || strcmp(current->name, name) == 0)) {
            if (previous == NULL)
                *head = current->next;
            else
                previous->next = current->next;
            free(current);
            printf("Record deleted.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Matching record not found.\n");
}

void del(SLL **head, char choice)
{
    int roll;
    char name[50];
    SLL *current;
    int matches = 0;
    int matching_roll = 0;

    if (*head == NULL) {
        printf("No records found.\n");
        return;
    }

    if (choice == 'r' || choice == 'R') {
        printf("Enter roll number: ");
        if (scanf("%d", &roll) == 1)
            delete_by_roll(head, roll, NULL);
        return;
    }

    if (choice != 'n' && choice != 'N') {
        printf("Choose r or n.\n");
        return;
    }

    printf("Enter name: ");
    if (scanf("%49s", name) != 1)
        return;

    current = *head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%d  %s  %.2f\n", current->rollno,
                   current->name, current->percentage);
            matching_roll = current->rollno;
            matches++;
        }
        current = current->next;
    }

    if (matches == 0) {
        printf("Name not found.\n");
    } else if (matches == 1) {
        delete_by_roll(head, matching_roll, name);
    } else {
        printf("Enter the roll number of the record to delete: ");
        if (scanf("%d", &roll) == 1)
            delete_by_roll(head, roll, name);
    }
}
