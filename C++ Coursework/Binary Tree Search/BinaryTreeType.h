#pragma once
#include <iostream>
using namespace std;

template<class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType>  *llink;
	nodeType<elemType>  *rlink;
};

template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
	bool isEmpty();
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();
	void insert(const elemType& insertItem);
	int treeHeight();
	int treeNodeCount();
	int treeLeavesCount();
	int singleParent(); //singleParent calls private single function
	void destroyTree();
	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	binaryTreeType();
	~binaryTreeType();

protected:
	nodeType<elemType> *root;

private:
	void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
	void destroy(nodeType<elemType>* &p);
	void inorder(nodeType<elemType> *p);
	void preorder(nodeType<elemType> *p);
	void postorder(nodeType<elemType> *p);
	int height(nodeType<elemType> *p);
	int max(int x, int y);
	int nodeCount(nodeType<elemType> *p);
	int leavesCount(nodeType<elemType> *p);
	int single(nodeType<elemType>* p); //recursive function calls itself to determine how many single 
};

//constructor
template<class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template<class elemType>
bool binaryTreeType<elemType>::isEmpty()
{
	return (root == NULL);
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal()
{
	inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal()
{
	preorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal()
{
	postorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::insert(const elemType& insertItem)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	nodeType<elemType> *newNode;

	trailCurrent = NULL;

	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->llink = nullptr;
	newNode->rlink = nullptr;

	if (root == nullptr)
		root = newNode;
	else
	{
		current = root;
		while (current != nullptr)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				cout << "The item to be inserted is already ";
				cout << "in the tree -- duplicates are not allowed.\n";
				return;
			}
			else if (current->info > insertItem)
				current = current->llink;
			else
				current = current -> rlink;
		}//end while
		if (trailCurrent->info > insertItem)
			trailCurrent->llink = newNode;
		else
		trailCurrent->rlink = newNode;
	}
}//end insert
template<class elemType>
int binaryTreeType<elemType>::treeHeight()
{
	return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount()
{
	return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount()
{
	return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot,
	nodeType<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p)
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p)
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{

	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL)  //if the binary tree is not empty, destroy the binary tree
			destroy(root);

		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else

	return *this;
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

//destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p)
{
	if (p == NULL)
		return 0;
	else
		if ((p->llink == NULL) && (p->rlink == NULL))
			return 1;
		else return (leavesCount(p->llink) + leavesCount(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::single(nodeType<elemType>* p)//single function definition
{
	if (p == NULL) 
		return 0;
	else if (p->llink == NULL && p->rlink != NULL)
		return 1 + single(p->rlink);
	else if (p->llink != NULL && p->rlink == NULL)
		return 1 + single(p->llink);
	else
		return single(p->llink) + single(p->rlink);
	
}

template<class elemType>
int binaryTreeType<elemType>::singleParent()//singleParent definition
{
	//recursive function to use single to count the number of single parents
	return single(root);
}