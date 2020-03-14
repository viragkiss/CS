output:	part1Driver.o SLinkedList.o StackQueue.o
	g++ part1Driver.o SLinkedList.o StackQueue.o -o output
part1Driver.o: part1Driver.cpp SLinkedList.h StackQueue.h
	g++ -c part1Driver.cpp
SLinkedList.o: SLinkedList.cpp SLinkedList.h
	g++ -c SLinkedList.cpp
StackQueue.o: StackQueue.cpp StackQueue.h SLinkedList.h
	g++ -c StackQueue.cpp
clean:
	rm *.o output