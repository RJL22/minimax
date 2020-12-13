#include "minimax.h"

#include <vector>
#include <iostream>


void min_alg(Node& node)
{
	if (node.getSolveState() == false)
	{
		std::cout << "Going down min" << std::endl;
		std::vector<Node*> nextLayer = node.getLeaves();
		for (int i = 0; i < nextLayer.size(); i++)
			max_alg(*nextLayer[i]);

		min_alg(node);
	} else
	{
		std::cout << "Solving min" << std::endl;
		std::vector<Node*> nextLayer = node.getLeaves();
		int min = INT_MAX;
		for (int i = 0; i < nextLayer.size(); i++) {
			if (nextLayer[i]->getValue() < min) {
				min = nextLayer[i]->getValue();
			}
		}

		std::cout << "Size of min num: " << min << std::endl;
		node.setValue(min);
		node.getParent()->setSolveState(true);
		std::cout << "New value of node:" << node.getValue() << std::endl;
		if (node.getParent() != nullptr)
			node.getParent()->setSolveState(true);
	}
}

void max_alg(Node& node)
{
	if (node.getSolveState() == false)
	{
		std::cout << "Going down max" << std::endl;
		std::vector<Node*> nextLayer = node.getLeaves();
		std::cout << "Layer size ------: " << nextLayer.size() << std::endl;
		for (int i = 0; i < nextLayer.size(); i++)
			min_alg(*nextLayer[i]);

		node.setSolveState(true);
		std::cout << "Current solve state: " << node.getSolveState() << std::endl;
		max_alg(node);
	} else
	{
		std::cout << "Solving max" << std::endl;
		std::vector<Node*> nextLayer = node.getLeaves();
		int max = INT_MIN;
		for (int i = 0; i < nextLayer.size(); i++) {
			std::cout << "Size of num: " << nextLayer[i]->getValue() << std::endl;
			if (nextLayer[i]->getValue() > max) {
				max = nextLayer[i]->getValue();
			}
		}

		std::cout << "Max: " << max << std::endl;

		node.setValue(max);
		if (node.getParent() != nullptr)
			node.getParent()->setSolveState(true);
	}
}


