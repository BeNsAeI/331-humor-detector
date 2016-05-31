# 331 Sarcasm detector

This is my personal repo for CS 331 assignment Sarcasm detector. The assignment was Assigned in the spring term of 2016.

Simplified steps are as follow:

- Read in the training set
- strip punctuation
- chop down every line tosingle words
- swap upeer case letters with lower case letters
- use std::set to build vocabulary and call it "Vocabulary""
- use std::set::insert method to put them in in alphabetical order
- put the last number before ')' into an array
- make another array that is going to be your feature vector and has a size of Vocabulary.size() + 1
- for example if your vocabulary is apple, Donkey, has, is, sad, worm; sentence: "Worm is sad" will be: 0,0,0,1,1,1 and "Donkey has apple" will be: 1,1,1,0,0,0
- now we add the classlable (sarcastic or not sarcastic) to it; sentence: "Worm is sad" will be: 0,0,0,1,1,1,1 and "Donkey has apple" will be: 1,1,1,0,0,0,0
- create two more array with Vocabulary.size() members first one increments the specific word only in sarcastic sentences and the otherone in non sarcastic sentences
- Now let X be set of all the words: X = {x0,x1,x2,x3,...xn} and Y be the the sarcasm: P(Y) = (number of sarcastic lines) / (total lines) and P(not Y) = 1- P(Y)
- now for verdicting the sarcasm we compare P(Y | X) vs P(not Y | X)
- according to Bayes rule it is: P(Y | X) = (P(X|Y) x P(Y))/ P(X). We have no idea what P(X) is but since we are omparing it and not actually calculating it, it ccancells out
- P(X | Y) is where the naeiveness becomes important. we assume they are independent: P(X | Y) = P(x0 | Y) * P(x1 | Y) * P(x2 | Y) * ... * P(xn | Y) 