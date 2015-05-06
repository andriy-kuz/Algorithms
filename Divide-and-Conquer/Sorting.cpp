#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindMax(vector<int>& Ar, int l, int r);

void MergeSort(vector<int>& Ar);
void QuickSort(vector<int>& Ar, int l, int r);
int LomutoPartition(vector<int>& Ar, int l, int r);
int HoarePartition(vector<int>& Ar, int l, int r);

int main()
{
	vector<int> Ar = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	QuickSort(Ar, 0, Ar.size()-1);
	for (auto v : Ar)
		cout << v << ",";
	cout << endl;
	//cout << FindMax(Ar, 0, Ar.size()-1);
	return 1;
}

void MergeSort(vector<int>& Ar)
{
	if (Ar.size() == 1)
		return;
	else
	{
		int m = Ar.size() / 2;
		vector<int> B(Ar.begin(), Ar.begin() + m), C(Ar.begin() + m, Ar.end());
		MergeSort(B);
		MergeSort(C);
		std::merge(B.begin(), B.end(), C.begin(), C.end(), Ar.begin());
	}
}

int FindMax(vector<int>& Ar, int l, int r)
{
	if (l == r)
		return l;
	else
	{
		int m = (l + r) / 2;
		int i1 = FindMax(Ar, l, m);
		int i2 = FindMax(Ar, m + 1, r);
		return Ar[i1] > Ar[i2] ? i1 : i2;
	}
}

void QuickSort(vector<int>& Ar, int l, int r)
{
	if (l < r)
	{
		int s = HoarePartition(Ar, l, r);/*LomutoPartition(Ar, l, r)*/;
		QuickSort(Ar, l, s - 1);
		QuickSort(Ar, s + 1, r);
	}
}

int LomutoPartition(vector<int>& Ar, int l, int r)
{
	int p = Ar[l], s = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (Ar[i] < p)
		{
			std::swap(Ar[++s], Ar[i]);
		}
	}
	std::swap(Ar[l], Ar[s]);
	return s;
}

int HoarePartition(vector<int>& Ar, int l, int r)
{
	if (l >= r)
		return r;

	int p = Ar[l], s = l, i = l + 1, j = r;
	while (i < j)
	{
		while (i < r &&  Ar[i] < p)
			++i;
		
		while (j > l && Ar[j] > p)
			--j;

		std::swap(Ar[i], Ar[j]);
	}

	std::swap(Ar[i], Ar[j]); // undo swap
	std::swap(Ar[j], Ar[l]);
	return j;
}
