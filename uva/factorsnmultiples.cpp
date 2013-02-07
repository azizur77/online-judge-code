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

int n, m, adj[205][205], A[105], B[105];

int match() {
	int flow = 0;
	bool flag = true;

	while (flag) {
		vector<int> stack(1, 0);
		vector<int> pi(n+m+2, -1);
		bool seen[205] = {0};
		flag = false;

		while(stack.size() > 0) {
			int curr = stack.back(); stack.pop_back();
			if (seen[curr]) continue;
			seen[curr] = 1;

			if (curr == n+m+1) {
				flag = true;
				break;
			}

			for(int i=0; i <= n+m+1; i++) 
				if (!seen[i] && adj[curr][i] > 0) {
					pi[i] = curr;
					stack.push_back(i);
				}
		}

		if (flag) {
			flow++;
			for(int u=n+m+1; u != 0; u = pi[u]) {
				int v = pi[u];
				adj[v][u]--;
				adj[u][v]++;
			}
		}
	}

	return flow;

}

int main() {
	int T;
	cin >> T;

	for(int t=1; t <= T; t++) {
		cin >> n;
		fill(adj, 0);

		for(int i=1; i <= n; i++) {
			cin >> A[i];
			adj[0][i] = 1;
		} 
		
		cin >> m;
		for(int i=1; i <= m; i++) {
			cin >> B[i];
			adj[n+i][n+m+1] = 1;
		} 

		for(int i=1; i <= n; i++)
			for(int j=1; j <= m; j++) { 
				if (A[i] > 0 && B[j] % A[i] == 0) 
					adj[i][n+j] = 1;
				else if (A[i] == 0 && B[j] == 0) 
					adj[i][n+j] = 1;
			}

		printf("Case %d: %d\n", t, match());
	}
	return 0;
}