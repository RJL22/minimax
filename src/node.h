#pragma once

#include <vector>

struct Node
{
private:
	Node * parent_;
	int value_;
	std::vector<Node*> leaves_;
	bool solveState_;

public:
	//Initialization and deinitialization
	Node(int value);

	~Node();

	//Setters
	void setParent(Node * parent);
	void setValue(int value);
	void setSolveState(bool s);


	// Getters
	Node * getParent();
	int getValue();
	std::vector<Node*> getLeaves();
	bool getSolveState();

	//Adding Leaves
	void addLeaf(int value);

	bool hasLeaves();
};