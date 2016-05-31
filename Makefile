all: main.cpp Reader.cpp Const.h Reader.h
	g++ main.cpp Reader.cpp -o out.out 
	./out.out
	#cat preprocessed_train.txt

clean:
	rm -f *.out *.o
	rm -f preprocessed_train.txt
	rm -f Log.txt
	clear
