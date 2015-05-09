#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node {
	int data;
	Node *Left;
	Node *Right;
};

typedef void (TraversallCallBack)(Node*&);

class Tree {
	Tree(const Tree& ){};
	Tree& operator=(const Tree&) {};
public:
	Tree();
	~Tree();
	void Insert(int data);
	bool Delete(int data);
	bool Find(int data);
	int LevelsCount();
	int LeafsCount();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	int InternalPath();
	void PrintAllPaths();
	void PrintAllLeafsPaths();
	int MaxDiameterOfTree();
	int Height();
	bool IsHasPathSum(int value);
	int TreePermutationCount(int n);
private:
	void PreorderTraversal(Node *node);
	void InorderTraversal(Node *node);
	void PostorderTraversal(Node *node, TraversallCallBack f);
	void Insert(Node*& root, int data);
	bool Delete(Node*& node, int data);
	Node* Find(Node* node, int data);
	int LevelsCount(Node* root);
	int LeafsCount(Node* root);
	const Node* FindMin(Node* node);
	const Node* FindMax(Node* node);
	int InternalPath(Node* node, int val = 0);
	void PrintAllPaths(Node* node, vector<int>& path);
	void PrintAllLeafsPaths(Node* node, vector<int>& path);
	int MaxDiameterOfTree(Node* node, vector<int>& path);
	int Height(Node* node);
	bool IsHasPathSum(Node* node, int value, int& sum);
	static void PrintNodeFunc(Node*& node);
	static void FreeNodeFunc(Node*& node);
private:
	Node *Root;
};