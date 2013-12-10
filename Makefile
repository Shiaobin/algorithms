.PHONY: all clean
CPP = g++
srcdir = src
includedir = include
CPPFLAGS = -g2 -Wall
BINS = singlyLinkedList
OBJS = $(BINS:=.o)

all: $(BINS)

$(BINS): %: %.o
	$(CPP) -o $@ $^

%.o: $(srcdir)/%.cpp $(includedir)/%.h
	$(CPP) -I$(includedir) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(BINS) $(OBJS)
