all: main.cpp Reader.cpp Const.h Reader.h
	g++ main.cpp Reader.cpp -o out.out 
	./out.out
clean:
	rm -f *.out *.o
