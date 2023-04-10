CC = g++
CFLAGS = -std=c++11

exe_file = exe

DEBUG ?= 1
ifeq($(DEBUG), 1)
  CFLAGS += -g -Wall
else 
  CFLAGS += -DNDEBUG -03
endif

SRCDIR = .
SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name "`.$(SRCEXT)")
OBJECTS = $(SOURCES:.cpp=.o)
DEP = $(OBJECTS:.o=.d)

$(exe_file): $(OBJECTS)
  $(CC) $^ -o $(exe_file)

-include $(DEP)

%.d: %.$(SRCTEXT)
  @$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.$(SRCTEXT)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.out *.o *.d $(exe_file)

PHONY: clean
