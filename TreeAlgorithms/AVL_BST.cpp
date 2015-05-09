#include "AVL_BST.h"

TreeAVL::TreeAVL() :
Root(nullptr)
{

}

TreeAVL::~TreeAVL()
{

}

void TreeAVL::Insert(int value)
{
	Insert(Root, value);
}

bool TreeAVL::Find(int value)
{
	return Find(Root, value);
}

void TreeAVL::PreorderTraversal()
{
	PreorderTraversal(Root);
}

void TreeAVL::Insert(Node*& node, int value)
{
	if (!node)
	{
		node = new Node;
		node->Data = value;
		node->LChild = nullptr;
		node->RChild = nullptr;
		node->Parent = nullptr;
		return;
	}

	if (node->Data > value)
	{
		Insert(node->LChild, value);
		node->LChild->Parent = node;
	}
	else
	{
		Insert(node->RChild, value);
		node->RChild->Parent = node;
	}

	RebalanceSubRoot(node);
}

void TreeAVL::RebalanceSubRoot(Node* node)
{
	Node* Parent = node->Parent;
	
	if (!Parent)
		return;

	int BalFact = BalanceFactor(Parent);
	if (BalFact == 2)
	{
		if (BalanceFactor(node) == -1)
			RotateLeft(node);
		RotateRight(node);
	}
	else if (BalFact == -2)
	{
		if (BalanceFactor(node) == 1)
			RotateRight(node);
		RotateLeft(node);
	}
}

int TreeAVL::BalanceFactor(Node* node)
{
	return Height(node->LChild) - Height(node->RChild);
}

int TreeAVL::Height(Node* node)
{
	if (!node)
		return -1;
	else
		return std::max(Height(node->LChild), Height(node->RChild)) + 1;
}

//RR calse
void TreeAVL::RotateLeft(Node* SubRoot)
{
	Node* Parent = SubRoot->Parent;
	Node* NewSubRoot = SubRoot->RChild;

	if (Parent->LChild == SubRoot)
		Parent->LChild = NewSubRoot;
	else
		Parent->RChild = NewSubRoot;

	NewSubRoot->Parent = Parent;
	SubRoot->Parent = NewSubRoot;
	SubRoot->RChild = NewSubRoot->LChild;
	NewSubRoot->LChild = SubRoot;
}
//LL case
void TreeAVL::RotateRight(Node* SubRoot)
{
	Node* OldParent = SubRoot->Parent;

	if (OldParent->Parent->LChild == OldParent)
		OldParent->Parent->LChild = SubRoot;
	else
		OldParent->Parent->RChild = SubRoot;

	SubRoot->Parent = OldParent->Parent;
	OldParent->Parent = SubRoot;
	OldParent->LChild = SubRoot->RChild;
	SubRoot->RChild = OldParent;
}

bool TreeAVL::Find(Node* node, int value)
{
	if (!node)
		return false;
	else if (node->Data == value)
		return true;
	else if (node->Data < value)
		return Find(node->RChild, value);
	else
		return Find(node->LChild, value);
}

void TreeAVL::PreorderTraversal(Node* node)
{
	if (node)
	{
		std::cout << node->Data << " ";
		PreorderTraversal(node->LChild);
		PreorderTraversal(node->RChild);
	}
}

int main()
{

	TreeAVL obj;
	obj.Insert(8);
	obj.Insert(3);
	obj.PreorderTraversal();
	std::cout << std::endl;
	obj.Insert(1);
	/*obj.Insert(10);
	obj.Insert(6);
	obj.Insert(4);
	obj.Insert(7);
	obj.Insert(14);
	obj.Insert(13);*/
	obj.PreorderTraversal();
	std::cout << std::endl;
	return 1;
}
