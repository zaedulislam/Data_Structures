
#include <iostream>
#include <cstdio>

#include <string>
#include <cstring>
#include <sstream>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <ctime>

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
#define REV(I,J,K) for(I = J; I > K; I--)
#define SF scanf
#define PF printf
#define PC() printf("Case %d:", caseno++)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define BOOST std::ios_base::sync_with_stdio(0);
using namespace std;

// BEGINTEMPLATE_BY_ZAYED
typedef long long LL;//NOTES:"%lld"
typedef unsigned long long ULL;//NOTES:"%llu"
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64

#define INF 2147483647
#define MOD 1000000007
const double PI = 2 * acos(0.0);
const double EPS = 1e-11;
const int SIZE = 1000 + 10;

vector < int > tree[SIZE]; // tree
int parent[SIZE], L[SIZE], table[SIZE][15]; // Parent/Level/Sparse Table

void dfs(int from, int u, int level)
{
	int I, v;
	parent[u] = from;
	L[u] = level;
	for (I = 0; I < tree[u].size(); I++)
	{
		v = tree[u][I];
		if (v == from)
			continue;
		dfs(u, v, level + 1);
	}
}

void initLCA(int N)
{
	memset(table, -1, sizeof(table));	// initialize the table with -1
	int I, J;
	for (I = 1; I <= N; I++)
		table[I][0] = parent[I];

	for (J = 1; (1 << J) < N; J++)
	{
		for (I = 1; I <= N; I++)
		{
			if (table[I][J - 1] != -1)
				table[I][J] = table[table[I][J - 1]][J - 1];
		}
	}
}

int lcaQuery(int N, int u, int v) // N = number of nodes
{
	int tmp, log, I;
	if (L[u] < L[v])
	{
		tmp = u;
		u = v;
		v = tmp;
	}

	log = 1;
	while (1)
	{
		int next = log + 1;
		if ((1 << next) > L[u])
			break;
		log++;
	}

	for (I = log; I >= 0; I--)
	{
		int x = (1 << I);
		if (L[u] - x >= L[v])
			u = table[u][I];
	}

	if (u == v)
		return u;

	for (I = log; I >= 0; I--)
	{
		if (table[u][I] != -1 && table[u][I] != table[v][I])
		{
			u = table[u][I];
			v = table[v][I];
		}
	}
	return parent[u];
}

int main()
{
	//BOOST
	int tcases, I, J, K, N, n, m, cnt = 0, len, u, v, Q;
	//READ();
	//WRITE();
	SF("%d", &tcases);
	while (tcases--)
	{
		memset(parent, 0, sizeof(parent));
		memset(L, 0, sizeof(L));

		SF("%d", &N);
		for (I = 0; I <= N; I++)
			tree[I].clear();

		for (I = 1; I <= N; I++)
		{
			u = I;
			SF("%d", &m);
			for (K = 0; K < m; K++)
			{
				SF("%d", &v);
				tree[u].push_back(v);
				tree[v].push_back(u);
			}
		}

		dfs(1, 1, 0);
		initLCA(N);

		SF("%d", &Q);
		PC();
		PF("\n");
		for (I = 0; I < Q; I++)
		{
			SF("%d %d", &u, &v);
			PF("%d\n", lcaQuery(N, u, v));
		}
	}
	return 0;
}

/*
1
3
2 2 3
0
0
1
2 3
*/

/*
1
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
5 7
2 7
*/