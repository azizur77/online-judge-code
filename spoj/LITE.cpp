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

#define MAXN (1 << 18)

int A[MAXN], T[2*MAXN+1], U[2*MAXN+1];

void build_tree(int a, int b, int x) {
	if (a > b) return;
	if (a == b) {
		T[x] = A[a];
		return;
	}
	int mid = (a+b)/2, lt = 2*x, rt = 2*x+1;
	build_tree(a, mid, lt);
	build_tree(mid+1, b, rt);
	T[x] = T[lt] + T[rt]; 
}

void propagate(int a, int b, int x) {
	if (U[x]) {
		T[x] = (b-a+1) - T[x];
		if (a != b) {
			int lt = 2*x, rt = 2*x+1;
			U[lt] = (U[lt] ^ 1);
			U[rt] = (U[rt] ^ 1);
		}
	}
	U[x] = 0;
}

void flip(int a, int b, int x, int i, int j) {
	if (a > b) return;
	propagate(a, b, x);
	if (b < i || a > j) return;
	if (a >= i && b <= j) {
		U[x] = 1;
		propagate(a, b, x);
		return;
	}
	int lt = 2*x, rt = 2*x+1, mid = (a+b)/2;
	flip(a, mid, lt, i, j);
	flip(mid+1, b, rt, i, j);
	T[x] = T[lt] + T[rt];
}

int query(int a, int b, int x, int i, int j) {
	if (a > b) return 0;
	propagate(a, b, x);
	if (b < i || a > j) return 0;
	if (a >= i && b <= j) return T[x];
	int mid = (a+b)/2;
	int left = query(a, mid, 2*x, i, j);
	int right = query(mid+1, b, 2*x+1, i, j);
	return left + right;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	fill(A, 0);
	fill(U, 0);
	fill(T, 0);
	build_tree(1, N, 1);
	for(int i=0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) flip(1, N, 1, b, c);
		else printf("%d\n", query(1, N, 1, b, c));
	}
	return 0;
}