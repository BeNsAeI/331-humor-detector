all: main.cpp Reader.cpp Const.h Reader.h Bag.h Bag.cpp
	g++ main.cpp Reader.cpp Bag.cpp -o out.out 
	./out.out
	cat preprocessed_train.txt

clean:
	rm -f *.out *.o
	rm -f preprocessed_train.txt
	clear
