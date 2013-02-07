#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()


int adj[205][205];

int main() {
	int n, m, x, y, w;
	scanf("%d %d", &n, &m);
	for(int i=0; i <= n; i++) for(int j=0; j <= n; j++) adj[i][j] = 10000000;

	for(int i=0; i < m; i++) {
		scanf("%d %d %d", x, y, w);
		adj[x][y] = adj[y][x] = w;
	}

	for(int k=1; k <= n; k++)
		for(int i=1; i <= n; i++)
			for(int j=0; j <= n; j++)
				adj[j][i] = adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	vector<ii> farthest(n+1, ii(0, 0));
	for(int i=0; i <= n; i++) farthest[i].Y = i;
 
	for(int i=1; i <= n; i++)
		for(int j=1; j <= n; j++)
			farthest[i].X = max(farthest[i], adj[i][j]);

	sort(farthest.begin(), farthest.end());

	int a = farthest[0].Y, b = farthest[1].Y;

	double best = farthest[0].X;
	dist = max(farthest[1].X)




}