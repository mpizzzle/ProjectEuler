CXX = clang++
CXXFLAGS = -O2 -Wall -Wextra -pedantic -std=c++17 -I.
BOOST = /usr/include/boost
DEPS = Euler.h EulerUtility.h $(BOOST)
ODIR = obj
_OBJ = main.o \
	Euler_1.o Euler_2.o Euler_3.o Euler_4.o Euler_5.o Euler_6.o Euler_7.o Euler_8.o Euler_9.o Euler_10.o \
	Euler_11.o Euler_12.o Euler_13.o Euler_14.o Euler_15.o Euler_16.o Euler_17.o Euler_18.o Euler_19.o Euler_20.o \
	Euler_21.o Euler_22.o Euler_23.o Euler_24.o Euler_25.o Euler_26.o Euler_27.o Euler_28.o Euler_29.o Euler_30.o \
	Euler_31.o Euler_32.o Euler_33.o Euler_34.o Euler_35.o Euler_36.o Euler_37.o Euler_38.o Euler_39.o Euler_40.o \
	Euler_41.o Euler_42.o Euler_43.o Euler_44.o Euler_45.o Euler_46.o Euler_47.o Euler_48.o Euler_49.o Euler_50.o \
	Euler_51.o Euler_52.o Euler_53.o Euler_54.o Euler_55.o Euler_56.o Euler_57.o Euler_58.o Euler_59.o Euler_60.o \
	Euler_61.o Euler_62.o Euler_63.o Euler_64.o Euler_68.o Euler_69.o Euler_70.o \
	Euler_71.o Euler_72.o Euler_73.o Euler_74.o Euler_75.o Euler_76.o Euler_77.o Euler_79.o Euler_80.o \
	Euler_86.o Euler_87.o Euler_90.o \
	Euler_94.o Euler_95.o Euler_100.o \
	EulerUtility.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

euler: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f $(ODIR)/*.o

.PHONY: clean
