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
#define MAXN 100010

vi edges[MAXN];
set<int> nodes[MAXN];
int n, m, color[MAXN];
bool seen[MAXN];

int main() {
	cin >> n >> m;
	REP(i, n) {
		cin >> color[i+1];
		seen[color[i+1]] = 1;
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i=1; i <= n; i++) {
		for(int j=0; j < edges[i].size(); j++)
			if (color[edges[i][j]] != color[i]) {
				nodes[color[i]].insert(color[edges[i][j]]);
			}
	}
	int best = -INF, bestcolor = -1;
	for(int i=1; i < MAXN; i++) {
		if (seen[i]) {
			int s = nodes[i].size();
			if (s > best) {
				bestcolor = i;
				best = s;
			}
		}
	}

	cout << bestcolor << endl;
	return 0;
}