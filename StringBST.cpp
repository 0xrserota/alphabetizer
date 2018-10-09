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

#include "StringBST.h"

using namespace std;


/* Default constructor */
StringBST::StringBST()
{
	/* Initialize root */
	root = NULL;
}

/* Parameterized constructor */
StringBST::StringBST(string wordlist[], int arraySize)
{
	/* Initialize root and loop through array, 
		adding each word to the tree. */

	root = NULL;
	for (int i = 0; i < arraySize; ++i) 
	{
		add(wordlist[i]);
	}
}

/* Destructor */
StringBST::~StringBST()
{
	/* Call clear */
	clear();
}

/* Public clear function */
void StringBST::clear()
{
	/* Call recursiveClear helper 
	function on root, then set root to nullptr */

	recursiveClear(root);
	root = NULL;
}

/* Public print function */
void StringBST::print()
{
	/* Call recursivePrint helper 
		function on root */

	recursivePrint(root);
}

/* Public function add(string) */
void StringBST::add(string word)
{
	root = recursiveAdd(root, word);
}

/* Public isEmpty function */
bool StringBST::isEmpty()
{
	/* Check if root points to null
		and return bool */

	if (root == NULL) return true;
	else return false;
}

/* Public size function */
int StringBST::size()
{
	/* return integer result of recursiveSize 
		helper function called on root */

	return recursiveSize(root);
}

/* Private helper function int recursiveSize(node*) */ 
int StringBST::recursiveSize(BSTNode* node)
{
	/* If node points to null, return 0, else do a 
 	pre-order traversal; adding recursive value of each 
 	left and right sub-tree strCount data member to the 
 	return value; this sum gets returned to public size. 
 	Returns the sum of node->strCount of every node in the BST. */

	if (node == NULL) 
		return 0;

	else
	{
		return node->strCount 
			+ recursiveSize(node->left) 
			+ recursiveSize(node->right);
	}
}

/* Private helper function BSTNode* recursiveAdd(BSTNode*, string) */
StringBST::BSTNode *StringBST::recursiveAdd(BSTNode* node, string word)
{
	/* If node points to null, call insertNode to add 
		a new node at this location; else if the current 
		node has the same word value as the word being added,
		increase the strCount at this node and return node, otherwise
		recurse through the left and right subtrees until either base case 
		is fulfilled. */

	if (node == NULL)
		return insertNode(node, word);

	else
	{
		if (node->word == word)
			node->strCount++;

		else if (word < node->word)
			node->left = recursiveAdd(node->left, word);

		else if (word > node->word)
			node->right = recursiveAdd(node->right, word);

		return node;
	}
}

/* Private helper function BSTNode* insertNode*(BSTNode*, string) */
StringBST::BSTNode *StringBST::insertNode(BSTNode* node, string word)
{
	/* Allocate new node pointed to by node, initialize 
	new node's left and right child pointers to null, assign 
	node->word to word being added, intialize node->strCount, 
	return this node. */
	node = new BSTNode;
	node->left = node->right = NULL;
	node->word = word; 
	node->strCount = 1;

	return node;
}

/* Private void recursivePrint(BSTNode*) function */
void StringBST::recursivePrint(BSTNode* node)
{
	/* If node is null, return, else do an in-order traversal print 
	with brackets around each of the subtrees */

	if (node == NULL) return;

	else
	{
		cout << "[";
		recursivePrint(node->left);
		cout << "]";
		cout << " " << node->word << " " << node->strCount << " ";
		cout << "[";
		recursivePrint(node->right);
		cout << "]";
	}
}

/* Private void recursiveClear(BSTNode*) */
void StringBST::recursiveClear(BSTNode *node)
{
	/* If node points to NULL, return, else do a 
		post-order traversal deletion of the whole tree */

	if (node == NULL) return;

	else
	{
		recursiveClear(node->left);
		delete node;
		recursiveClear(node->right);
	}	
}

/* Private bool remove(string) function */
bool StringBST::remove(string word)
{
	if (contains(word))
	{
		root = recursiveRemove(root, word);
		return true;
	}

	else 
		return false;
}

/* Private BSTNode* recursiveRemove(BSTNode*, string) function */
StringBST::BSTNode *StringBST::recursiveRemove(BSTNode *node, string word)
{	
	/* If the node at the word is the same as word, check if the node
		has more than one strCount, else if the node is a leaf, else if
		the leaf has one child, else it must have two children. Call 
		the appropriate function to remove type of node. */

	if (node->word == word)
	{
		if (node->strCount > 1)
			return removeDuplicate(node);

		else if (isLeaf(node))
			return removeLeaf(node);

		else if (isOnceParent(node))
			return removeOnceParent(node);

		else
			return removeTwiceParent(node);
	}

	else if (node->word < word)
		node->right = recursiveRemove(node->right, word);

	// if (node->word > word)
	else 
		node->left = recursiveRemove(node->left, word);	

	return node;
}

