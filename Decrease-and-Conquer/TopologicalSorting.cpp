#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::set;
const int Vertices = 7;

void TopologicSortWithDFS(bool G[Vertices][Vertices]);
void DFS(bool G[Vertices][Vertices], int Ver, bool Vis[Vertices], vector<int>& Res);
void TopologicSortWithSR(bool G[Vertices][Vertices]);
void RemoveVertice(bool G[Vertices][Vertices], int V);

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

	TopologicSortWithSR(G);

	return 0;
}

/*
* Deep-first search
* @param G Graph adjacency matrix
* @param Ver vertice number
* @param Vis array that indicate visited vertices
* @param Res DFS algoritm result
*/
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
/*
* Topological-sorting using DFS algorithm
* @param G Graph adjacency matrix
*/
void TopologicSortWithDFS(bool G[Vertices][Vertices])
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
		std::cout << *Iter << " ";
}
/*
* Topological-sorting using source-removal algorithm
* @param G Graph adjacency matrix
*/
void TopologicSortWithSR(bool G[Vertices][Vertices])
{
	vector<int> Res;
	set<int> DelVerts;
	for (int i = 0; i < Vertices; i++)
	{
		if (DelVerts.find(i) != DelVerts.end())
			continue;

		int j = 0;
		for (; j < Vertices && !G[j][i]; j++);


		if (j == Vertices)
		{
			RemoveVertice(G, i);
			DelVerts.insert(i);
			Res.push_back(i);
			if (DelVerts.size() == Vertices)
				break;
			i = -1;
		}

	}

	if (DelVerts.size() != Vertices)
	{
		std::cout << "Graph has at least one cycle" << std::endl;
		return;
	}
	else
	{
		for (int i = 0; i < Vertices; i++)
			std::cout << Res[i] << " ";
	}
}
/*
* Remove vertice from agency matrix
* @param G Graph adjacency matrix
* @param V number of vertice
*/
void RemoveVertice(bool G[Vertices][Vertices], int V)
{
	for (int i = 0; i < Vertices; i++)
		G[V][i] = 0;
}