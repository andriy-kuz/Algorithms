/*A digraph is called strongly connected if for any pair of two distinct vertices u
and v there exists a directed path from u to v and a directed path from v to u.In
general, a digraph’s vertices can be partitioned into disjoint maximal subsets
of vertices that are mutually accessible via directed paths; these subsets are
called strongly connected components of the digraph. */

#include <iostream>
#include <vector>
using std::vector;
const int Vertices = 8;

void StronglyConnected(bool G[Vertices][Vertices]);
void DFS(bool G[Vertices][Vertices], int Ver, bool Vis[Vertices], vector<int>& Res);
void ReverseGraph(bool G[Vertices][Vertices]);

int main()
{
	bool G[Vertices][Vertices] =
	{
		{ 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 1, 0, 0, 0, 0 }
	};
	StronglyConnected(G);

}
/*
* Funtion find strongly connected components of the digraph
* @param G Graph adjacency matrix
*/
void StronglyConnected(bool G[Vertices][Vertices])
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


	vector<int> Connected;
	std::memset(Vis, 0, Vertices);
	ReverseGraph(G);
	while (Res.size())
	{
		Vis[Res.back()] = true;
		DFS(G, Res.back(), Vis, Connected);
		for (auto Ver : Connected)
		{
			std::cout << Ver << " ";
			Res.pop_back();
		}
		Connected.clear();
		std::cout << std::endl;
	}
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

void ReverseGraph(bool G[Vertices][Vertices])
{
	for (int i = 0; i < Vertices; i++)
		for (int j = i; j < Vertices; j++)
			std::swap(G[i][j], G[j][i]);
}