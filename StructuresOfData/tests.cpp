#include "BinaryTree.h"

int main()
{
	int i;

	std::cout << "Set tree: ";
	std::cin >> i;

	BinaryTree testTree(i);
	Link* testRoot = testTree.GetRoot();

	while (i)
	{
		std::cin >> i;
		if (i)
			testTree.Insert(i, testRoot);
	}

	std::cout << "\n Tree: \n";
	testTree.PrintTree(testTree.GetRoot());
	std::cout << "\n";

	return 0;
}