/* Private BSTNode* removeDuplicate(BSTNode*) function */
StringBST::BSTNode *StringBST::removeDuplicate(BSTNode *node)
{
	node->strCount--;
	return node;
}

/* Private BSTNode* removeLeaf(BSTNode*) function */
StringBST::BSTNode *StringBST::removeLeaf(BSTNode *node)
{
	delete node;
	return NULL;
}

/* Private BSTNode* removeOnceParent(BSTNode*) function */
StringBST::BSTNode *StringBST::removeOnceParent(BSTNode *node)
{
	if (node->right == NULL)
	{
		BSTNode *child = node->left;
		delete node;
		return child;
	}

	else
	{
		BSTNode *child = node->right;
		delete node;
		return child;
	}	
}

/* Private BSTNode* removeTwiceParent(BSTNode*) function */
StringBST::BSTNode *StringBST::removeTwiceParent(BSTNode *node)
{
	BSTNode *rightMin = findMin(node->right);
	node->word = rightMin->word;
	node->strCount = rightMin->strCount;
	removeBadLeaf(node, node->word);	
	return node;
}

/* Private bool isLeaf(BSTNode*) function */
bool StringBST::isLeaf(BSTNode *node)
{
	if (node->left == NULL and node->right == NULL)
		return true;

	else 
		return false;
}

/* Private bool isOnceParent(BSTNode*) function */
bool StringBST::isOnceParent(BSTNode *node)
{
	if (node->left == NULL xor node->right == NULL)
		return true;

	else 
		return false;
}

/* Private BSTNode* findMin(BSTNode*) function */
StringBST::BSTNode *StringBST::findMin(BSTNode *node)
{
	if (node->left == NULL)
		return node;

	else
		return findMin(node->left);
}

/* Private BSTNode* removeBadLeaf(BSTNode*, string) function */
StringBST::BSTNode *StringBST::removeBadLeaf(BSTNode *node, string word)
{
	/* removes duplicate minimum of right sub-tree of node being removed,
	 which is being replaced with the same node. */
	recursiveRemove(node->right, word);
	return node;
}

/* Private BSTNode* findMax(BSTNode*) function */
StringBST::BSTNode *StringBST::findMax(BSTNode *node)
{
	if (node->right == NULL)
		return node;

	else
		return findMax(node->right);
}

/* Private string getMin() function */
string StringBST::getMin()
{
	if (isEmpty())
		throw runtime_error("empty_tree");

	else
		return findMin(root)->word;
}

/* Private string getMax() function */
string StringBST::getMax()
{
	if (isEmpty())
		throw runtime_error("empty_tree");

	else
		return findMax(root)->word;
}

/* Private void removeMin() function */
void StringBST::removeMin()
{
	if (isEmpty())
		throw runtime_error("empty_tree");

	else
	{
		BSTNode *minNode = findMin(root);
		remove(minNode->word);
	}
}

/* Private void removeMax() function */
void StringBST::removeMax()
{
	if (isEmpty())
		throw runtime_error("empty_tree");

	else
	{
		BSTNode *maxNode = findMax(root);
		remove(maxNode->word);
	}
}

/* Private bool contains(string) function */
bool StringBST::contains(string word)
{
	/* If tree is empty, return false, else call recursiveSearch with root 
	and word as arguments, and if the search returns a NULL pointer, return
	false, else return true since the node was found. */

	if (isEmpty())
		return false;

	else 
	{
		if (recursiveSearch(root, word) == NULL)
			return false;

		else
			return true;
	}
}

/* Private BSTNode* recursiveSearch(BSTNode*, word) function */
StringBST::BSTNode *StringBST::recursiveSearch(BSTNode *node, string word)
{
	/* If node points to a NULL pointer, return NULL. Else if the word at the 
	node is the same as the word being passed as an argument, else if the word
	at the current node is less or more, return the recursive call of 
	recursiveSearch of either the right or left subtree. */


	if (node == NULL)
		return NULL;
	
	else if (node->word == word)
		return node;

	else if (node->word < word)
		return recursiveSearch(node->right, word);

	else //if (node->word > word)
		return recursiveSearch(node->left, word);
}