/*
#
#  COMP 15 HW4 - Tree-Mendous Alphabetizer
#
#  testAlphabetizer.cpp
#  Test function for Alphabetizer class
#  Modified By (UTLN): rserot01
#          On       : 10/26/2017
#
*/

#include "Alphabetizer.h"

int main()
{
	Alphabetizer alphabetizer;

	alphabetizer.run();

	alphabetizer.run("some_words.txt", "f");
	alphabetizer.run("some_words.txt", "r");

	alphabetizer.run("lots_of_words.txt", "f");
	alphabetizer.run("lots_of_words.txt", "r");

	return 0;
}