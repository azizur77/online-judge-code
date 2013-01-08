// Weights and Measures
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

vector<ii> turtles;
int n = 0;
int dp[6000][6000];
bool cmp(ii a, ii b) { return a.Y < b.Y;  }

int main() {
	int a, b;
	while(scanf("%d %d", &a, &b) > 0) {
		turtles.push_back(mp(a, b));
	}
	n = sz(turtles);
	REP(i, n) REP(j, n+1) dp[i][j] = INF;
	sort(all(turtles), cmp);
	int len = 0;


	REP(i, n) dp[i][1] = turtles[i].X;
	// Find the min weight stack of height j possible on top of each turtle after sorting
	for(int i=0; i < n; i++)
		for(int j=1; j <= n; j++) {
			if (i > 0)
				dp[i][j] = dp[i-1][j];
			if (i > 0 && dp[i-1][j-1] + turtles[i].X <= turtles[i].Y) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + turtles[i].X);
			}
			if (dp[i][j] < INF ) {
				len = max(len, j);
			}
		}
	printf("%d\n", len);
	return 0;
}















