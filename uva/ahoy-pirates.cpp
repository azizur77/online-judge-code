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
#define MAXN 1025000
static const int SET = 1, CLEAR = 2, FLIP = 3;

int T[2*MAXN+1], U[2*MAXN+1];
bool A[MAXN];

void build_tree(int a, int b, int x) {
	if (a > b) return;
	if (a == b) {
		T[x] = A[a];
		return;
	}
	int mid = (a+b) / 2;
	build_tree(a, mid, 2*x);
	build_tree(mid+1, b, 2*x+1);
	T[x] = T[2*x] + T[2*x+1];
}

int invert(int flag) {
	if (flag == SET) return CLEAR;
	if (flag == CLEAR) return SET;
	if (flag == FLIP) return 0;
	return FLIP;
}


void propagate(int a, int b, int x) {
	int lt = 2*x, rt = 2*x+1;
	if (U[x] == SET) 
		T[x] = (b-a+1);
	else if (U[x] == CLEAR)
		T[x] = 0;
	else if (U[x] == FLIP)
		T[x] = (b-a+1) - T[x];
	if (a != b) {
		if (U[x] == SET || U[x] == CLEAR)
			U[lt] = U[rt] = U[x];
		else if (U[x] == FLIP) {
			U[lt] = invert(U[lt]);
			U[rt] = invert(U[rt]);
		}
	}
	U[x] = 0;
}

int query(int a, int b, int x, int i, int j) {
	if (a > b) return 0;
	propagate(a, b, x);
	if (a > j || b < i) return 0;
	if (a >= i && b <= j) {
		return T[x];
	}
	int mid = (a + b) / 2;
	int left = query(a, mid, 2*x, i, j);
	int right = query(mid+1, b, 2*x+1, i, j);
	return left + right;
}

void update(int a, int b, int x, int i, int j, int type) {
	if (a > b) return;
	propagate(a, b, x);
	if (a > j || b < i || a > b) return;
	if (a >= i && b <= j) {
		U[x] = type;
		propagate(a, b, x);
		return;
	}
	int mid = (a+b) / 2, lt = 2*x, rt = 2*x+1;
	update(a, mid, lt, i, j, type);
	update(mid+1, b, rt, i, j, type);
	T[x] = T[lt] + T[rt];
}

int main() {
	int tcases;
	scanf("%d", &tcases);
	for(int c=0; c < tcases; c++) {
		fill(A, 0);
		fill(U, 0);
		fill(T, 0);
		int m, idx=0, times;
		scanf("%d", &m);
		char s[100];
		for(int j=0; j < m; j++) {
			scanf("%d %s", &times, s);
			int l = strlen(s);
			for(int k=0; k < l*times; k++)
				A[++idx] = s[k%l] - '0';
		}
		int n = idx;
		build_tree(1, n, 1);
		int queries, q = 0;
		scanf("%d", &queries);
		printf("Case #%d:\n", c+1);
		for(int j=0; j < queries; j++) {
			int start, stop;
			char type[2];
			scanf("%s %d %d", type, &start, &stop);
			start++;
			stop++;
			switch(type[0]) {
				case 'F': update(1, n, 1, start, stop, SET); break;
				case 'E': update(1, n, 1, start, stop, CLEAR); break;
				case 'I': update(1, n, 1, start, stop, FLIP); break;
				case 'S': printf("Q%d: %d\n", ++q, query(1, n, 1, start, stop));
			}
		}
	}
	return 0;
}