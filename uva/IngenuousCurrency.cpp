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
#define cube(x) ((x)*(x)*(x))

int main() {
	ll dp[10001][22] = {{0}}, x;
	dp[0][0] = 1LL;
	for(int i=0; i <= 10000; i++)
		for(int j=1; j < 22; j++) 
			dp[i][j] = dp[i][j-1] + ((i >= cube(j)) ? dp[i-cube(j)][j] : 0);
	while(scanf("%lld", &x) > 0) {
		printf("%lld\n", dp[x][21]);
	}
}