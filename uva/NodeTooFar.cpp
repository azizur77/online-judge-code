// 336 - A node too far
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
#include <map>
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
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int bfs(map<int, vi> &edges, int start, int ttl) {
	set<int> seen;
	queue<ii> Q;
	Q.push(mp(start, 0));
	int count = 0;
	while(!Q.empty()) {
		ii curr = Q.front();
		Q.pop();
		if (seen.find(curr.X) != seen.end()) continue;
		count++;
		seen.insert(curr.X);
		if (curr.Y < ttl) {
			for(int i=0; i < edges[curr.X].size(); i++) {
				Q.push(mp(edges[curr.X][i], curr.Y+1));
			}
		}
	}
	return count;
}


int main() {
	int NC, caseno=0;
	scanf("%d", &NC);
	while(NC > 0) {
		int x, y;
		map<int, vi> edges;
		for(int i=0; i < NC; i++) {
			scanf("%d %d", &x, &y);
			edges[x].pb(y);
			edges[y].pb(x);
		}	
		int V = edges.size();
		scanf("%d %d", &x, &y);
		while (!(x==0 && y==0)) {
			int na = V - bfs(edges, x, y);			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caseno, na, x, y);
			scanf("%d %d", &x, &y);
		}
		scanf("%d", &NC);
	}
	return 0;
}