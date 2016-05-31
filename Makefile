all: main.cpp Reader.cpp Const.h Reader.h Bag.h Bag.cpp
	g++ main.cpp Reader.cpp Bag.cpp -o out.out 
	./out.out
clean:
	rm -f *.out *.o
