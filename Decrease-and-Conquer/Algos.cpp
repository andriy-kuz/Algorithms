#include <iostream>
#include <vector>

using namespace std;

int BinarySearch_NonRec(const vector<int>& Ar, int k);
int TernarySearch_NonRec(const vector<int>& Ar, int k);
int MultyplicationLaRus(int n, int m);
int LomutoPartition(vector<int>& Ar, int l, int r);
int QuickSelect(vector<int>& Ar, int l, int r, int k);

int main()
{
	//vector<int> Ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//test
	//for (int i = 0; i <= Ar.size(); i++)
	//	cout << TernarySearch_NonRec(Ar, i) << endl;
	//cout << MultyplicationLaRus(13, 94);
	vector<int> Ar = { 5,7,3,9,2 };
	cout << QuickSelect(Ar, 0, Ar.size()-1, 1);
	return 0;
}

int BinarySearch_NonRec(const vector<int>& Ar, int k)
{
	int l = 0, r = Ar.size() - 1;

	while (l <= r)
	{
		int m = (r + l) / 2;
		if (Ar[m] == k)
			return m;
		else if (k < Ar[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int TernarySearch_NonRec(const vector<int>& Ar, int k)
{
	int l = 0, r = Ar.size()-1;

	while (l <= r)
	{
		int m = (r + l) / 3;
		if (Ar[m] == k)
			return m;
		else if (k < Ar[m])
			r = m - 1;
		else
		{
			m = 2 * (r + l) / 2;
			if (Ar[m] == k)
				return m;
			else if (k < Ar[m])
			{
				r = m - 1;
			}
			else
				l = m + 1;
		}
	}

	return -1;
}

int MultyplicationLaRus(int n, int m)
{
	if (n == 1)
		return m;
	else
	{
		int k = 0;
		if (n % 2)
		{
			k = m;
			--n;
		}

		n = n >> 1;
		m = m << 1;

		return MultyplicationLaRus(n, m) + k;
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

int QuickSelect(vector<int>& Ar, int l, int r, int k)
{
	int s = LomutoPartition(Ar, l, r);
	if (s == k)
		return Ar[s];
	else if (k < s)
		return QuickSelect(Ar, l, s - 1, k);
	else
		return QuickSelect(Ar, s+1, r, k);
}


