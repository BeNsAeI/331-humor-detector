/*
-using naive Bayes
-File Format
	-training_text.txt
	-test_text.txt

		*("This is a review",0)
		*('This sentence is false',1)
		*("REF This is a tweet",0)
		("some text",classlabel)
		**IGNORE PUNCTUATION

Pre-processing step

- Convert each sentence into a feature vector plus a class label that is read in by your Naive Bayes algorithm
- Each sentence is a "bag of words"

- The vocabulary consists of the set of all the words that are in the training data
- The vocabulary will now be the features of your training data
- Keep the vocabulary in alphabetical order
- Convert the training AND test data into a set of features
- Let M be the size of your vocabulary
- For each sentence, convert it into a feature vector of size M+1
- Each slot in that feature vector takes the value of 0 or 1
- For the first M slots, if the ith slot has the value 1, it means that the ith word in the vocabulary is present in the sentence; otherwise, if it is 0, then the ith word is not present in the sentence
- Most of the first M feature vector slots will be 0
- Since you are keeping the vocabulary in alphabetical order, the first feature will be the first word alphabetically in the vocabulary
- The (M+1)th slot corresponds to the class label. A 1 in this slot means the message is (extremely) sarcastic while a 0 in this slot means the message is not
- We will refer to the "featurized" training data as the pre-processed training data.
- Output the pre-processed training and testing data to two files called preprocessed_train.txt and preprocessed_test.txt
- The first line should contain the alphabetized words in the vocabulary, separated by commas, followed by a dummy non-word called "classlabel"
- The lines that follow the vocabulary words should be the featurized versions of the sentences in the training data, with the features separated by commas
** Your file should look something like:
	aardvark,almost,anticipate,...,classlabel
	0,1,0,...,0
	1,0,1,...,1

-Classification step should happen right after the pre-processing step (just pass the preprocessed data directly to your classifier. Don't save it out and reload it back in).

Classification step

Build a naive Bayes classifier as described in class.

In the training phase, the naive Bayes classifier reads in the training data along with the training labels and learns the parameters used by the classifier
In the testing phase, the trained naive Bayes classifier classifies the data in the test_text.txt data file. Use the preprocessed data you generated above.
Output the accuracy of the naive Bayes classifier by comparing the predicted class label of each sentence in the test data to the actual class label. The accuracy is the number of correct predictions divided by the total number of predictions.
You may output extra data (e.g. confusion matrices, incorrectly classified sentences) if you think it makes your program's performance more clear, but we should be able to immediately identify and read the accuracy in your output without effort.

A couple of hints:

As mentioned, strip any punctuation and whitespace when you count and/or identify the words.
Make sure that you follow the implementation hints given in the lecture. Specifically, do the probability calculations in log space to prevent numerical instability. Also, use uniform Dirichlet priors to avoid zero counts.
The accuracy for the training data should be very good (>85%), we will not tell you the accuracy of the test data.
Files

Here are the training and test data sets:

Training: training_sentences.txt
Test: test_sentences.txt
Results

**Your results must be stored in a file called results.txt.
Run your classifier by training on training_text.txt then testing on training_text.txt. Report the accuracy in results.txt (along with a comment saying what files you used for the training and testing data). In this situation, you are training and testing on the same data. This is a sanity check: your accuracy should be high i.e. > 85%
Run your classifier by training on training_text.txt then testing on test_text.txt. Report the accuracy in results.txt (along with a comment saying what files you used for the training and testing data). We will not be letting you know beforehand what your performance on the test set should be.

**All of your source code and the results.txt file. Zip everything up with a zip program. To hand in your assignment, go to the TEACH electronic handin site: https://secure.engr.oregonstate.edu:8000
**Pre-processing step (25 points)
**Naive Bayes classifier (25 points)
