// BIT
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
#define MAXN 100500

vector<ii> coders;
ll tree[MAXN];

bool cmp(int a, int b) { return coders[a] < coders[b]; }

ll read(int idx) {
	ll sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, ll val) {
	while(idx < MAXN) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int a, b;
		scanf("%d %d", &a, &b);
		coders.push_back(mp(a, b));
	}
	vi aux (n, 0);
	REP(i, n) aux[i] = i;
	sort(all(aux), cmp);
	vector<ll> result(n, 0);
	int track = 0;
	for(int i=0; i < n; i++) {
		// if (i > 0 && coders[aux[i]] == coders[aux[i-1]])
		// 	result[aux[i]] = read(coders[aux[i-1]].Y-1);
		// else
			if (i > 0 && coders[aux[i]] != coders[aux[i-1]]) track = 0;
			else if (i > 0) track++;
			result[aux[i]] = read(coders[aux[i]].Y) - track;
		update(coders[aux[i]].Y, 1);
	}
	REP(i, n) printf("%lld\n", result[i]);
	return 0;
}