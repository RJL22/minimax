#include "node.h"


Node::Node(int value)
{
	value_ = value;
	parent_ = nullptr;
	solveState_ = true;
}

Node::~Node()
{
	for (int i = 0; i < leaves_.size(); i++)
		delete leaves_[i];	
}

//Setters
void Node::setParent(Node * parent) { parent_ = parent; }
void Node::setValue(int value) { value_ = value; }
void Node::setSolveState(bool s) { solveState_ = s; }

//Getters
Node * Node::getParent() { return parent_; }
int Node::getValue() { return value_; }
std::vector<Node*> Node::getLeaves() { return leaves_; }
bool Node::getSolveState() { return solveState_; }

bool Node::hasLeaves()
{
	if (leaves_.size() == 0)
		return false;
	else
		return true;
}


void Node::addLeaf(int value)
{
	Node * leaf = new Node(value);
	leaf->setParent(this);

	if (this->getParent() != nullptr)
		this->getParent()->setSolveState(false);

	leaves_.push_back(leaf);
}


