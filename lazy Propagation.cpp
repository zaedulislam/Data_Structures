//loj horrible quries
#include<bits/stdc++.h>

using namespace std;

#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)
#define SFFF(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INF_I        2147483647    //max limit
#define INF          1999999999
#define PB           push_back
#define MEM(n, val)  memset((n), val, sizeof(n))
#define F            first
#define S            second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define ALL(c)       c.begin(), c.end()
#define BOOST        std::ios_base::sync_with_stdio(false);
#define INP          freopen("in.txt", "r", stdin);
#define OUT          freopen("out.txt", "w", stdout);
#define MP           make_pair
#define INIT_RAND    srand(time(NULL))
#define MOD          1000000007
#define MX           (100010)
#define PI           acos(-1.0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef priority_queue<int> PQ;
typedef queue<int> Q;
typedef stringstream SS;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/

int n, q;

LL tree[3 * 100010];
LL lazy[3 * 100010];


void update(LL ll, LL rr, int pos, int t_l, int t_r, LL t_val)    {
    if(lazy[pos])   {
        tree[pos] += (rr - ll + 1) * lazy[pos];
        if(ll != rr)    {
            lazy[pos * 2] += lazy[pos];lazy[(pos * 2) + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if((ll >= t_l) && (rr <= t_r))  {
        tree[pos] += (rr - ll + 1) * t_val;
        if(ll != rr)    {
            lazy[pos * 2] += t_val;lazy[(pos * 2) + 1] += t_val;
        }
        return;
    }
    if((ll > t_r) || (rr < t_l))   {
        return;
    }


    LL mid = (ll + rr) / 2;
    update(ll, mid, pos * 2, t_l, t_r, t_val);
    update(mid + 1, rr, (pos * 2) + 1,  t_l, t_r, t_val);

    tree[pos] = tree[(pos * 2)] + tree[(pos * 2) + 1];
}

LL query(LL ll, LL rr, int pos, int t_l, int t_r)    {
    if(lazy[pos])   {
        tree[pos] += (rr - ll + 1) * lazy[pos];
        if(ll != rr)    {
            lazy[pos * 2] += lazy[pos];lazy[(pos * 2) + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if((ll >= t_l) && (rr <= t_r))  {
        return tree[pos];
    }
    if((ll > t_r) || (rr < t_l))   {
        return 0;
    }

    LL mid = (ll + rr) / 2;
    LL left_v = query(ll, mid, pos * 2, t_l, t_r);
    LL right_v = query(mid + 1, rr, (pos * 2) + 1,  t_l, t_r);
    return left_v + right_v;
}

int main()  {
    //INP;OUT;
    //BOOST;
    int tc;
    //cin >> tc;
    SF(tc);
    FOR(tt, 1, tc)   {
        MEM(lazy, 0);MEM(tree, 0);
        //cin >> n >> q;
        SFF(n, q);
        PF("Case %d:\n", tt);
        FOR(i, 0, q - 1)   {
            int comm;
            //cin >> comm;
            SF(comm);
            if(comm == 0)   {
                int l, r, v;
                //cin >> l >> r >> v;
                SFFF(l, r, v);
                l++, r++;
                update(1, n, 1, l, r, v);
            }
            else if(comm == 1)   {
                int l, r;
                //cin >> l >> r;
                SFF(l, r);
                l++, r++;
                //cout << query(1, n, 1, l, r) << "\n";
                PF("%lld\n", query(1, n, 1, l, r));
            }
        }
    }
    return 0;
}
/*
2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19
*/
