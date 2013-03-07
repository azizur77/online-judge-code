#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))
#define MAXN 100005

struct node {
	bool ladder, inc, dec, is_null;
	node (bool isn=1, bool i=true, bool d=true, bool l=false) :
		is_null(isn), inc(i), dec(d), ladder(l) {}
};

node T[4*MAXN];
int A[MAXN];


void build_tree(int a, int b, int x) {
	if (a > b) return;
	if (a == b) {
		T[x] = node(0, 1, 1, 1);
		return;
	}	
	int mid = (a+b)/2, lt = 2*x, rt = 2*x+1;

	build_tree(a, mid, lt);
	build_tree(mid+1, b, rt);

	bool incflag = T[lt].inc && T[rt].inc && (A[mid+1] >= A[mid]);
	bool decflag = T[lt].dec && T[rt].dec && (A[mid+1] <= A[mid]);

	bool ladflag = (T[lt].inc && T[rt].dec && A[mid+1] <= A[mid]) ||
		(T[lt].ladder && T[rt].dec && A[mid+1] <= A[mid]) || (incflag ^ decflag) || 
		(T[lt].inc && T[rt].ladder && A[mid] <= A[mid+1]);

	T[x] = node(0, incflag, decflag, ladflag);
}

node query(int a, int b, int x, int i, int j) {
	if (a > b || a > j || b < i) {
		return node(1);
	}
	if (a >= i && b <= j) {
		return T[x];
	}


	int lt = 2*x, rt = 2*x+1, mid = (a+b)/2;

	node left = query(a, mid, lt, i, j);
	node right = query(mid+1, b, rt, i, j);


	node empty(1);

	if (left.is_null && right.is_null) return empty;
	else if (left.is_null) return right;
	else if (right.is_null) return left;

	bool incflag = left.inc && right.inc && (A[mid+1] >= A[mid]);
	bool decflag = left.dec && right.dec && (A[mid+1] <= A[mid]);

	bool ladflag = (left.inc && right.dec && A[mid+1] <= A[mid]) ||
		(left.ladder && right.dec && A[mid+1] <= A[mid]) || (incflag ^ decflag)
		|| (left.inc && right.ladder && A[mid] <= A[mid+1]) ;

	return node(0, incflag, decflag, ladflag);
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i=1; i <= n; i++) cin >> A[i];

	build_tree(1, n, 1);
	for(int i=1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		puts((query(1, n, 1, x, y).ladder) ? "Yes" : "No");
	}
	return 0;
}