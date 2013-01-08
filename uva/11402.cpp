// Ahoy! Pirates - Segment Tree with Lazy Propagation
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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
#define si(x) scanf("%d", &x)

#define MAXN 1025000
#define FSET 1
#define FCLR 2
#define FFLIP 3

int A[MAXN], T[2 * MAXN + 1], flag[2 * MAXN + 1];

void build_tree(int b, int e, int node) {
	if (b > e) return;
	if (b == e) {
		T[node] = A[b];
		return;
	}
	int mid = (b+e)/2;
	build_tree(b, mid, node*2);
	build_tree(mid+1, e, node*2+1);
	T[node] = T[node*2] + T[node*2+1];
}

int get_flip(int state) {
	if (state == FFLIP) return 0;
	else if (state = FCLR) return FSET;
	else if (state = FSET) return FCLR;
	return FFLIP;
}

void propagate(int b, int e, int node) {
	int lt = 2*node;
	int rt = lt+1;
	if (flag[node] == FSET) {
		T[node] = e - b + 1;
		flag[lt] = flag[rt] = FSET;
	}	
	else if (flag[node] == FCLR) {
		T[node] = 0;
		flag[lt] = flag[rt] = FCLR;
	}
	else if (flag[node] == FFLIP) {
		T[node] = (e-b+1) - T[node];
		flag[lt] = get_flip(flag[lt]);
		flag[rt] = get_flip(flag[rt]);
	}
	flag[node] = 0;
}


int query(int b, int e, int node, int qb, int qe) {
	if (e < qb || b > qe) return 0;
	propagate(b, e, node);
	int mid = (b+e) / 2;
	if (b >= qb && e <= qe) return T[node];
	int left = query(b, mid, 2*node, qb, qe);
	int right = query(mid+1, e, 2*node+1, qb, qe);
	return left + right;
}

void update(int b, int e, int node, int qb, int qe, int state) {
	if (e < qb || b > qe) return;
	propagate(b, e, node);
	int mid = (b+e) / 2;
	if (b >= qb && e <= qe) {
		if (state == FFLIP) {
			flag[2*node] = get_flip(flag[2*node]);
			flag[2*node+1] = get_flip(flag[2*node+1]);
			T[node] = (e-b+1) - T[node];
		}
		else {
			flag[2*node] = flag[2*node+1] = state;
			T[node] = (state == FSET) ? (e-b+1) : 0;
		}
		return;
	}
	update(b, mid, 2*node, qb, qe, state);
	update(mid+1, e, 2*node+1, qb, qe, state);
}

void task(int scen) {
	int m, times, idx = 1, q, qnum=0, start, stop;
	char s[100], st[2];
	fill(T, 0);
	fill(A, 0);
	fill(flag, 0);
	si(m);
	REP(i, m) {
		scanf("%d %s", &times, s);
		int l = strlen(s);
		REP(j, l*times) {
			A[idx++] = s[j % l] - '0';
		}
	}
	int n = idx-1;
	build_tree(1, n, 1);
	si(q);
	if (q) printf("Case #%d:\n", scen);
	REP(i, q) {
		scanf("%s %d %d", st, &start, &stop);
		start++;
		stop++;
		switch(st[0]) {
			case 'F': update(1, n, 1, start, stop, FSET);
					  break;
			case 'E': update(1, n, 1, start, stop, FCLR);
					  break;
			case 'I': update(1, n, 1, start, stop, FFLIP);
					  break;
			case 'S': printf("Q%d: %d\n", ++qnum, query(1, n, 1, start, stop));
		}
	}
}


int main() {
	int cases;
	si(cases);
	REP(i, cases) task(i+1);
	return 0;
}