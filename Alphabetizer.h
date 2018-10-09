/*
#
#  COMP 15 HW4 - Tree-Mendous Alphabetizer
#
#  Alpbabetizer.h
#  Interface for Alphabetizer class
#  Modified By (UTLN): rserot01
#          On       : 10/26/2017
#
*/

#include <iostream>
#include "StringBST.h"

#ifndef ALPHABETIZER_H
#define ALPHABETIZER_H


class Alphabetizer {

	public:

		Alphabetizer();
		~Alphabetizer();
		void run();
		void run(std::string, std::string);

	private:

		void printInOrder(std::string, std::string);
		void forwardPrint(std::string, std::string);
		void reversePrint(std::string, std::string);

		StringBST tree;
};

#endif


