#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <algorithm>
#include <iostream> 
using namespace std;
class AvlNode
{
public:
	AvlNode(int ele, AvlNode *lt, AvlNode *rt, int h = 0)
		: element{ ele }, left{ lt }, right{ rt }, height{ h } { }

	//AvlNode(int && ele, AvlNode *lt, AvlNode *rt, int h = 0)
	//	: element{ std::move(ele) }, left{ lt }, right{ rt }, height{ h } { }
	~AvlNode() {}

	int element;
	AvlNode   *left;
	AvlNode   *right;
	int       height;
};


class AvlTree
{
public:
	AvlTree();
	AvlTree(const AvlTree & rhs);
	AvlTree(AvlTree && rhs);
	~AvlTree();

	const int& findMin() const;
	const int& findMax() const;

	//int value(const int& x) const;

	bool contains(const int& x) const;
	bool isEmpty() const;

	void value(const int& x) const;

	void printTree() const;
	void makeEmpty();
	void insert(const int& x);
	void insert(int&& x);
	void remove(const int& x);

	//int height();

	// solution for protfolio 1
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	void printLevelOrder();

private:

	// solution for portfolio 1
	void printPreOrder(AvlNode *t);
	void printInOrder(AvlNode *t);
	void printPostOrder(AvlNode *t);
	void printLevelOrder(AvlNode *t, int targetLevel);
	void printLevel(AvlNode *t, int targetLevel, int currentLevel);

	AvlNode *root;

	void insert(const int& x, AvlNode * & t);
	void insert(int&& x, AvlNode * & t);
	void remove(const int& x, AvlNode * & t);

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AvlNode * & t);
	AvlNode* findMin(AvlNode *t) const;
	AvlNode* findMax(AvlNode *t) const;
	
	//int value(const int& x, AvlNode *t) const;
	
	bool contains(const int& x, AvlNode *t) const;
	void makeEmpty(AvlNode * & t);

	void value(const int& x, AvlNode *t) const;

	void printTree(AvlNode *t, int debth) const;
	AvlNode* clone(AvlNode *t) const;
	int height(AvlNode *t) const;
	int max(int lhs, int rhs) const;
	void rotateWithLeftChild(AvlNode * & k2);
	void rotateWithRightChild(AvlNode * & k1);
	void doubleWithLeftChild(AvlNode * & k3);
	void doubleWithRightChild(AvlNode * & k1);

};

#endif


