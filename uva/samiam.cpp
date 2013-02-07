#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int n, m, adj[2055][2055], row[2055], col[2055], r, c;
vi edges[2055];

int match() {
	int flow = 0;
	bool flag = true;

	while (flag) {
		vector<int> stack(1, 0);
		vector<int> pi(n+m+2, -1);
		bool seen[2055] = {0};
		flag = false;

		while(stack.size() > 0) {
			int curr = stack.back(); stack.pop_back();
			if (seen[curr]) continue;
			seen[curr] = 1;

			if (curr == n+m+1) {
				flag = true;
				break;
			}

			for(int u=0; u < sz(edges[curr]); u++) { 
				int i = edges[curr][u];
				if (!seen[i] && adj[curr][i] > 0) {
					pi[i] = curr;
					stack.push_back(i);
				}
			}
		}

		if (flag) {
			flow++;
			for(int u=n+m+1; u != 0; u = pi[u]) {
				int v = pi[u];
				if (u >= 1 && u <= n) row[u] = 1;
				adj[v][u]--;
				adj[u][v]++;
			}
		}
	}

	return flow;

}

int main() {
	int E;
	while (scanf("%d %d %d", &n, &m, &E) > 0 && n > 0) {
		fill(adj, 0);
		fill(row, 0);
		fill(col, 0);

		for(int i=0; i <= n+m+1; i++) edges[i].clear();

		for(int e=0; e < E; e++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a][b+n] = 1;
			edges[a].push_back(b+n);
			edges[b+n].push_back(a);
		}

		for(int i=1; i <= n; i++) {
			adj[0][i] = 1;
			edges[0].push_back(i);
			edges[i].push_back(0);
		}

		for(int i=1; i <= m; i++) {
			adj[n+i][n+m+1] = 1;
			edges[n+i].push_back(n+m+1);
			edges[n+m+1].push_back(n+i);
		}

		for(int i=1; i <= n; i++) 
			if (!row[i]) 
				for(int j=0; j < edges[i].size(); j++) 
					col[edges[i][j]] = 1;

		for(int i=n+1; i <= n+m; i++)
			if (col[i])
				for(int j=0; j < edges[i].size(); j++) {
					int v = edges[i][j];
					if (row[v] == 1 ) row[v] = 0;
				}

		int cover = match();


		printf("%d", cover);

		for(int i=1; i <= n; i++) 
			if (row[i])
				printf(" r%d", i);


		for(int i=n+1; i <= n+m; i++) 
			if (col[i])
				printf(" c%d", i-n);
		printf("\n");
	}
}