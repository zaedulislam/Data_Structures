// Segment Tree_Lazy Propagation (Insert, Search, Range_Update).cpp

#include <bits/stdc++.h>
using namespace std;
int caseno = 1;

#define NL '\n'
#define SF scanf
#define PF printf
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define INF (1 << 31) - 1


const int SIZE = 1e5 + 10;
int ar[SIZE], tree[4 * SIZE], lazy[4 * SIZE];




void Init(int node, int b, int e)
{
	if (b == e)
	{
		tree[node] = ar[b];
		return;
	}

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	Init(left, b, mid);
	Init(right, mid + 1, e);

	tree[node] = min(tree[left], tree[right]);

}



void lazyUpdate(int node, int b, int e, int I, int J, int delta)
{
	if (b > e)
		return;

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;


	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];

		if (I != J)
		{
			/// not a leaf node
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0;
	}

	/// no overlap
	if(b > J || e < I)
		return;


	/// Total overlap condition
	if(b >= I && e <= J)
	{
		tree[node] += delta;

		if (I != J)
		{
			/// not a leaf node
			lazy[left] += delta;
			lazy[right] += delta;
		}

		return;
	}

	/// Otherwise partial overlap so look both left and right
	lazyUpdate(left, b, mid, I, J, delta);
	lazyUpdate(right, e, mid + 1, I, J, delta);

	tree[node] = min(tree[left], tree[right]);

}



int Query(int node, int b, int e, int I, int J)
{
	if (b > e)
		return INF;

	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];

		if (I != J)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0;
	}


	/// no overlap
	if(b > J || e < I)
		return INF;

	/// total overlap
	if(b >= I && e <= J)
		return tree[node];

	/// parital overlap
	int ret1 = Query(left, b, mid, I, J);
	int ret2 = Query(right, mid + 1, e, I, J);

	return min(ret1, ret2);

}



int main()
{
	///READ();
	///WRITE();
	int T, I, J, K, N, n, m, k, cnt = 0, len, Q, x, y;

	CLR(ar);
	CLR(tree);
	CLR(lazy);

	cin >> N >> Q;

	for (I = 1; I <= N; I++)
		cin >> ar[I];

	cout << "kireh\n";

	Init(1, 1, N);

//	for (I = 1; I <= 5; I++)
//		cout << tree[I] << ' ';


	for (I = 0; I < Q; I++)
	{
		cin >> n >> x >> y;

		if (n == 1)
		{
			cout << Query(1, 1, N, x, y) << NL;
		}
		else
		{
			cin >> m;
			lazyUpdate(1, 1, N, x, y, m);

		}

	}


	return 0;
}


/*
8 10
3 2 4 1 7 1 3 2
*/



