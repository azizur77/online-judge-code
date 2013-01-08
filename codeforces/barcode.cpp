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

int x, y, n, m, to_white[1005], to_black[1005];
ll mem[1005][2];


ll solve(int start, int prev) {
	// printf("%d %d\n", start, prev);
	ll ret = INF;
	if (start == m) return 0;
	else if (start + x > m) return ret;

	if (mem[start][prev] != -1) return mem[start][prev];

	for(int i=x; i <= y; i++) {
		if (start + i <= m) {
			if (prev == 0)
				ret = min(ret, accumulate(to_white+start, to_white+start+i, 0) + solve(start + i, 1));
			else
				ret = min(ret, accumulate(to_black+start, to_black+start+i, 0) + solve(start + i, 0));
		}
	}
	return (mem[start][prev] = ret);
}

int main() {
	fill(mem, -1); 
	scanf("%d %d %d %d", &n, &m, &x, &y);
	fill(to_white, 0);
	fill(to_black, 0);
	char s[1005][1005];
	REP(i, n) {
		scanf("%s", s[i]);
	}
	REP(j, m) REP(i, n) {
		if (s[i][j] == '#') to_white[j]++;
		else if (s[i][j] == '.') to_black[j]++;
	}
	cout << min(solve(0, 0), solve(0, 1)) << endl;
	return 0;
}