CC = gcc
CFLAGS = -O4 -std=c99
LDFLAGS = 
OBJECTS = solver.o level.o level_info.o global.o position.o hashtable.o move.o queue.o allocator.o solving_routine.o deadlock_table.o solution.o crs.o
DRAW_OBJECTS = draw_solutions.o level.o level_info.o global.o position.o hashtable.o move.o queue.o allocator.o solving_routine.o deadlock_table.o solution.o crs.o

all : solver draw clean 

solver : $(OBJECTS)

draw : $(DRAW_OBJECTS)
	$(CC) $(DRAW_OBJECTS) -o draw_solutions

%.o : %c %h

clean:
	rm *.o

tags : *.c *.h
	ctags *.c *.h

gzip : *.c *.h Makefile
	tar cvzf solver.tar.gz *.c *.h levels documentation/*.tex documentation/*.pdf documentation/Makefile Makefile

todo:
	grep "TODO" *.c *.h
