// Cutting Sticks
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

int positions[51];
int memo[1005][1005], n;

int solve(int start, int end) {
	int cnt = 0;
	int ret = INF;
	if (memo[start][end] != -1) return memo[start][end];
	REP(i, n) 
		if (positions[i] > start && positions[i] < end) {
			ret = min(ret, end-start + solve(start, positions[i]) + solve(positions[i], end));
			cnt++;
		}
	if (cnt == 0) ret = 0;
	return (memo[start][end] = ret);
}

void task(int len) {
	REP(i, len+1) REP(j, len+1) memo[i][j] = -1;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &positions[i]);
	int ans = solve(0, len);
	printf("The minimum cutting is %d.\n", ans);
}

int main() {
	int l;
	while(1) {
		scanf("%d", &l);
		if (l != 0) task(l);
		else break;
	}
	return 0;
}


