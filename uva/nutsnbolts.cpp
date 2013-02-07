#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue> 
#include <stack>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int adj[1005][1005], n, m;
vi edges[1005];

int match() {
	int flow = 0;
	bool flag = false;
	int prev[1005];

	do {
		vector<int> S;
		S.push_back(0);
		bool seen[1005] = {0};
		fill(prev, -1);
		flag = false;

		while(sz(S) > 0) {
			int curr = S.back();
			S.pop_back();
			if (seen[curr]) continue;
			seen[curr] = 1;

			if (curr == n+m+1) {
				flag = true;
				break;
			}

			for(int i=0; i < edges[curr].size(); i++) {
				int v = edges[curr][i];
				if (!seen[v] && adj[curr][v] > 0) {
					prev[v] = curr;
					S.push_back(v);
				}
			}
		}

		if (flag) {
			flow++;
			for(int l=n+m+1; l!=0 ; l = prev[l]) {
				int u = l, v = prev[l];
				adj[u][v]++;
				adj[v][u]--;
			}
		}
	} while (flag);

	return flow;
}

int main() {
	int T, x;
	cin >> T;
	for(int t=1; t <= T; t++) {
		fill(adj, 0);
		cin >> n >> m;
		for(int i=0; i <= n+m+1; i++) edges[i].clear();
		for(int i=1; i <=n; i++) { adj[0][i] = 1; edges[0].push_back(i); edges[i].push_back(0); }
		for(int i=1; i <=m; i++) { adj[n+i][n+m+1] = 1; edges[n+i].push_back(n+m+1); edges[n+m+1].push_back(n+i); }

		for(int i=1; i <= n; i++)
			for(int j=1; j <= m; j++) {
				cin >> adj[i][j+n];
				if (adj[i][j+n] == 1) {
					edges[i].push_back(j+n);
					edges[j+n].push_back(i);
				}
			}
		
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t, match());
	}
	return 0;
}