#compiling all
CC_C = gcc
WARN = -Wall
CFLAGS = $(WARN) $(INC) $(LIB)
TARGETS = sim_cache.c
TARGETS_OBJ = sim_.o

all: $(TARGETS_OBJ) 
		$(CC_C) -o sim_cache $(CFLAGS) $(TARGETS_OBJ) -lm

.c.o:
		$(CC_C)	$(CFLAGS) -c $*.c	

clean:
		rm -f *.o sim
clobber:
		rm -f *.o	


	

			