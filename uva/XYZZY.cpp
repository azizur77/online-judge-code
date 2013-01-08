// 10557 - XYZZY - Bellman Ford, finding cycles
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std; 

int N, weights[105];
vector<int> graph[105], revgraph[105];

struct node {
	int x, energy;
	node(int a, int b) : x(a), energy(b) {}
};


void solve() {
	bitset<105> f1, f2;
	queue<node> fillstart;
	queue<int> fillend;
	fillstart.push(node(1, 0));
	int firstvisit[105];

	while(!fillstart.empty()) {
		node curr = fillstart.front();
		fillstart.pop();
		if (f1[curr.x]) continue;
		f1[curr.x] = 1;
		firstvisit[curr.x] = curr.energy;
		for(int i=0; i < graph[curr.x].size(); i++) 
			if (!f1[graph[curr.x][i]])
				fillstart.push(node(graph[curr.x][i], curr.energy - weights[graph[curr.x][i]]));
	}

	fillend.push(N);

	while(!fillend.empty()) {
		int curr = fillend.front();
		fillend.pop();
		if (f2[curr]) continue;
		f2[curr] = 1;
		for(int i=0; i < revgraph[curr].size(); i++) 
			if (!f2[revgraph[curr][i]])
				fillend.push(revgraph[curr][i]);
	}

	bitset<105> ingraph = f1 & f2; // common graph

	int dist[105];
	dist[1] = -100;
	for(int i=2; i <= N; i++) dist[i] = (int) 1e9;
	
	// Bellman Ford
	for(int i=0; i < N; i++) 
		for(int j=1; j <= N; j++)
		for(int k=0; k < graph[j].size(); k++) {
			int o = graph[j][k];
			if (ingraph[o] && ingraph[j])
			if (dist[j] < 0 && (dist[j] - weights[o]) < 0 && dist[o] > dist[j] - weights[o])
				dist[o] = dist[j] - weights[o];
		}

	for(int i=1; i <= N; i++) 
		for(int j=0; j < graph[i].size(); j++) {
			int o = graph[i][j];
			if (ingraph[o] && ingraph[i])
			if (dist[o] > (dist[i] - weights[o]) && (dist[i] - weights[o] < 0)) {
				puts("winnable");
				return;
			}
		}
	puts((dist[N] < 0) ? "winnable" : "hopeless");
}

int main() {
	scanf("%d", &N);
	while(N > 0) {
		for(int i=0; i <= N; i++) {
			graph[i].clear();
			revgraph[i].clear();
		}

		for(int i=1; i <= N; i++) {
			scanf("%d", &weights[i]);
			int e, o;
			scanf("%d", &e);
			for(int j=0; j < e; j++) {
				scanf("%d", &o);
				graph[i].push_back(o);
				revgraph[o].push_back(i); 
			}
		}
		solve();
		scanf("%d", &N);
	}
	return 0;
}