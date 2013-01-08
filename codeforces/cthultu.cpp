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
typedef vector <bool> vb;
typedef vector <vb> vvb;

int n, m;

bool find_cycle(vvb adj) {
	bool seen[101] = {0};
	stack <int> S;
	S.push(1);
	while(S.size()) {
		int curr = S.top();
		S.pop();
		if (seen[curr]) return true;
		seen[curr] = true;
		for(int i=1; i <= n; i++) 
			if (adj[curr][i]) {
				adj[curr][i] = 0;
				S.push(i);
			}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	vvb adj(n, vb (n, 0));
	REP(i, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = adj[b][a] = 1;
	}

}