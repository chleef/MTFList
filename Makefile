# Makefile for P1 - MTFList - Clyde leef

CC = g++
CFLAGS = -pg -Wall -std=c++11

SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

p1: $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o p1

$(OBJS):
	$(CPP) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CPP) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep

clean:
	rm -f *.o a.out core

include Makefile.dep
