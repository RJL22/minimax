#include <vector>
#include <iostream>

struct Node
{
public:
	Node * parent_;
	int value_;
	std::vector<Node*> leaves_;
	bool solveState_;

public:
	//Initialization and deinitialization
	Node(int value)
	{
		value_ = value;
		parent_ = nullptr;
		solveState_ = true;
	}

	~Node() 
	{
		for (int i = 0; i < leaves_.size(); i++)
			delete leaves_[i];
	}

	//Setters
	void setParent(Node * parent) { parent_ = parent; }
	void setValue(int value) { value_ = value; }
	void setSolveState(bool s) { solveState_ = s; }


	// Getters
	Node * getParent() { return parent_; }
	int getValue() { return value_; }
	std::vector<Node*> getLeaves() {return leaves_; }
	bool getSolveState() { return solveState_; }

	//Adding Leaves
	void addLeaf(int value)
	{
		Node * leaf = new Node(value);
		leaf->setParent(this);

		// (*parent_).getValue();
		if (this->getParent() != nullptr)
			this->getParent()->setSolveState(false);

		leaves_.push_back(leaf);
	}

	bool hasLeaves()
	{
		if (leaves_.size() == 0)
			return false;
	}
};


void max_alg(Node& node); 

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


