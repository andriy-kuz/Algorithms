#include <iostream>
#include <vector>

using std::vector;

const int Vertices = 7;

void TopologicSort(bool G[Vertices][Vertices]);
void DFS(bool G[Vertices][Vertices], int Ver, bool Vis[Vertices], vector<int>& Res);


int main()
{
	bool G[Vertices][Vertices] =
	{
		{ 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 1, 0 },
		{ 1, 1, 1, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0 },
	};

	TopologicSort(G);

	return 0;
}


void DFS(bool G[Vertices][Vertices], int Ver, bool Vis[Vertices], vector<int>& Res)
{
	for (int i = 0; i < Vertices; i++)
		if (Ver != i && G[Ver][i] && !Vis[i])
		{
			Vis[i] = true;
			DFS(G, i, Vis, Res);
		}
	Res.push_back(Ver);
}

void TopologicSort(bool G[Vertices][Vertices])
{
	bool Vis[Vertices] = { 0 };
	vector<int> Res;
	for (int i = 0; i < Vertices; i++)
	{
		if (!Vis[i])
		{
			Vis[i] = true;
			DFS(G, i, Vis, Res);
		}
	}

	for (vector<int>::const_reverse_iterator Iter = Res.rbegin(); Iter != Res.rend(); Iter++)
		std::cout << *Iter<<" ";
}