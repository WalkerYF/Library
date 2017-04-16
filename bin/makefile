cc=g++
exe=main.out
obj=Library.o test.o
add=-std=c++11 -Wall

$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
Library.o:Library.cpp Library.h
	$(cc) -c Library.cpp $(add)
test.o:test.cpp Library.h
	$(cc) -c test.cpp $(add)
.PHONY : clean
clean:
	-rm -rf *.o main
