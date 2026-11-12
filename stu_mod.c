#include <stdio.h>
#include <string.h>
#include "student.h"

static void update_record(SLL *student)
{
    char new_name[50];
    float new_percentage;

    printf("Enter the new name and percentage: ");
    if (scanf("%49s %f", new_name, &new_percentage) != 2) {
        printf("Invalid input. Record was not changed.\n");
        return;
    }

    while (new_percentage < 0 || new_percentage > 100) {
        printf("Percentage must be from 0 to 100. Enter it again: ");
        if (scanf("%f", &new_percentage) != 1)
            return;
    }

    strcpy(student->name, new_name);
    student->percentage = new_percentage;
    printf("Record updated.\n");
}

void mod(SLL *head, char choice)
{
    SLL *current = head;
    SLL *match = NULL;
    int matches = 0;
    int roll;
    float percentage;
    char name[50];

    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    if (choice == 'r' || choice == 'R') {
        printf("Enter roll number: ");
        if (scanf("%d", &roll) != 1)
            return;
        while (current != NULL) {
            if (current->rollno == roll) {
                printf("Current: %d  %s  %.2f\n", current->rollno,
                       current->name, current->percentage);
                update_record(current);
                return;
            }
            current = current->next;
        }
        printf("Roll number not found.\n");
        return;
    }

    if (choice == 'n' || choice == 'N') {
        printf("Enter name: ");
        if (scanf("%49s", name) != 1)
            return;
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                printf("%d  %s  %.2f\n", current->rollno,
                       current->name, current->percentage);
                match = current;
                matches++;
            }
            current = current->next;
        }
    } else if (choice == 'p' || choice == 'P') {
        printf("Enter percentage: ");
        if (scanf("%f", &percentage) != 1)
            return;
        while (current != NULL) {
            if (current->percentage == percentage) {
                printf("%d  %s  %.2f\n", current->rollno,
                       current->name, current->percentage);
                match = current;
                matches++;
            }
            current = current->next;
        }
    } else {
        printf("Choose r, n, or p.\n");
        return;
    }

    if (matches == 0) {
        printf("No matching record found.\n");
        return;
    }

    if (matches > 1) {
        printf("Enter the roll number of the record to modify: ");
        if (scanf("%d", &roll) != 1)
            return;
        match = head;
        while (match != NULL && match->rollno != roll)
            match = match->next;
        if (match == NULL) {
            printf("Roll number not found.\n");
            return;
        }
        if ((choice == 'n' || choice == 'N') && strcmp(match->name, name) != 0) {
            printf("That roll number does not match the name.\n");
            return;
        }
        if ((choice == 'p' || choice == 'P') && match->percentage != percentage) {
            printf("That roll number does not match the percentage.\n");
            return;
        }
    }

    update_record(match);
}
