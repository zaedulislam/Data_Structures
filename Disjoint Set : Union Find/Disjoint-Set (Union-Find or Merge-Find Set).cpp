// Disjoint-Set (Union-Find or Merge-Find Set).cpp
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;
int parent[SIZE];




void MakeSet(int N)
{
	for(int I = 0; I <= N; I++)
		parent[I] = I;
}



int Find(int r)
{
	if(parent[r] == r)
		return r;

	int p = Find(parent[r]);
	return p;
}



/// Optimiztion: Alternate Find funtion for path compression technique
int PathCompression(int r)
{
    if(parent[r] == r)
		return r;

	parent[r] = Find(parent[r]);
	return parent[r];
}



void Union(int a, int b)
{
	int u = Find(a);
	int v = Find(b);

	if(u == v)
		cout << "They are already friends\n";

	parent[u] = v;
}



int main()
{
	int T, I, J, K, N, n, m, k, cnt = 0, len, u, v;

	cin >> N;

	MakeSet(N);

	for(I = 1; I <= N; I++)
	{
		cin >> u >> v;

		Union(u, v);
	}


	return 0;
}
