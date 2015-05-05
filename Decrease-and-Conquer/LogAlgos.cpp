#include <iostream>
#include <vector>

using namespace std;

int BinarySearch_NonRec(const vector<int>& Ar, int k);
int TernarySearch_NonRec(const vector<int>& Ar, int k);
int MultyplicationLaRus(int n, int m);

int main()
{
	//vector<int> Ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//test
	//for (int i = 0; i <= Ar.size(); i++)
	//	cout << TernarySearch_NonRec(Ar, i) << endl;
	cout << MultyplicationLaRus(13, 94);
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


