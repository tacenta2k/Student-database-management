# Student Record Management System

A small menu-based C project for managing student names, roll numbers, and percentages. It follows the supplied assignment: records are stored in a singly linked list and saved in `student.dat`.

The list operations use ordinary `while` loops. There is no recursion. Each student is one node: it stores the student's details and a `next` pointer to the following node. The program uses `malloc()` to add a node and `free()` to remove it.

## Build and run

In a terminal opened in this folder, run:

```sh
make
./student
```

To remove the executable and object files:

```sh
make clear
```

## Menu options

- `a` — add a student. The program chooses the smallest unused roll number.
- `d` — delete by roll number or name. For a name, choose the matching roll number.
- `s` — show all students.
- `m` — modify by roll number, name, or percentage.
- `v` — save the records to `student.dat`.
- `t` — sort by name (A to Z) or percentage (highest first).
- `l` — delete all records from memory.
- `r` — reverse the order of the list.
- `e` — choose `s` to save and exit or `e` to exit without saving.

Enter names as one word (for example, `Rahul`). Percentages must be between 0 and 100.

## Files

- `stu_main.c` — menu and program flow.
- `stu_add.c`, `stu_del.c`, `stu_mod.c` — add, delete, and modify records.
- `stu_show.c`, `stu_sort.c`, `stu_reverse.c` — display, sort, and reverse the list.
- `stu_save.c`, `stu_load.c` — save and load records.
- `stu_del_all.c` — free all list nodes.
- `student.h` — student structure and function declarations.
- `makefile` — builds the `student` program.

The program loads `student.dat` at startup if that file exists. Deleting records from memory does not change the saved file unless you save again.
