#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> ii;

int n, k, adj[32][32];
vector<int> seqs[32], edges[32];
static const int INF = (1<<20);

bool cmp(int a, int b) {
	for(int i=0; i < k; i++)
		if (seqs[a][i] >= seqs[b][i]) return false;
	return true;
}

void longest() {
	int m = INF;
	vector<int> best;

	for(int i=0; i < n; i++) {
		int prev[32], dist[32];
		for(int j=0; j < n; j++) { prev[j] = -1; dist[j] = INF; }
		int deepest = i;
		dist[i] = 0;

		for(int x=0; x < n; x++)
			for(int u=0; u < n; u++)
				for(int j=0; j < edges[u].size(); j++)  {
					int v = edges[u][j];
					if (dist[v] > dist[u] - 1) {
						dist[v] = dist[u]-1;
						prev[v] = u;
					}
				}

		int len = 1;
		for(int j=0; j < n; j++)
			if (dist[j] <= 0 && dist[j] < len) {
				len = dist[j];
				deepest = j;
			}

		if (len < m) {
			m = len;
			best.clear();
			for(int l = deepest; l != -1; l = prev[l]) 
				best.push_back(l+1);
		}
	}
	reverse(best.begin(), best.end());
	printf("%d\n", best.size());
	for(int i=0; i < best.size() - 1; i++) printf("%d ", best[i]);
	if (best.size()) printf("%d\n", best.back());
}


int main() {
	while(scanf("%d %d", &n, &k) > 0) {
		for(int i=0; i < n; i++) for(int j=0; j < n; j++) adj[i][j] = INF;
		for(int i=0; i < n; i++) { seqs[i].resize(k, 0); edges[i].clear(); }
		for(int i=0; i < n; i++) for(int j=0; j < k; j++) scanf("%d", &seqs[i][j]);
		for(int i=0; i < n; i++) sort(seqs[i].begin(), seqs[i].end());
		for(int i=0; i < n; i++) for(int j=0; j < n; j++) if (cmp(i, j)) {
			adj[i][j] = -1;
			edges[i].push_back(j);
		}
		longest(); 

	}
	return 0;
}