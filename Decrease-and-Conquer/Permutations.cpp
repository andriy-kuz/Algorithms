#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

void LexicographicOrder(vector<int>& Ar);
list<vector<bool>> BRGC(int n);
void HeapPermute(vector<int>& Ar, int N);
void PowerSet(set<char> Set);

const int size = 4;

int main()
{
	vector<int> Ar;
	for (int i = 1; i <= size; i++)
		Ar.push_back(i);

	//LexicographicOrder(Ar);
	//HeapPermute(Ar, size);
	PowerSet({'a','b','c'});
	/*list<vector<bool>> L = BRGC(3);
	for (auto l : L)
	{
		for (auto v : l)
			cout << v << ",";
		cout << endl;
	}*/
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
		list < vector<bool>> L2 = L1;

		//for (auto Item : L1)
			//L2.push_front(Item);

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

void HeapPermute(vector<int>& Ar, int N)
{
	if (N == 1)
	{
		for (auto e : Ar)
			cout << e << " ";
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			HeapPermute(Ar, N - 1);
			if (N % 2)
			{
				std::swap(Ar[0], Ar[N - 1]);
			}
			else
			{
				std::swap(Ar[i-1], Ar[N - 1]);
			}

		}
	}
}

void PowerSet(set<char> Set)
{
	if (Set.empty())
	{
		cout << "{}" << endl;
		return;
	}
	else
	{
		set<char>::reverse_iterator a = Set.rbegin();
		char val = *a;
		Set.erase(val);
		PowerSet(Set);
		cout << "{" << val << "}" << endl;
		for (auto ele : Set)
		{
			cout << "{";
			cout << ele << ",";
			cout << val;
			cout << "}" << endl;
		}
		Set.insert(val);
		/*cout << "{";
		for (auto ele : Set)
		{
			cout << ele << ",";
		}
		cout << "}" << endl;*/
	}
}