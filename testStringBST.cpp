/*
#
#  COMP 15 HW4 - Tree-Mendous Alphabetizer
#
#  testStringBST.cpp
#  Test function for StringBST class
#  Modified By (UTLN): rserot01
#          On       : 10/26/2017
#
*/

#include "StringBST.h"
#include <string>

using namespace std;

int main()
{
	/*
	StringBST testBST;
	//testBST.print();
	testBST.clear();
	//testBST.print();
	testBST.add("blueberry");
	//testBST.print();
	//testBST.size();
	testBST.add("strawberry");
	testBST.clear();
	//testBST.print();
	testBST.add("plum");
	testBST.print();
	int size = testBST.size();
	cout << "\nSize 1: " << size << endl;
	*/

	string wordlist[] = 
	{ "banana", "apple", "watermelon", "pear", "aardvard", "orange" };
	int size;
	StringBST test2BST(wordlist, 6);
	//test2BST.print();
	//test2BST.clear();
	//test2BST.print(); 
	//test2BST.remove("banana");

	//test2BST.add("blueberry");
	//test2BST.remove("blueberry");
	test2BST.isEmpty();
	//test2BST.print();
	//test2BST.add("strawberry");
	//test2BST.print();
	//test2BST.remove("orange");
	//test2BST.remove("banana");
	//test2BST.remove("watermelon");
	test2BST.removeMin();
	test2BST.removeMin();
	//test2BST.removeMax();
	//test2BST.add("plum");

	test2BST.print();
	size = test2BST.size();
	cout << "\nSize 2: " << size << endl;
	cout << test2BST.getMin() << endl;

	cout << test2BST.getMax() << endl;
	test2BST.removeMax();
	cout << test2BST.getMax() << endl;

	if (test2BST.contains("pear"))
		cout << "true" << endl;

	return 0;
}
