// 910 TV Game
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
#define ex(x) (x[0] - 'A')

int main() {
	int N, M;
	while(scanf("%d", &N) > 0) {
		int dp[26][26][32] = {0}, special[26] = {0};
		fill(dp, 0);
		vi incoming[26];
		ii edges[26];
		for(int i=0; i < N; i++) {
			char a[5], b[5], c[5], d[5];
			scanf("%s %s %s %s", a, b, c, d);
			dp[ex(a)][ex(b)][1] = 1;
			dp[ex(a)][ex(c)][1] = 1;
			incoming[ex(b)].push_back(ex(a));
			incoming[ex(c)].push_back(ex(a));
			if (ex(a) == 0 && ex(b) == 0 && ex(c) == 0) {
				dp[0][0][1] = 2;
			}
			if  (d[0] == 'x') special[ex(a)] = 1;
		}
		scanf("%d", &M);
		if (special[0]) {
			dp[0][0][0] = 1;
		}
		for(int k=2; k <= M; k++)
			for(int i=0; i < N; i++)
				for(int j=0; j < N; j++)
				 {
					dp[i][j][k] = 0;
					for(int l=0; l < sz(incoming[j]); l++) 
						dp[i][j][k] += dp[i][incoming[j][l]][k-1];
				}
		int ans = 0;
		for(int i=0; i < N; i++)
			if (special[i]) 
				ans += dp[0][i][M];
		printf("%d\n", ans);
	}
	return 0;
}