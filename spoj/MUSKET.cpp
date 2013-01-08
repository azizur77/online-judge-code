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

string adj[101];
int n;
int dp[101][101];

inline int mod(int x, int y) { int m = x % y; return (m >= 0) ? m : m + y; }

bool check(int i, int j) {
	i = mod(i, n);
	j = mod(j, n);
	if (dp[i][j] != -1) return dp[i][j];
	if (i > j) return (dp[i][j] = check(i, n-1) && check(0, i-1));
	else if (i == j) return (dp[i][j] = (adj[mod(i-1, n)][i] == '1' || adj[mod(i+1, n)][i] == '1'));
	else if (check(i, j-1) && adj[mod(i-1, n)][j] == '1') return (dp[i][j] = true);
	else if (check(i, j-1) && adj[mod(j+1, n)][j] == '1') return (dp[i][j] = true);
	else if (check(i+1, j) && adj[mod(i-1, n)][i] == '1') return (dp[i][j] = true);
	else if (check(i+1, j) && adj[mod(j+1, n)][i] == '1') return (dp[i][j] = true);
	return false;
}

void task() {
	fill(dp, -1);
	scanf("%d", &n);
	REP(i, n) {
		char s[120];
		scanf("%s", s);
		adj[i] = s;
	}
	bool winners[101];
	fill(winners, false);
	REP(i, n) {
		REP(j, n) {
			if (i != j && adj[i][j] == '1') {
				if (check(i+1, j-1)) {
					winners[i] = true;
					break;
				}
 			}
		}
	}
	int cnt = 0;
	REP(i, n) if (winners[i]) cnt++;
	printf("%d\n", cnt);
	REP(i, n) if (winners[i]) printf("%d\n", i+1);;
	// cout << "dbg" << endl;
	// REP(i, n) REP(j, n) printf("%d %d %d\n", i, j, dp[i][j]);
}


int main() {
	int t;
	cin >> t;
	REP(i, t) task();
	return 0;
}