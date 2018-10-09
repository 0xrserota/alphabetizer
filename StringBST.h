#include <iostream>

#ifndef STRINGBST_H
#define STRINGBST_H

class StringBST {

	public:

		StringBST();
		StringBST(std::string wordlist[], int arraySize);
		~StringBST();
		void clear();
		void print();
		void add(std::string);
		bool isEmpty();
		int size();
		bool remove(std::string);
		bool contains(std::string);
		void removeMax();
		void removeMin();
		std::string getMax();
		std::string getMin();


	private: 

		struct BSTNode {

			std::string word;
			int strCount;
			BSTNode *left;
			BSTNode *right;
		};

		BSTNode *root;

		void recursiveClear(BSTNode*);
		void recursivePrint(BSTNode*);
		BSTNode *recursiveAdd(BSTNode*, std::string);
		BSTNode *insertNode(BSTNode*, std::string);
		int recursiveSize(BSTNode*);

		BSTNode *recursiveRemove(BSTNode*, std::string);
		BSTNode *removeOnceParent(BSTNode*);
		BSTNode *removeTwiceParent(BSTNode*);
		BSTNode *removeLeaf(BSTNode*);
		BSTNode *removeDuplicate(BSTNode*);
		BSTNode *removeBadLeaf(BSTNode*, std::string);

		BSTNode *recursiveSearch(BSTNode*, std::string);
		BSTNode *findMin(BSTNode*);
		BSTNode *findMax(BSTNode*);

		bool isLeaf(BSTNode*);
		bool isOnceParent(BSTNode*);
		
};
#endif