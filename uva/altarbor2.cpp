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

vi getints() {
	vi res;
	int k = 0;
	char a;
	a = getchar();
	while(a == '\n' || a == ' ') a = getchar();
	k = k * 10 + (a - '0');
	while((a=getchar())!=':')
		k = k * 10 + (a - '0');
	res.push_back(k);
	a = getchar();
	while(a != '\n') {
		a = getchar();
		k = 0;
		while (a != ' ' && a != '\n') {
			k = k * 10 + (a - '0');
			a = getchar();
		}
		res.push_back(k);
	}
	// printf("size of %d is %d\n", res[0], sz(res) - 1);
	return res;
}

vi edges[10005];
bool root[10005];
int N, dp[10005][25];

int solve(int node, int c) {
	if (dp[node][c] != -1) return dp[node][c];
	int cost, mincost = INF;
	for(int i=1; i <= 20; i++)
		if (i != c) {
			cost = c;
			for(int j=0; j < sz(edges[node]); j++)
				cost += solve(edges[node][j], i);
			mincost = min(cost, mincost);
		}
	return (dp[node][c] = mincost);
}

int main() {
	scanf("%d", &N);
	while (N > 0) {
		fill(root, 1);
		fill(dp, -1);
		for(int i=0; i < N; i++) {
			vi ints = getints();
			edges[ints[0]].clear();
			for(int j=1; j < sz(ints); j++) {
				root[ints[j]] = 0;
				edges[ints[0]].push_back(ints[j]);
			}
		}
		int ans = 0;
		for(int j=0; j < N; j++) {
			if (root[j]) {
				int cost = INF;
				for(int k=1; k <= 20; k++)
					cost = min(cost, solve(j, k));
				ans += cost;
			}
		}
		printf("%d\n", ans);
		scanf("%d", &N);
	}
	return 0;
}