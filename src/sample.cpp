#include <iostream>
#include "node.h"
#include "minimax.h"

int main()
{
	int branchingFactor = 4;
	Node root = Node(23);

	//First layer of nodes
	for (int i = 0; i < branchingFactor; i++)
		root.addLeaf(3);



	std::vector<Node*> firstLayer = root.getLeaves();


	//Second layer of nodes
	for (int i = 0; i < branchingFactor; i++)
		for (int j = 0; j < branchingFactor; j++)
			firstLayer[i]->addLeaf(j + 2);

	max_alg(root);
	// for (int i = 0; i < firstLayer.size(); i++)
	// 	std::cout << (*firstLayer[i]).getValue() << std::endl;

	return 0;

}