// Segment Tree (Insert,Search,Update).cpp
#include <iostream>
#include <cstdio>

int caseno = 1;
#define NL '\n'
using namespace std;
const int SIZE = 50;

// fflush(stdout);
int ar[SIZE] = { 0,1 ,2, 3, 4, 5 }, tree[4 * SIZE];

void init(int node, int start, int end)
{
	// node = Current node/ (start, end) = Current range
	if (start == end)
	{
		// Leaf node will have a single element
		tree[node] = ar[start];
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (start + end) / 2;
	// Recurse on the left child
	init(left, start, mid);
	// Recurse on the right child
	init(right, mid + 1, end);
	// Internal node will have the sum of both of its children
	tree[node] = tree[left] + tree[right];
}

int query(int node, int start, int end, int I, int J)
{
	if (I > end || J < start)
	{
		// Range represented by a node is completely outside the given range
		return 0;
	}
	
	if (start >= I && end <= J)
	{
		// Range represented by a node is completely inside the given range
		return tree[node];
	}
	// Range represented by a node is partially inside and partially outside the given range
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (start + end) / 2;
	int p1 = query(left, start, mid, I, J);
	int p2 = query(right, mid + 1, end, I, J);
	return p1 + p2;
}

void update(int node, int start, int end, int I, int newValue)
{
	if (I > end || I < start)
		return;
	if (start >= I && end <= I)
	{
		// Range represented by a node is completely inside the given range
		// Leaf node
		tree[node] = newValue;
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (start + end) / 2;
	update(left, start, mid, I, newValue);
	update(right, mid + 1, end, I, newValue);
	// Internal node will have the sum of both of its children
	tree[node] = tree[left] + tree[right];
}

int main()
{
	//std::ios_base::sync_with_stdio(0);
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	//READ();
	//WRITE();
	//cin >> n;

	init(1, 1, 5);
	update(1, 1, 5, 2, 10);
	//cout << query(1, 1, 7, 2, 6) << NL;

	return 0;
}

