// BIT / sequences

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
#define MAXN 1000010

ll tree[2][MAXN];
int arr[MAXN], aux[MAXN], indices[MAXN]; 

bool cmp (int a, int b) { return arr[a] < arr[b]; }

ll read(int sel, int idx) {
	ll sum = 0;
	while(idx > 0) {
		sum += tree[sel][idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int sel, int idx, ll val) {
	while(idx < MAXN) {
		tree[sel][idx] += val;
		idx += (idx & -idx);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i, 1, n+1) scanf("%d", &arr[i]);
	fill(tree, 0);
	FOR(i, 1, n+1) aux[i] = i;
	sort(aux+1, aux+n+1, cmp);
	FOR(i, 1, n+1) indices[aux[i]] = i;

	ll tripcnt = 0;

	for(int i=n; i > 0; i--) {
		ll x = read(0, indices[i]-1);
		tripcnt += read(1, indices[i]-1);
		update(0, indices[i], 1);
		update(1, indices[i], x);
	}
	cout << tripcnt << endl;
	return 0;
}