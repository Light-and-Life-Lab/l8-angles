OPTS    = -g -Wall -O2 -march=nocona -mfpmath=sse -msse2 -fPIC
CC = gcc

LIBS = -L./ias_lib/ -ll8ang -lm

INCS =	\
	-I./ias_lib/ \
	-I./

SRC	= \
	l8_angles.c \
	angles_api.c 

OBJ	= $(SRC:.c=.o)

all: l8_angles

l8_angles: ias_lib/libl8ang.a $(OBJ)
	$(CC) $(OPTS) $(INCS) -o $@ $^ $(LIBS) 

ias_lib/libl8ang.a:
	cd ias_lib && make

.c.o: $(INCS) $(LIBS)
	$(CC) $(OPTS) $(INCS) -c -o $@ $<
clean:
	/bin/rm -f *.o
