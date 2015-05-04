#include <iostream>
#include <vector>
#include <list>
using namespace std;

void LexicographicOrder(vector<int>& Ar);
list<vector<bool>> BRGC(int n);

const int size = 3;

int main()
{
	vector<int> Ar;;
	for (int i = 1; i <= size; i++)
		Ar.push_back(i);

	LexicographicOrder(Ar);
	return 0;
}
/*
* Function generates permutations in lexicographic order
* @param Ar array a0<a1<a2....an-1<an
*/
void LexicographicOrder(vector<int>& Ar)
{
	vector<int>::iterator k = Ar.end()-1;
	
	while (k != Ar.begin())
	{
		if (*k < *(k - 1))
			k--;
		else
			break;
	}

	if (k == Ar.begin())
	{
		for (auto Elem : Ar)
		{
			cout << Elem << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		//find min value that bigget than k
		vector<int>::iterator a = k - 1, an = k;
		while (k != Ar.end())
		{
			if (*k > *a && *an > *k)
			{
				an = k;
			}
			k++;
		}
		//
		std::swap(*a, *an);
		std::reverse(a+1, Ar.end());

		for (auto Elem : Ar)
		{
			cout << Elem << " ";
		}
		cout << endl;
		LexicographicOrder(Ar);
	}
}
/*
* Functions implement binary reflected Gray code
* @param n set size
* @return A list of all bit strings of length n composing the Gray code
*/
list<vector<bool>> BRGC(int n)
{
	if (n == 1)
	{
		//retur list with two vectors: {false} and {true}
		return{ { false }, { true } };
	}
	else
	{
		list < vector<bool>> L1 = BRGC(n - 1);
		list < vector<bool>> L2;

		for (auto Item : L1)
			L2.push_front(Item);

		for (list<vector<bool>>::iterator L1Iter = L1.begin(), L2Iter = L2.begin(); L1Iter != L1.end(); L1Iter++, L2Iter++)
		{
			L1Iter->push_back(false);
			L2Iter->push_back(true);
		}

		for (auto Item : L2)
			L1.push_back(Item);

		return L1;
	}
}
