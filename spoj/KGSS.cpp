#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
#define si(x) scanf("%d", &x)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAXN 110000

ll maxval[2*MAXN], best[2*MAXN], A[MAXN];

struct node {
	ll curmax, maxpair; 
	node (ll a=-INF, ll b=-INF) : curmax(a), maxpair(b) {}
};

void build_tree(int a, int b, int x) {
	if (a > b) return;
	if (a == b) {
		maxval[x] = A[a];
		best[x] = -INF;
		return;
	}
	int lt = 2*x, rt = 2*x+1, mid = (a+b)/2;
	build_tree(a, mid, lt);
	build_tree(mid+1, b, rt);
	maxval[x] = max(maxval[lt], maxval[rt]);
	best[x] = max(max(maxval[lt] + maxval[rt], best[lt]), best[rt]);
}

node query(int a, int b, int x, int i, int j) {
	if (a > b || a > j || b < i) {
		return node();
	} 
	if (a >= i && b <= j) {
		return node(maxval[x], best[x]);
	}
	int lt = 2*x, rt = 2*x+1, mid = (a + b) / 2;
	node nleft = query(a, mid, lt, i, j);
	node nright = query(mid+1, b, rt, i, j);
	return node(
		max(nleft.curmax, nright.curmax), 
		max(max(nleft.curmax + nright.curmax, nleft.maxpair), nright.maxpair));
}

void update(int a, int b, int x, int y, int val) {
	if (a > b || a > y || b < y) return;
	if (a == b && a == y) {
		maxval[x] = val;
		best[x] = -INF;
		return;
	}
	int mid=(a+b)/2, lt=2*x, rt=2*x+1;
	update(a, mid, lt, y, val);
	update(mid+1, b, rt, y, val);
	maxval[x] = max(maxval[lt], maxval[rt]);
	best[x] = max(max(maxval[lt] + maxval[rt], best[lt]), best[rt]);
}

int main() {
	int N, Q;
	si(N);
	REP(i, N) {
		scanf("%lld", &A[i+1]);
	}
	build_tree(1, N, 1);
	si(Q);
	REP(i, Q) {
		int x, y;
		char m[2];
		scanf("%s", m); si(x); si(y);
		if (m[0] == 'Q')
			printf("%lld\n", query(1, N, 1, x, y).maxpair);
		else
			update(1, N, 1, x, y);
	}
}	