/*
#
#  COMP 15 HW4 - Tree-Mendous Alphabetizer
#
#  main.cpp
#  Main function for alphabetizer
#  Modified By (UTLN): rserot01
#          On       : 10/26/2017
#
*/

#include "Alphabetizer.h"
#include "StringBST.h"

using namespace std;

/* Main takes commandline arguments */
int main(int argc, char *argv[])
{
	string filename;
	string order;

	/* If arg count is 3, check the args to make sure that the user specified
	a proper order argument. Then, create an instance of Alphabetizer and
	call the parameterized run with proper string args; order gets 
	first argument and filename gets second argument.

	Else if arg count is 1 (just ./alphabetizer), create an instance of 
	alphabetizer and call the interactive (default) run function 

	Else if the number of arguments is not 1 or 3, print a message to cerr
	and return. */

	if (argc == 3)
	{
		order = argv[1];
		filename = argv[2];

		if (not(order == "f" or order == "r"))
		{
			cerr << "Usage:  alphabetizer [order filename]" << endl;
			return 1;
		}

		Alphabetizer alphabetizer;
		alphabetizer.run(filename, order);
	}

	else if (argc == 1)
	{
		Alphabetizer alphabetizer;
		alphabetizer.run();
	}

	else
	{
		cerr << "Usage:  alphabetizer [order filename]" << endl;
		return 1;
	}

}