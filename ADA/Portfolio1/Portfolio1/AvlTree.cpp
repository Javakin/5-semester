#include "AvlTree.h"
AvlTree::AvlTree() : root{ nullptr }
{ }

AvlTree::AvlTree(const AvlTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}

AvlTree::AvlTree(AvlTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

AvlTree::~AvlTree()
{
	makeEmpty();
}

const int& AvlTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}

const int& AvlTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

/*
int AvlTree::value(const int & x) const
{
	return value(x, root);
	return 0;
}
*/

bool AvlTree::contains(const int& x) const
{
	return contains(x, root);
}

bool AvlTree::isEmpty() const
{
	return root == nullptr;
}

void AvlTree::value(const int& x) const
{
	return value(x, root);
}

void AvlTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root, 0);
}

void AvlTree::makeEmpty()
{
	makeEmpty(root);
}

void AvlTree::insert(const int& x)
{
	insert(x, root);
}

void AvlTree::insert(int&& x)
{
	insert(std::move(x), root);
}

void AvlTree::remove(const int& x)
{
	remove(x, root);
}

void AvlTree::printPreOrder()
{
		printPreOrder(root);
}

void AvlTree::printInOrder()
{
	printInOrder(root);
}

void AvlTree::printPostOrder()
{
	printPostOrder(root);
}

void AvlTree::printLevelOrder()
{
	printLevelOrder(root, 0);
}

void AvlTree::insert(const int& x, AvlNode * & t)
{
	if (t == nullptr)
		t = new AvlNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);

	balance(t);
}

void AvlTree::insert(int && x, AvlNode * & t)
{
	if (t == nullptr)
		t = new AvlNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);

	balance(t);
}

void AvlTree::remove(const int& x, AvlNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing

	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		AvlNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}

	balance(t);
}

void AvlTree::balance(AvlNode * & t)
{
	if (t == nullptr)
		return;

	if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
		if (height(t->left->left) >= height(t->left->right))
			rotateWithLeftChild(t);
		else
			doubleWithLeftChild(t);
	else
		if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
			if (height(t->right->right) >= height(t->right->left))
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);

	t->height = max(height(t->left), height(t->right)) + 1;
}

AvlNode * AvlTree::findMin(AvlNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

AvlNode * AvlTree::findMax(AvlNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

/*
int AvlTree::value(const int & x, AvlNode * t) const
{
	if (t == nullptr)
		return 100;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return 200;
}
*/

bool AvlTree::contains(const int& x, AvlNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void AvlTree::makeEmpty(AvlNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

void AvlTree::value(const int & x, AvlNode * t) const
{	
	if (t == nullptr)
	{
		cout << "This line is empty" << endl;
		value(x, t->right);
	}
	else
		cout << "This line is not empty" << endl;
	{
		//value(x, t->right);
		//while (t != nullptr)
		//{
			cout << t->element << " ";
			if (t == root)
				cout << " <-- root node";
			cout << endl;
			//t->right;
		//}
		cout << endl;
	}
	cout << "This is the height: " << t->height << endl;
	if (t != nullptr)
	{
	//value(x, t->right);
	cout << "Thies are the elements to the right: " << t->element << endl;
	}
	/*if (t == nullptr)

		return false;
	else if (x < t->element)
		return value(x, t->left);
	else if (t->element < x)
		return value(x, t->right);
	else
		return true;*/
}

void AvlTree::printTree(AvlNode *t, int debth) const
{
	if (t != nullptr)
	{
		printTree(t->left, debth + 1);

		// display with tap
		for (int i = 0; i < debth; i++)
			cout << "\t|";
		cout << t->element << endl;
		
		printTree(t->right, debth + 1);
	}
}

AvlNode * AvlTree::clone(AvlNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new AvlNode{ t->element, clone(t->left), clone(t->right), t->height };
}

int AvlTree::height(AvlNode *t) const
{
	return t == nullptr ? -1 : t->height;
}

int AvlTree::max(int lhs, int rhs) const
{
	return lhs > rhs ? lhs : rhs;
}

void AvlTree::rotateWithLeftChild(AvlNode * & k2)
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;
}

void AvlTree::rotateWithRightChild(AvlNode * & k1)
{
	AvlNode *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	k1 = k2;
}

void AvlTree::doubleWithLeftChild(AvlNode * & k3)
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

void AvlTree::doubleWithRightChild(AvlNode * & k1)
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

void AvlTree::printPreOrder(AvlNode * t)
{
	if (t != nullptr)
	{
		cout << t->element << ", ";
		printPreOrder(t->left);
		printPreOrder(t->right);
	}
}

void AvlTree::printInOrder(AvlNode * t)
{
	if (t != nullptr)
	{
		printInOrder(t->left);
		cout << t->element << ", ";
		printInOrder(t->right);
	}
}

void AvlTree::printPostOrder(AvlNode * t)
{
	if (t != nullptr)
	{
		printPostOrder(t->left);
		printPostOrder(t->right);
		cout << t->element << ", ";
	}
}

void AvlTree::printLevelOrder(AvlNode * t, int targetLevel)
{
	// recursive function - repeat for every level in the tree

	// base case
	if (root->height < targetLevel)
		return;

	printLevel(t, targetLevel, 0);
	printLevelOrder(t, targetLevel + 1);
}

void AvlTree::printLevel(AvlNode * t, int targetLevel, int currentLevel)
{
	// recursice function - list all numbers in the trees targetLevel 
	if (t == nullptr)
		return;

	if (currentLevel != targetLevel)
	{
		printLevel(t->left, targetLevel, currentLevel + 1);
		printLevel(t->right, targetLevel, currentLevel + 1);
	}
	if (currentLevel == targetLevel)
		cout << t->element << ", ";
}
