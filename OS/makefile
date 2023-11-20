COMPILER = gcc

all : exec

exec : main.o node.o utils.o display.o fifo.o sjf.o rr.o
		$(COMPILER) -o exec main.o node.o utils.o display.o fifo.o sjf.o rr.o

main.o : main.c node.h fifo.h sjf.h rr.h
		$(COMPILER) -c -o main.o main.c

fifo.o : fifo.c fifo.h node.h
		$(COMPILER) -c -o fifo.o fifo.c

sjf.o : sjf.c sjf.h node.h
		$(COMPILER) -c -o sjf.o sjf.c

rr.o : rr.c rr.h node.h
		$(COMPILER) -c -o rr.o rr.c

display.o : display.c display.h node.h
		$(COMPILER) -c -o display.o display.c

utils.o : utils.c utils.h node.h
		$(COMPILER) -c -o utils.o utils.c

node.o : node.c node.h
		$(COMPILER) -c -o node.o node.c

clean:
		rm *.o

mrproper: clean
	rm -f exec