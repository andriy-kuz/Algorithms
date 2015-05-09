#include "BinarySearchTree.h"

Tree::Tree()
{
	Root = NULL;

}

Tree::~Tree()
{
	PostorderTraversal(Root, FreeNodeFunc);
}

void Tree::Insert(int data)
{
	Insert(Root, data);
}


void Tree::Insert(Node*& root, int data)
{
	if (!root)
	{
		root = new Node;
		root->data = data;
		root->Left = NULL;
		root->Right = NULL;
	}
	else if (data < root->data)
		Insert(root->Left, data);
	else 
		Insert(root->Right, data);
}

bool Tree::Delete(int data)
{
	return Delete(Root, data);
}

bool Tree::Find(int data)
{
	return Find(Root, data) ? true : false;
}

int Tree::LevelsCount()
{
	return LevelsCount(Root);
}

int Tree::LeafsCount()
{
	return LeafsCount(Root);
}

void Tree::PreorderTraversal()
{
	if (!Root)
		cout << "Tree is empty" << endl;
	else 
		PreorderTraversal(Root);
}

void Tree::InorderTraversal()
{
	if (!Root)
		cout << "Tree is empty" << endl;
	else
		InorderTraversal(Root);
}

void Tree::PostorderTraversal()
{
	if (!Root)
		cout << "Tree is empty" << endl;
	else
		PostorderTraversal(Root, PrintNodeFunc);
}

int Tree::InternalPath()
{
	return InternalPath(Root);
}

void Tree::PrintAllPaths()
{
	vector<int> path;
	PrintAllPaths(Root, path);
}

void Tree::PrintAllLeafsPaths()
{
	vector<int> path;
	PrintAllLeafsPaths(Root, path);
}

int Tree::MaxDiameterOfTree()
{
	vector<int> path;
	return MaxDiameterOfTree(Root, path);
}

int Tree::Height()
{
	return Height(Root);
}

bool Tree::IsHasPathSum(int value)
{
	int sum = 0;
	return IsHasPathSum(Root, value, sum);
}

int Tree::TreePermutationCount(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += TreePermutationCount(i - 1)*TreePermutationCount(n - i);
		return sum;
	}
}

void Tree::PreorderTraversal(Node *node)
{
	if (node)
	{
		cout << node->data << " ";
		PreorderTraversal(node->Left);
		PreorderTraversal(node->Right);
	}
}

void Tree::InorderTraversal(Node *node)
{
	if (node)
	{
		InorderTraversal(node->Left);
		cout << node->data << " ";
		InorderTraversal(node->Right);
	}
}

void Tree::PostorderTraversal(Node *node, TraversallCallBack f)
{
	if (node)
	{
		PostorderTraversal(node->Left, f);
		PostorderTraversal(node->Right, f);
		f(node);
	}
}

int Tree::LevelsCount(Node* root)
{
	if (!root)
		return 0;
	else
	{
		return std::max(LevelsCount(root->Left), LevelsCount(root->Right)) + 1;
	}
}

int Tree::LeafsCount(Node* root)
{
	if (!root)
		return 0;
	else if (!root->Left && !root->Right)
		return 1;
	else
		return LeafsCount(root->Left) + LeafsCount(root->Right);
}

const Node* Tree::FindMin(Node* node)
{
	while (node->Left)
		node = node->Left;

	return node;
}

const Node* Tree::FindMax(Node* node)
{
	while (node->Right)
		node = node->Right;

	return node;
}

int Tree::InternalPath(Node* node, int val)
{
	if (!node)
		return 0;
	else if (!node->Left && !node->Right)
		return 0;
	else
		return val + InternalPath(node->Left, val + 1) + InternalPath(node->Right, val + 1);
}

void Tree::PrintAllPaths(Node* node, vector<int>& path)
{
	if (node)
	{
		path.push_back(node->data);
		PrintAllPaths(node->Left, path);
		PrintAllPaths(node->Right, path);
		for (auto v : path)
			cout << v << " ";
		cout << endl;
		path.pop_back();
	}
}

void Tree::PrintAllLeafsPaths(Node* node, vector<int>& path)
{
	if (node)
	{
		path.push_back(node->data);
		PrintAllLeafsPaths(node->Left, path);
		PrintAllLeafsPaths(node->Right, path);
		if (!node->Right && !node->Left) {
			for (auto v : path)
				cout << v << " ";
			cout << endl;
		}
		path.pop_back();
	}
}

int Tree::MaxDiameterOfTree(Node* node, vector<int>& path)
{
	if (!node)
	{
		return 0;
	}
	else
	{
		int lH = Height(node->Left);
		int rH = Height(node->Right);
		int lD = MaxDiameterOfTree(node->Left, path);
		int rD = MaxDiameterOfTree(node->Right, path);
		return std::max(lH+rH+1, max(lD, rD)) +1;
	}
}

int Tree::Height(Node* node)
{
	if (!node)
		return -1;
	else
		return std::max(Height(node->Left), Height(node->Right)) + 1;
}

bool Tree::IsHasPathSum(Node* node, int value, int& sum)
{
	if (sum == value)
		return true;
	if (node)
	{
		sum += node->data;
		bool res = IsHasPathSum(node->Left, value, sum) || IsHasPathSum(node->Right, value, sum);
		sum -= node->data;
		return  res;
	}
	return false;
}

void Tree::PrintNodeFunc(Node*& node)
{
	cout << node->data<<" ";
}

void Tree::FreeNodeFunc(Node*& node)
{
	delete node;
	node = NULL;
}

bool Tree::Delete(Node*& node, int data)
{
	if (!node)
		return false;

	if (data > node->data)
		return Delete(node->Right, data);
	else if (data < node->data)
		return Delete(node->Left, data);
	else if (data == node->data)
	{
		if (!node->Left && !node->Right)
		{
			delete node;
			node = NULL;
		}
		else if (!node->Left)
		{
			Node* TmpPtr = node->Right;
			delete node;
			node = TmpPtr;
		}
		else if (!node->Right)
		{
			Node* TmpPtr = node->Left;
			delete node;
			node = TmpPtr;
		}
		else
		{
			if (!node->Right->Left)
			{
				Node* L = node->Left;
				Node* R = node->Right;
				delete node;
				node = R;
				node->Left = L;
			}
			else
			{
				const Node* Min = FindMin(node->Right);	
				node->data = Min->data;
				Delete(node->Right, Min->data);
			}
		}
		return true;
	}

}

Node* Tree::Find(Node* node, int key)
{
	if (!node)
		return NULL;
	else if (key == node->data)
		return node;
	else if (key > node->data)
		return Find(node->Right, key);
	else 
		return Find(node->Left, key);
}

int main()
{
	Tree obj;
	obj.Insert(8);
	obj.Insert(3);
	obj.Insert(1);
	obj.Insert(10);
	obj.Insert(6);
	obj.Insert(4);
	obj.Insert(7);
	obj.Insert(14);
	obj.Insert(13);
	obj.PostorderTraversal();
	cout << endl;
	cout << obj.TreePermutationCount(2);
	//cout << endl << obj.InternalPath();
	return 0;
}