#include <stdio.h>
#include "student.h"

int main(void)
{
    SLL *head = NULL;
    char choice;

    load(&head);

    while (1) {
        printf("\n--- STUDENT RECORD MENU ---\n");
        printf("a - Add a record\n");
        printf("d - Delete a record\n");
        printf("s - Show records\n");
        printf("m - Modify a record\n");
        printf("v - Save records\n");
        printf("t - Sort records\n");
        printf("l - Delete all records\n");
        printf("r - Reverse the list\n");
        printf("e - Exit\n");
        printf("Choice: ");

        if (scanf(" %c", &choice) != 1)
            break;

        switch (choice) {
            case 'a': case 'A':
                add(&head);
                break;
            case 'd': case 'D':
                printf("Delete by roll number (r) or name (n)? ");
                scanf(" %c", &choice);
                del(&head, choice);
                break;
            case 's': case 'S':
                show(head);
                break;
            case 'm': case 'M':
                printf("Find by roll number (r), name (n), or percentage (p)? ");
                scanf(" %c", &choice);
                mod(head, choice);
                break;
            case 'v': case 'V':
                save(head);
                break;
            case 't': case 'T':
                printf("Sort by name (n) or percentage (p)? ");
                scanf(" %c", &choice);
                sort(head, choice);
                break;
            case 'l': case 'L':
                del_all(&head);
                break;
            case 'r': case 'R':
                rev(&head);
                break;
            case 'e': case 'E':
                printf("Save and exit (s) or exit without saving (e)? ");
                scanf(" %c", &choice);
                if (choice == 's' || choice == 'S')
                    save(head);
                else if (choice != 'e' && choice != 'E') {
                    printf("Choose s or e.\n");
                    break;
                }
                del_all(&head);
                return 0;
            default:
                printf("Please choose one of the menu letters.\n");
        }
    }

    del_all(&head);
    return 0;
}
