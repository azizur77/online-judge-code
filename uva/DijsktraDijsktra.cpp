// 10806 - Dijkstra Dijkstra
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second

const static int INF = (1 << 30);
int N, E, used[105][105], dist[105];
vector<ii> edges[105];

int bellman_ford() {
	int prev[105];
	for(int i=0; i <= N; i++) prev[i] = -1;
	for(int i=2; i <= N; i++) dist[i] = INF;
	dist[1] = 0;
	for(int i=0; i < N; i++) 
		for(int j=1; j <= N; j++) 
			for(int k=0; k < edges[j].size(); k++) {
				int v = edges[j][k].X, c = edges[j][k].Y;
				if (!used[j][v] && dist[v] > dist[j] + c) {
					dist[v] = dist[j] + c;
					prev[v] = j;
				}
			}
	if (dist[N] < INF/2)
	for(int l=N; l != 1; l = prev[l]) { 
		used[prev[l]][l] = true;
		for(int i=0; i < edges[l].size(); i++)
			if (edges[l][i].X == prev[l])
				edges[l][i].Y *= -1;
	}
	return dist[N];
}

int main() {
	while(scanf("%d", &N) > 0 && N > 0) {
		scanf("%d", &E);
		memset(used, 0, sizeof(used));

		for(int i=0; i <= N; i++) edges[i].clear();

		for(int i=0; i < E; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edges[a].push_back(ii(b, c));
			edges[b].push_back(ii(a, c));
		}

		int k1 = bellman_ford();
		if (k1 >= INF/2) { puts("Back to jail"); continue; }
		int k2 = bellman_ford();
		if (k2 >= INF/2) { puts("Back to jail"); continue; }
		printf("%d\n", k1+k2);
	}
	return 0;
}