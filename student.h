#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

void add(SLL **head);
void del(SLL **head, char choice);
void show(SLL *head);
void mod(SLL *head, char choice);
void save(SLL *head);
void load(SLL **head);
void sort(SLL *head, char choice);
void rev(SLL **head);
void del_all(SLL **head);

#endif
