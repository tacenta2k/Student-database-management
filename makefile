student: stu_main.o stu_add.o stu_del.o stu_del_all.o stu_reverse.o stu_save.o stu_load.o stu_show.o stu_sort.o stu_mod.o
	cc stu_main.o stu_add.o stu_del.o stu_del_all.o stu_reverse.o stu_save.o stu_load.o stu_show.o stu_sort.o stu_mod.o -o student

stu_main.o: stu_main.c
	cc -c stu_main.c
stu_add.o: stu_add.c
	cc -c stu_add.c
stu_del.o: stu_del.c
	cc -c stu_del.c
stu_del_all.o: stu_del_all.c
	cc -c stu_del_all.c
stu_reverse.o: stu_reverse.c
	cc -c stu_reverse.c
stu_save.o: stu_save.c
	cc -c stu_save.c
stu_load.o: stu_load.c
	cc -c stu_load.c
stu_show.o: stu_show.c
	cc -c stu_show.c
stu_sort.o: stu_sort.c
	cc -c stu_sort.c
stu_mod.o: stu_mod.c
	cc -c stu_mod.c

clear:
	@echo "cleaning up..."
	@rm -f *.o student
