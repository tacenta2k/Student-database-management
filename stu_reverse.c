#include <stdio.h>
#include "student.h"

void rev(SLL **head)
{
    SLL *previous = NULL;
    SLL *current = *head;

    /* Turn each link around, one at a time. */
    while (current != NULL) {
        SLL *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
    printf("List reversed.\n");
}
