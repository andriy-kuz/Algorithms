#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<vector<bool>> BRGC(int n);

int main()
{
	list<vector<bool>> L = BRGC(3);
	for (auto LItem : L)
	{
		for (auto VItem : LItem)
		{
			cout << VItem << " ";
		}
		cout << endl;
	}

	return 0;
}

list<vector<bool>> BRGC(int n)
{
	if (n == 1)
	{
		//retur list with two elemts -> two vectors: {false} and {true}
		return { { false }, { true } };
	}
	else
	{
		list < vector<bool>> L1 = BRGC(n - 1);
		list < vector<bool>> L2 = L1;
		L2.reverse();
		for (auto Item : L1)
			Item.push_back(false);

		for (auto Item : L2)
		{
			Item.push_back(true);
			L1.push_back(Item);
		}
		return L1;
	}
}