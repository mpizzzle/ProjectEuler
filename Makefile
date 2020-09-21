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

bigint-objects = \
    BigUnsigned.o \
    BigInteger.o \
    BigIntegerAlgorithms.o \
    BigUnsignedInABase.o \
    BigIntegerUtils.o \

bigint-headers = \
    NumberlikeArray.hh \
    BigUnsigned.hh \
    BigInteger.hh \
    BigIntegerAlgorithms.hh \
    BigUnsignedInABase.hh \
    BigIntegerLibrary.hh \

bigint: $(bigint-objects)

$(bigint-objects): $(bigint-headers)

$(euler-objects): $(euler-headers) $(bigint-headers)

$(program) : $(euler-objects) $(bigint-objects)
    g++ $^ -o $@

clean : rm -f $(bigint-objects) $(program-objects) $(program)

all: make $(program)
