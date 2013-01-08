// Bicoloring

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

static const int RED = 0, BLACK = 1; 

string task(int n) {
	int e;
	scanf("%d", &e);
	vi edges[220];
	REP(i, e) {
		int x, y;
		scanf("%d %d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	stack <int> S;
	int color[220];
	fill(color, -1);
	color[0] = RED;
	S.push(0);
	bool seen[220] = {0};
	while(sz(S)) {
		int curr = S.top();
		S.pop();
		if (seen[curr]) continue;
		seen[curr] = true;

		for(int i=0; i < sz(edges[curr]); i++) {
			int oth = edges[curr][i];
			if (color[oth] == color[curr]) return "NOT BICOLORABLE.";
			else {
				color[oth] = color[curr] ^ 1;
				S.push(oth);
			}
		}
	}
	return "BICOLORABLE.";
}


int main() {
	int x;
	while(scanf("%d", &x)) {
		if (x == 0) break;
		cout << task(x) << endl;
	}
	return 0;
}