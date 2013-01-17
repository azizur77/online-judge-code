// Angry Programmer - Edmonds Karp - Min Cut
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define X first
#define Y second
#define out(x) (x+100)
using namespace std;
typedef pair<int, int> ii;

int M, W;
int resg[200][200];

vector<int> best;

struct edge {
	int x, cost;
	edge(int a, int b) : x(a), cost(b) {};
	const bool operator<(const edge &rhs) const {
		return cost < rhs.cost;
	}
};

void augpath() {
	best.clear();
	int prev[200];
	memset(prev, -1, sizeof(prev));
	priority_queue<edge> Q;
	Q.push(edge(1, 1<<30));
	bool flag = false;
	bool seen[200] = {false};

	while(Q.size() > 0) {
		edge curr = Q.top();
		Q.pop();
		if (seen[curr.x]) continue;
		seen[curr.x] = 1;

		if (curr.x == M) {
			flag = true;
			break;
		}

		for(int i=0; i < 101+M; i++) 
			if (resg[curr.x][i] > 0 && !seen[i]) {
				prev[i] = curr.x;
				Q.push(edge(i, min(curr.cost, resg[curr.x][i])));
			}
	}
	if (flag)  {
		int curr = M;
		while(curr != -1) {
			best.push_back(curr);
			curr = prev[curr];
		}
	}
 }

int edmonds_karp() {
	int mincut = 0;
	while(1) {
		augpath();
		if (best.size() == 0) break;
		int flow = 1<<30;
		for(int i=0; i < best.size()-1; i++) flow = min(flow, resg[best[i+1]][best[i]]);
		for(int i=0; i < best.size() - 1; i++) {
			int u = best[i], v = best[i+1];
			resg[u][v] += flow;
			resg[v][u] -= flow;
		}
		mincut += flow;
	}
	return mincut;
}

int main() {
	scanf("%d %d", &M, &W);
	while (!(M==0 && W==0)) {
		memset(resg, 0, sizeof(resg));
		resg[1][out(1)] = resg[M][out(M)] = 1<<30;
		for(int i=0; i < M-2; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			resg[a][out(a)] = b;
		}

		for(int i=0; i < W; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			resg[out(a)][b] = c;
			resg[out(b)][a] = c;
		}
		printf("%d\n", edmonds_karp());
		scanf("%d %d", &M, &W);
	}
	return 0;
}