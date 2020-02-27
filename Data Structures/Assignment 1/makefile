output:	main.o CStudent.o CCourse.o CDept.o
	g++ main.o CStudent.o CCourse.o CDept.o -o output
main.o: main.cpp CStudent.hpp CCourse.hpp CDept.hpp
	g++ -c main.cpp
CStudent.o: CStudent.cpp CStudent.hpp CCourse.hpp constants.h
	g++ -c CStudent.cpp
CCourse.o: CCourse.cpp CCourse.hpp CStudent.hpp constants.h
	g++ -c CCourse.cpp
CDept.o: CDept.cpp CDept.hpp CCourse.hpp CStudent.hpp constants.h
	g++ -c CDept.cpp
clean:
	rm *.o output
