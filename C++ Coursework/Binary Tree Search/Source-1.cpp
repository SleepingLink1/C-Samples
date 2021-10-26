#include <iostream>
#include <cassert>
#include "BinaryTreeType.h"

using namespace std;

int main()
{
	binaryTreeType<int>  treeRoot; 
	cout << "Numbers before Binary Tree: " << "65 55 22 44 61 19 90 10 78 52" << endl;
	treeRoot.insert(65);
	treeRoot.insert(55);
	treeRoot.insert(22);
	treeRoot.insert(44); 
	treeRoot.insert(61);
	treeRoot.insert(19); 
	treeRoot.insert(90); 
	treeRoot.insert(10); 
	treeRoot.insert(78); 
	treeRoot.insert(52);
	cout << endl;

	cout << "The tree height is: " << treeRoot.treeHeight() << endl;
	//now running the singleParent function
	cout << "The number of single Parents is: " << treeRoot.singleParent() << endl;

	system("pause");
	return 0;

}