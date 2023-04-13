#include <iostream>
#include "QuadTree.h"
#include "binarytree.h"


int main()
{
	/*QuadTree center1(treePoint(0, 0), treePoint(8, 8));

	std::unique_ptr<Node> a = std::make_unique<Node>(treePoint(1, 1), 1);
	std::unique_ptr<Node> b = std::make_unique<Node>(treePoint(2, 2), 2);
	std::unique_ptr<Node> c = std::make_unique<Node>(treePoint(3, 3), 3);
	std::unique_ptr<Node> d = std::make_unique<Node>(treePoint(4, 4), 4);

	center1.Insert(a.get());
	center1.Insert(b.get());
	center1.Insert(c.get());
	center1.Insert(d.get());

	std::cout << "Node b:" << center1.Search(treePoint(2, 2))->data;

	return 0;*/

	mytree::Binarytree myTree;

	auto pRoot = myTree.GetRoot();
	pRoot->mData = 1;

	auto pNode = myTree.InsertLeft(pRoot, 2);
	myTree.InsertLeft(pNode, 4);
	myTree.InsertRight(pNode, 5);
	pNode = myTree.InsertRight(pRoot, 3);
	myTree.InsertLeft(pNode, 6);
	myTree.InsertRight(pNode, 7);

	std::cout << "---In Order---" << std::endl;
	myTree.InOrder(pRoot);
	std::cout << std::endl << "---Pre Order---" << std::endl;
	myTree.PreOrder(pRoot);
	std::cout << std::endl << "---Post Order---" << std::endl;
	myTree.PostOrder(pRoot);
	std::cout << std::endl;


	myTree.BreadthFirst();
	std::cout << std::endl;
	myTree.DepthFirst();
	std::cout << std::endl;

	std::cout << myTree.Search(pRoot, 6) << std::endl;
	std::cout << myTree.Sum(pRoot) << std::endl;
}