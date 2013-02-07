#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))
#define EPS 1e-9

int n, m, s, v, adj[205][205] = {0};
double gophers[101][2], holes[101][2];

double euclid(double a, double b, double c, double d) {
	return sqrt((a-c) * (a-c) + (b-d) * (b-d));
}

int match() {
	int flow = 0;
	bool flag = true;

	do {
		queue<vi> Q;
		Q.push(vi(1, 0));
		vi hop;
		bool seen[205] = {0};
		flag = false;

		while(!Q.empty()) {
			vi curr = Q.front();
			Q.pop();
			int last = curr.back();
			if (seen[last]) continue;
			seen[last] = 1;

			if (last == n+m+1) {
				flag = true;
				hop = curr;
				break;
			}

			for(int i=0; i <= n+m+1; i++)
				if (!seen[i] && adj[last][i]) {
					vi copy(all(curr));
					copy.push_back(i);
					Q.push(copy);
				}
		}
		if (flag) flow++;
		for(int i=1; i < hop.size(); i++) {
			int u = hop[i-1], v = hop[i];
			adj[u][v]--;
			adj[v][u]++;
		}
	} while (flag);
	return flow;
}

int main() {

	while(scanf("%d %d %d %d", &n, &m, &s, &v) == 4) {
		for(int i=1; i <= n; i++) cin >> gophers[i][0] >> gophers[i][1]; 
		for(int i=1; i <= m; i++) cin >> holes[i][0] >> holes[i][1];

		fill(adj, 0);

		for(int i=1; i <= n; i++)
			for(int j=1; j <= m; j++) {
				double t = euclid(gophers[i][0], gophers[i][1], holes[j][0], holes[j][1]) / v;
				adj[i][j+n] = (t < s+EPS);
			} 

		for(int i=1; i <= n; i++) adj[0][i] = 1; // source
		for(int i=1; i <= m; i++) adj[n+i][n+m+1] = 1; // sink

		cout << n - match() << endl;
	}
}