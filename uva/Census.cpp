// 11297 - Census
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

static const int MAXN = 505;

int A[MAXN][MAXN], tree[4*MAXN][4*MAXN][2];

void build_tree(int x, int a1, int b1, int y, int a2, int b2) {
	if (b1 < a1 || b2 < a2) return;
	if (a1 == b1 && a2 == b2) {
		tree[x][y][0] = tree[x][y][1] = A[a1][a2];
		return;
	}
	int mid1 = (a1+b1)/2, mid2 = (a2+b2)/2;
	build_tree(2*x, a1, mid1, 2*y, a2, mid2); // UL
	build_tree(2*x+1, mid1+1, b1, 2*y, a2, mid2); // UR
	build_tree(2*x, a1, mid1, 2*y+1, mid2+1, b2); // BL
	build_tree(2*x+1, mid1+1, b1, 2*y+1, mid2+1, b2); // BR
	tree[x][y][0] = min(min(tree[2*x][2*y][0], tree[2*x+1][2*y][0]) , min(tree[2*x][2*y+1][0], tree[2*x+1][2*y+1][0]));
	tree[x][y][1] = max(max(tree[2*x][2*y][1], tree[2*x+1][2*y][1]) , max(tree[2*x][2*y+1][1], tree[2*x+1][2*y+1][1]));
}

int query(int x, int a1, int b1, int y, int a2, int b2, int i1, int j1, int i2, int j2, int m) {
	if (b1 < a1 || b2 < a2 || a1 > j1 || a2 > j2 || b1 < i1 || b2 < i2) return (m == 0) ? INF : 0;
	if (a1 >= i1 && b1 <= j1 && a2 >= i2 && b2 <= j2) return tree[x][y][m];
	int mid1 = (a1+b1)/2, mid2 = (a2+b2)/2;
	int UL = query(2*x, a1, mid1, 2*y, a2, mid2, i1, j1, i2, j2, m);
	int UR = query(2*x+1, mid1+1, b1, 2*y, a2, mid2, i1, j1, i2, j2, m);
	int BL = query(2*x, a1, mid1, 2*y+1, mid2+1, b2, i1, j1, i2, j2, m);
	int BR = query(2*x+1, mid1+1, b1, 2*y+1, mid2+1, b2, i1, j1, i2, j2, m);
	if (m == 0)	return min(min(UL, UR), min(BL, BR));
	return max(max(UL, UR) , max(BL, BR));
}

void update(int x, int a1, int b1, int y, int a2, int b2, int i, int j, int val) {
	if (b1 < a1 || b2 < a2 || i > b1 || i < a1 || j > b2 || j < a2) return;
	if (a1 == b1 && a2 == b2 && a1 == i && a2 == j) {
		tree[x][y][0] = tree[x][y][1] = val;
		return;
	}
	int mid1 = (a1+b1)/2, mid2 = (a2+b2)/2;
	update(2*x, a1, mid1, 2*y, a2, mid2, i, j, val); // UL
	update(2*x+1, mid1+1, b1, 2*y, a2, mid2, i, j, val); // UR
	update(2*x, a1, mid1, 2*y+1, mid2+1, b2, i, j, val); // BL
	update(2*x+1, mid1+1, b1, 2*y+1, mid2+1, b2, i, j, val); // BR
	tree[x][y][0] = min(min(tree[2*x][2*y][0], tree[2*x+1][2*y][0]) , min(tree[2*x][2*y+1][0], tree[2*x+1][2*y+1][0]));
	tree[x][y][1] = max(max(tree[2*x][2*y][1], tree[2*x+1][2*y][1]) , max(tree[2*x][2*y+1][1], tree[2*x+1][2*y+1][1]));
}

int main() {
	int N, M, Q;
	scanf("%d %d", &N, &M);
	for(int i=0; i < 4*N; i++)
		for(int j=0; j < 4*M; j++) {
			tree[i][j][0] = INF;
			tree[i][j][1] = 0;
		}
	fill(A, 0);
	for(int i=1; i <= N; i++)
		for(int j=1; j <= M; j++)
			scanf("%d", &A[i][j]);
	build_tree(1, 1, N, 1, 1, M);
	scanf("%d", &Q);
	for(int q=0; q < Q; q++) {
		char s[5];
		scanf("%s", s);
		if (s[0] == 'q') {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d %d\n", query(1, 1, N, 1, 1, M, x1, x2, y1, y2, 1), 
				query(1, 1, N, 1, 1, M, x1, x2, y1, y2, 0));
		}
		else if (s[0] == 'c') {
			int a, b, val;
			scanf("%d %d %d", &a, &b, &val);
			update(1, 1, N, 1, 1, M, a, b, val);
		}
	}
	return 0;
}