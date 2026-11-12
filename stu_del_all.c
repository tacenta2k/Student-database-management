#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void del_all(SLL **head)
{
    SLL *current = *head;

    while (current != NULL) {
        SLL *next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
    printf("All records deleted.\n");
}
