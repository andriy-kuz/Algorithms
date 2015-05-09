#include <iostream>
#include <algorithm>

struct Node
{
	int Data;
	Node* Parent;
	Node* LChild;
	Node* RChild;
};

class TreeAVL
{
	TreeAVL(const TreeAVL&){};
	TreeAVL& operator=(const TreeAVL&){};
public:
	TreeAVL();
	~TreeAVL();
	void Insert(int value);
	void Delete(int value);
	bool Find(int value);
	void PreorderTraversal();
private:
	void Insert(Node*& node, int value);
	void RebalanceSubRoot(Node* node);
	int BalanceFactor(Node* node);
	int Height(Node* node);
	//RR calse
	void RotateLeft(Node* node);
	//LL case
	void RotateRight(Node* node);
	bool Find(Node* node,int value);
	void PreorderTraversal(Node* node);
private:
	Node *Root;
};