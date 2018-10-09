/*
#
#  COMP 15 HW4 - Tree-Mendous Alphabetizer
#
#  Alphabetizer.cpp
#  Implementation for Alphabetizer class
#  Modified By (UTLN): rserot01
#          On       : 10/26/2017
#
*/

#include "Alphabetizer.h"
#include <fstream>

using namespace std;

/* Alphabetizer Constructor */
Alphabetizer::Alphabetizer()
{
	/* Create an instance of StringBST */
	StringBST tree;		
}

/* Alphabetizer Constructor */
Alphabetizer::~Alphabetizer()
{
	/* nothing to do */
}

/* Public default run function */
void Alphabetizer::run()
{
	/* If not the first input, input from cin gets
	 added to tree, else input gets assigned to order,
	 after loop condition is false, calls print function 
	 with argument order. If the first input is not of the
	 correct form (either "f" or "r") the program exits and 
	 prints a usage message to cerr. */

	bool first = true;
	string order;
	string word;

	while (not cin.eof())
	{
		cin >> word;
		if (cin.eof())
			break;

		if (first)
		{
			order = word;

			if (not(order == "f" or order == "r"))
			{
				cerr << "Usage:  alphabetizer [order filename]" << endl;
				exit(1);
			}
		
			first = false;
		}

		else
			tree.add(word);
	}

	printInOrder("cin", order);
}

/* Public parameterized run function */
void Alphabetizer::run(string filename, string order)
{
	/* Open fstream using filename, while not eof, get string,
		add string to tree. If the file hits an eof flag after the 
		word has been inputted, break from the loop.
		After the loop ends, close the file, and call printInOrder with
		the proper string args. 
		Input checks are handled in main. */

	fstream file;
	file.open(filename);
	string word;

	while (not file.eof())
	{
		
		file >> word;
		if (file.eof())
			break;

		tree.add(word);
	}

	file.close();
	printInOrder(filename, order);
}

/* Private printInOrder function */
void Alphabetizer::printInOrder(string filename, string order)
{
	/* Call either forwardPrint or reversePrint 
		depending on order */

	if (order == "f")
		forwardPrint(filename, order);

	else 
		reversePrint(filename, order);
}

/* Private forwardPrint function */
void Alphabetizer::forwardPrint(string filename, string order)
{
	/* While tree isn't empty, get min, remove min, print min. */

	cout << "[ " << filename << ", "
		<< order << " : ";

	while(not tree.isEmpty())
	{
		string min = tree.getMin();
		tree.removeMin();
		if (tree.isEmpty())
			cout << min << " ";

		else 
			cout << min << ", ";
	}

	cout << "]";
}

/* Private reversePrint function */
void Alphabetizer::reversePrint(string filename, string order)
{
	/* While tree isn't empty, get max, remove max, print max. */

	cout << "[ " << filename << ", "
		<< order << " : ";

	while(not tree.isEmpty())
	{
		string max = tree.getMax();
		tree.removeMax();
		if (tree.isEmpty())
			cout << max << " ";

		else 
			cout << max << ", ";
	}

	cout << "]";
}