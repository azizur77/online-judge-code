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

int L, lectures[1001], C, N;
ii dp[1001][501];

int di(int tleft) {
	if (tleft == 0) return 0;
	else if (tleft <= 10) return -C;
	return (tleft - 10) * (tleft - 10);
} 

ii solve(int lecno, int tleft) {
	if (lecno == N) return ii (tleft < L, di(tleft));
	if (dp[lecno][tleft].X != INF) return dp[lecno][tleft];

	ii skip, noskip;
	if (tleft < L) {
		skip = solve(lecno, L);
		skip.X += 1;
		skip.Y += di(tleft);
		if (tleft >= lectures[lecno]) {
			noskip = solve(lecno+1, tleft - lectures[lecno]);
			dp[lecno][tleft] = min(skip, noskip);
		}
		else
			dp[lecno][tleft] = skip;
	}

	else {
		noskip = solve(lecno+1, tleft - lectures[lecno]);
		dp[lecno][tleft] = noskip;
	}

	return dp[lecno][tleft];
}

int main() {
	scanf("%d", &N);
	int cno = 0;
	while(N > 0) {
		scanf("%d %d", &L, &C);
		if (cno > 0) printf("\n");
		for(int i=0; i < N; i++)
			scanf("%d", &lectures[i]);
		for(int i=0; i < N; i++)
			for(int j=0; j <= L; j++)
				dp[i][j].X = INF;
		ii ans = solve(0, L);
		printf("Case %d:\n", ++cno);
		printf("Minimum number of lectures: %d\n", ans.X);
		printf("Total dissatisfaction index: %d\n", ans.Y);
		scanf("%d", &N);
	}
	return 0;
}
