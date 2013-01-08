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

int n, S[105][105], memo[105][105];

int solve(int x, int y) {
	if (x == y && x == n) return 0;
	int &ret = memo[x][y];
	if (ret != -1) return ret;

	if (x < n && y < n)
		ret = S[x][y] + max(solve(x+1, y), solve(x, y+1));
	else if (x == n) 
		ret = S[x][y] + solve(x, y+1);
	else
		ret = S[x][y] + solve(x+1, y);

	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		fill(S, 0);
		fill(memo, -1);
		scanf("%d", &n);
		for(int i=1; i <= n; i++) 
			for(int j=1; j <= n; j++) 
				scanf("%d", &S[i][j]);
		double res = (1.0 * solve(1, 1)) / (2*n-3);
		if (res >= 0)
			printf("%.6lf\n", res);
		else
			printf("Bad Judges\n");
	}
	return 0;
}