# Mention default target.
all:

%.o: %.cpp
    clang++ -O2 -Wall -Wextra -pedantic -std=c++11 $<

program =euler

euler-objects = \
    main.o \
    EulerUtility.o \
    Euler_15.o \

euler-headers = \
    EulerUtility.h \
    Euler.h \

$(euler-objects): $(euler-headers)

$(program) : $(euler-objects)
    g++ $^ -o $@

clean : rm -f $(program-objects) $(program)

all: make $(program)
