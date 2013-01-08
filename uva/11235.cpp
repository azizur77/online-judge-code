// Frequent Values 
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
#define ctz __builtin_ctz
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int dp[100010][20], nums[100010];

int log2(int n) {
	int dl = 0;
	while(n > 0) { n >>= 1; dl++; }
	return dl;
}

int log22(int n) {
	int dl = 0;
	while(n > 1) { n >>= 1; dl++; }
	return dl;
}


void task(int n) {
	fill(dp, 0);
	fill(nums, 0);
	int q;
	scanf("%d", &q);
	REP(i, n) scanf("%d", &nums[i]);

	// Fill frequencies
	int idx = 0;
	while(idx < n) {
		int cnt = 100010;
		int j = idx + 1;
		while(j < n && nums[idx] == nums[j]) { j++; cnt++; }
		for(int k=idx; k < j; k++) dp[k][0] = cnt;
		idx = j;
	}

	int bits = log2(n);
	for(int k = 1; k <= bits; k++) {
		for(int i=0; i < n; i++) {
			dp[i][k] = max(dp[i][k-1], dp[min(n-1, i+(1<<(k-1)))][k-1]);
		}
	}	

	for(int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int bno = log22(b - a + 1);
		printf("%d\n", bno);
		a--; b--;
		int ans = max(dp[a][bno], dp[b - (1 << bno) + 1][bno]);
		printf("%d\n", ans);
	}

}

int main() {
	int n;
	while(scanf("%d", &n)) {
		if (n == 0) break;
		task(n);
	}
	return 0;
}