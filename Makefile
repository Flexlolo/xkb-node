CXXFLAGS ?= -O2

PREFIX ?= /usr/local

headers := XKeyboard.h X11Exception.h
sources := XKeyboard.cpp xkb-node.cpp
objects := $(sources:.cpp=.o)
program := xkb-node

all: $(program)

$(objects): %.o: %.cpp $(headers)
	$(CXX) $(CXXFLAGS) -Wall -c -o $@ $<

$(program): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ -lX11

clean:
	rm -f $(program) $(objects)

install: $(program)
	install -D -t $(DESTDIR)$(PREFIX)/bin $(program)