# Makefile for P1 - MTFList - Clyde leef


CC = g++
CFLAGS = -Wall -g
SRCS = main.cc


#SRCS = ${wildcard *.cc}
OBJS = ${SRCS:.cc=.o}
#INCLS = ${wildcard *.h}
INCLS = ${SRCS:.cc=.h} main.h MTFList.h Node.h OrderedList.h

p1: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o p1

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cc

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) HONOR Makefile Makefile.dep

clean:
	rm -f $(OBJS) p1 core

include Makefile.dep
