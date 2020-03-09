#include "BinaryTree.h"

BinaryTree::BinaryTree() : Root(nullptr)
{
}

BinaryTree::BinaryTree(int k)
{
	Root = new Link;
	Root->Inner = new Data;
	Root->Inner->key = k;
	Root->Left = nullptr;
	Root->Right = nullptr;
}

BinaryTree::~BinaryTree()
{
	DeleteTree(Root);
}

Link* BinaryTree::GetRoot()
{
	return Root;
}

Data* BinaryTree::Find(int k, Link* fRoot)
{
	if (fRoot == nullptr) return nullptr;

	Link* p = fRoot;
	
	if (p->Inner->key == k) return p->Inner;
	if (p->Inner->key > k) return Find(k, p->Left);
	if (p->Inner->key < k) return Find(k, p->Right);
}

void BinaryTree::Delete(int k, Link* fRoot)
{
	return;
}

void BinaryTree::Insert(int k, Link* fRoot)
{
	Link* pp = fRoot;

	if (pp->Inner->key == k) throw;

	if (pp->Inner->key > k)
		if (pp->Left == nullptr)
		{
			pp->Left = new Link;
			pp->Left->Inner = new Data;
			pp->Left->Inner->key = k;
			pp->Left->Left = nullptr;
			pp->Left->Right = nullptr;

			return;
		}
		else
			return Insert(k, pp->Left);

	if (pp->Inner->key < k)
		if (pp->Right == nullptr)
		{
			pp->Right = new Link;
			pp->Right->Inner = new Data;
			pp->Right->Inner->key = k;
			pp->Right->Left = nullptr;
			pp->Right->Right = nullptr;

			return;
		}
		else
			return Insert(k, pp->Right);
}

void BinaryTree::DeleteTree(Link* fRoot)
{
	if (fRoot == nullptr) return;

	DeleteTree(fRoot->Left);
	DeleteTree(fRoot->Right);

	delete fRoot;
}

void BinaryTree::PrintTree(Link* fRoot)
{
	if (fRoot == nullptr) return;

	PrintTree(fRoot->Left);
	std::cout << fRoot->Inner->key << std::endl;
	PrintTree(fRoot->Right);
}