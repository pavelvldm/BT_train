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

Link* BinaryTree::MinLink(Link* fR)
{
	if (fR == nullptr) return fR;

	Link* p = fR;
	while (p->Left != nullptr)
		p = p->Left;

	return p;
}

void BinaryTree::Delete(int k)
{
	if (Root == nullptr) throw;
	
	Link* p = Root;
	Link* pp = Root;
	
	while (p->Inner->key != k)
	{
		if (p->Inner->key > k)
			if (p->Left != nullptr)
			{
				pp = p;
				p = p->Left;
			}
			else
				throw;

		if (p->Inner->key < k)
			if (p->Right != nullptr)
			{
				pp = p;
				p = p->Right;
			}
			else
				throw;
	}

	// нет дочерних звеньев
	if ((p->Left == nullptr) && (p->Right == nullptr))
	{
		if (pp->Left == p)
		{
			pp->Left = nullptr;
			delete p;

			return;
		}
		else
		{
			pp->Right = nullptr;
			delete p;

			return;
		}
	}

	// есть одно дочернее звено
	if ((p->Left == nullptr) && (p->Right != nullptr))
	{
		if (pp->Left == p)
		{
			pp->Left = p->Right;
			p->Right->Parent = pp;
			delete p;

			return;
		}
		else
		{
			pp->Right = p->Right;
			p->Right->Parent = pp;
			delete p;

			return;
		}
	}

	// есть одно дочернее звено
	if ((p->Left != nullptr) && (p->Right == nullptr))
	{
		if (pp->Left == p)
		{
			pp->Left = p->Left;
			p->Left->Parent = pp;
			delete p;

			return;
		}
		else
		{
			pp->Right = p->Left;
			p->Left->Parent = pp;
			delete p;

			return;
		}
	}

	// есть два дочерних звена
	if ((p->Left != nullptr) && (p->Right != nullptr))
	{
		if (pp->Left == p)
		{
			Link* pr = MinLink(p->Right);
			pp->Left = pr;
			pr->Left = p->Left;
			pr->Right = p->Right;
			pr->Parent->Left = nullptr;
			pr->Parent = pp;
			delete p;

			return;
		}
		else
		{
			Link* pr = MinLink(p->Right);
			pp->Right = pr;
			pr->Left = p->Left;
			pr->Right = p->Right;
			pr->Parent->Left = nullptr;
			pr->Parent = pp;
			delete p;

			return;
		}
	}

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
			pp->Left->Parent = pp;

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
			pp->Right->Parent = pp;

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