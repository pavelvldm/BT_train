#pragma once
#include <iostream>

struct Data
{
	int key;
};

struct Link
{
	Link* Left;
	Link* Right;
	Link* Parent;
	Data* Inner;
};

class BinaryTree
{
	Link* Root;
public:
	BinaryTree();
	BinaryTree(int k);
	~BinaryTree();

	Link* GetRoot();

	Data* Find(int k, Link* fRoot);
	void Insert(int k, Link* fRoot);
	void Delete(int k);

	Link* MinLink(Link* fR);

	void DeleteTree(Link* fRoot);
	void PrintTree(Link* fRoot);
};
