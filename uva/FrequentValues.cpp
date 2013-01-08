// 11235 - Frequent Values
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
const int MAXN = 100005;

struct node {
	int x, y, lb, ra;
	node(int a = 0, int b=0, int c=0, int d=0) {
		x = a;
		y = b;
		lb = c;
		ra = d;
	}
};

int A[MAXN];
vector<node> tree(4*MAXN, node());

void build_tree(int a, int b, int x) {
	if (a > b) return;
	if (a == b) {
		tree[x] = node(a, a, a, a);
		return;
	}
	int lt = 2*x, rt = 2*x+1, mid = (a+b)/2;
	build_tree(a, mid, lt);
	build_tree(mid+1, b, rt);
	int xx, yy, lb, ra;

	lb = (A[a] == A[mid+1]) ? tree[rt].lb : tree[lt].lb;
	ra = (A[mid] == A[b]) ? tree[lt].ra : tree[rt].ra;
	int inter = (A[mid+1] == A[mid]) ? (tree[rt].lb - tree[lt].ra + 1) : 1;
	int eles[] = {lb - a + 1, b - ra + 1, tree[lt].y - tree[lt].x + 1, tree[rt].y - tree[rt].x + 1, inter};
	int cnt = *max_element(eles, eles+5);
	
	if (eles[0] == cnt) {xx = a; yy = lb;}
	else if (eles[1] == cnt) {xx = ra; yy = b;}
	else if (eles[2] == cnt) {xx = tree[lt].x; yy = tree[lt].y;}
	else if (eles[3] == cnt) {xx = tree[rt].x; yy = tree[rt].y;}
	else {xx = tree[lt].ra; yy = tree[rt].lb;}
	
	tree[x] = node(xx, yy, lb, ra);
}

node query(int a, int b, int x, int i, int j) {
	if (a > b || a > j || b < i) return node();
	if (a >= i && b <= j) {
		return tree[x];
	}

	int mid = (a+b) / 2;
	node left = query(a, mid, 2*x, i, j);
	node right = query(mid+1, b, 2*x+1, i, j);
	if (left.x == 0 && right.x == 0) return left;
	if (left.x == 0) return right;
	if (right.x == 0) return left;

	int xx, yy, cnt, lb, ra;
	lb = (A[a] == A[mid+1]) ? right.lb : left.lb;
	ra = (A[mid] == A[b]) ? left.ra : right.ra;
	int inter = (A[mid+1] == A[mid]) ? (min(j, right.lb) - max(i, left.ra) + 1) : 0;
	int lmi = (left.y < i) ? 0 : left.y - max(i, left.x) + 1;
	int rmi = (right.x > j) ? 0 : min(right.y, j) - right.x + 1; 

	int eles[] = {min(lb, j) - max(i, a) + 1, min(b, j) - max(i, ra) + 1, lmi, rmi, inter};
	cnt = *max_element(eles, eles+5);
	
	if (eles[0] == cnt) {xx = max(i, a); yy = min(lb, j);}
	else if (eles[1] == cnt) {xx = max(i, ra); yy = min(b, j);}
	else if (eles[2] == cnt) {xx = max(i, left.x); yy = left.y;}
	else if (eles[3] == cnt) {xx = right.x; yy = min(right.y, j);}
	else {xx = max(left.ra, i); yy = min(right.lb, j);}

	return node(xx, yy, lb, ra);
}

int main() {
	int n, q;
	scanf("%d", &n);
	while(n != 0) {
		scanf("%d", &q);
		for(int i=1; i <= n; i++) scanf("%d", &A[i]);
		build_tree(1, n, 1);
		for(int i=0; i < q; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			node ans = query(1, n, 1, x, y);
			printf("%d\n", ans.y - ans.x + 1);
		}
		scanf("%d", &n);
	}
	return 0;
}