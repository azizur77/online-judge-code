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

int adj[6][6] = {0};

vector<string> results;

void backtrack(string prefix, int node) {
	bool flag = true;
	for(int i=1; i <= 5; i++)
		if (adj[node][i]) {
			flag = false;
			adj[node][i] = 0;
			adj[i][node] = 0;
			char c = '0' + i;
			backtrack(prefix + c, i);
			adj[node][i] = 1;
			adj[i][node] = 1;
		}
	if (flag && sz(prefix) == 9) {
		results.push_back(prefix);
	}
}

int main() {
	adj[1][2] = adj[2][1] = adj[2][3] = adj[3][2] = 1;
	adj[1][3] = adj[3][1] = adj[1][5] = adj[5][1] = 1;
	adj[2][5] = adj[5][2] = adj[3][5] = adj[5][3] = 1;
	adj[3][4] = adj[4][3] = adj[5][4] = adj[4][5] = 1;
	backtrack("1", 1);

	sort(all(results));
	REP(i, sz(results)) cout << results[i] << endl;
	return 0;
}

