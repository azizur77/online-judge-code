// Unidirectional TSP

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
typedef long long ll;
typedef pair<ll, ll> ii;

inline int mod(int m, int n) { int p = m % n; return (p < 0) ? (p + n) : p; }

void task(int m, int n) {
	ll weights[12][105];
	REP(i, m) REP(j, n) scanf("%lld", &weights[i][j]);
	ll dp[12][105], choice[12][105];
	fill(dp, 0LL);
	for(int j = n-1; j >= 0; j--) {
		for(int i = 0; i < m; i++) {
			ii minpair[] = {
				mp(dp[mod(i-1, m)][j+1], mod(i-1, m)), 
				mp(dp[i][j+1], i), 
				mp(dp[mod(i+1, m)][j+1], mod(i+1, m))
			};
			sort(minpair, minpair+3);
			choice[i][j] = minpair[0].Y;
			dp[i][j] = weights[i][j] + minpair[0].X;
		}
	}
	int idx = 0, mincost = dp[0][0];
	for(int i=0; i < m; i++) {
		if (dp[i][0] < mincost) {
			idx = i;
			mincost = dp[i][0];
		}
	}
	vi result(1, idx);
	int cx = idx;
	for(int j=0; j < n-1; j++) {
		result.push_back(choice[cx][j]);
		cx = choice[cx][j];
	}
	// REP(i, m) {
	// 	REP(j, n+1) printf("%4d ", dp[i][j]); 
	// 	printf("\n");
	// }

	REP(i, n-1) printf("%d ", result[i]+1);
	printf("%d\n", result[n-1] + 1);
	printf("%lld\n", dp[0][idx]);
}	

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) > 0) {
		task(a, b);
	}
	return 0;
}