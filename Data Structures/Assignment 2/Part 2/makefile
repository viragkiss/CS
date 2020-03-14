output:	part2Driver.o DLCircList.o
	g++ part2Driver.o DLCircList.o -o output
part2Driver.o: part2Driver.cpp DLCircList.h
	g++ -c part2Driver.cpp
DLCircList.o: DLCircList.h DLCircList.cpp
	g++ -c DLCircList.cpp
clean:
	rm *.o output