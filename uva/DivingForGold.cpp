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
#include <bitset>
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

int N, w;
ii treasure[30];
pair<int, bitset<30> > dp[1001][30];

pair<int, bitset<30> > solve(int tleft, int pos) {
	// printf("(dbg) %d %d\n", tleft, pos);
	if (pos == N) return mp(0, bitset<30> ());
	if (dp[tleft][pos].X != -1) return dp[tleft][pos];

	pair<int, bitset<30> > no = solve(tleft, pos + 1);
	dp[tleft][pos] = no;

	if (tleft >= 3 * w * treasure[pos].X) {
		pair<int, bitset<30> > yes = solve(tleft - 3 * w * treasure[pos].X, pos+1);
		yes.X += treasure[pos].Y;
		yes.Y[pos] = 1;
		if (yes.X > no.X) dp[tleft][pos] = yes;
	}
	return dp[tleft][pos];
}


int main() {
	int t;
	bool flag = false;
	while(scanf("%d %d", &t, &w) > 0) {
		if (flag) printf("\n");
		scanf("%d", &N);
		for(int i=0; i < N; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			treasure[i] = ii(x, y);
		}
		// Clear memo
		for(int i=0; i < 30; i++) 
			for(int j=0; j <= t; j++)
				dp[j][i].X = -1;
		pair<int, bitset<30> > ans = solve(t, 0);

		printf("%d\n%d\n", ans.X, ans.Y.count());
		for(int i=0; i < N; i++)
			if (ans.Y[i])
				printf("%d %d\n", treasure[i].X, treasure[i].Y);
		flag = true;
	}
	return 0;
}