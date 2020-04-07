// Trie (Prefix Tree/Radix Tree).cpp

/// Template by Zayed ///

///************************************************************///
/// #include <bits/stdc++.h>
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
//#include<unordered_map>
#include <set>
//#include<unordered_set>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
///************************************************************///
using namespace std;
int caseno = 1;
///************************************************************///
#define NL '\n'
#define SF scanf
#define PF printf
#define PC() printf("Case %d: ", caseno++)//NOTES:printf
//#define PC cout << "Case "//NOTES:cout
//#define CN cout << caseno++ << ": "//NOTES:cout
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define READ() freopen("input.txt", "r", stdin)
#define WRITE() freopen("output.txt", "w", stdout)

string S;




struct node
{
	bool endmark;
	node *next[26 + 1];

	/// Constructor
	node()
	{
		endmark = false;

		int I;
		for(I = 0; I < 26; I++)
			next[I] = NULL;
	}

};

node *root;



void Insert(string S, int len)
{
	node *curr = root;

	int I;
	for(I = 0; I < len; I++)
	{
		int id = S[I] - 'a';

		if(curr -> next[id] == NULL)
			curr -> next[id] = new node();

		curr = curr -> next[id];
	}

	curr -> endmark = true;
}



bool Search(string S, int len)
{
	node *curr = root;

	int I;
	for(I = 0; I < len; I++)
	{
		int id = S[I] - 'a';

		if(curr -> next[id] == NULL)
			return false;

		curr = curr -> next[id];
	}

	return curr -> endmark;
}



int main()
{
	///READ();
	///WRITE();
	int tcases, I, J, K, N, n, m, cnt = 0, len, a, b, cost = 0, q;

	root = new node();

	cout << "ENTER NUMBE OF WORDS: ";
	cin >> n;

	for(I = 0; I < n; I++)
	{
		cin >> S;
		len = S.length();

		Insert(S, len);
	}

	cout << "ENTER THE NUMBER OF QUERY: ";
	cin >> q;

	for(I = 1; I <= q; I++)
	{
		cin >> S;
		len = S.length();

		if(Search(S, len))
			cout << "FOUND\n";
		else
			cout << "NOT FOUND\n";
	}

	return 0;
}