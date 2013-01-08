// 11504 - Dominos (Tarjan SCCs)
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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

vi edges[100005], root;
bool seen[100005], deleted[100005], instack[100005], isroot[100005], second[100005];
int N, scc_count, id;
int idx[100005], lowlink[100005];
stack<int> S;

void _delete(int node) {
	if (deleted[node]) return;
	deleted[node] = 1;
	for(int i=0; i < sz(edges[node]); i++) {
		_delete(edges[node][i]);
	}
}

void tarjan(int node) {
	if (isroot[node]) {
		scc_count--;
		// second[node] = 1;
		// for(int i=0; i < sz(edges[node]); i++)
		// 	if (!deleted[edges[node][i]] && !second[edges[node][i]])
		// 		tarjan(edges[node][i]);
		return;
	}
	if (deleted[node] || seen[node]) return;
	seen[node] = 1;
	idx[node] = ++id;
	lowlink[node] = idx[node];
	S.push(node);
	instack[node] = 1;
	for(int i=0; i < sz(edges[node]); i++) {
		if (!deleted[edges[node][i]]) {
			if(!seen[edges[node][i]]) {
				tarjan(edges[node][i]);
				lowlink[node] = min(lowlink[node], lowlink[edges[node][i]]);
			}
			else if (instack[edges[node][i]]) {
				lowlink[node] = min(idx[edges[node][i]], lowlink[node]);
			}
		}
	}
	if(lowlink[node] == idx[node]) {
		while(S.top() != node) {
			instack[S.top()] = 0;
			S.pop();
		}
		S.pop();
		instack[node] = 0;
		isroot[node] = 1;
		scc_count++;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		S = stack<int> ();
		int m, initroot = 0;
		id = 0;
		scanf("%d %d", &N, &m);
		for(int i=1; i <= N; i++) edges[i].clear();
		fill(seen, false);
		fill(deleted, false);
		fill(isroot, false);
		fill(instack, false);
		fill(second, false);
		fill(idx, 0);
		fill(lowlink, 0);
		root.resize(N+1, 1);
		for(int i=0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			edges[x].push_back(y);
			root[y] = 0;
		}

		for(int i=1; i <= N; i++) 
			if (root[i] > 0 && !deleted[i])  {
				initroot++;
				_delete(i);
			}
			
	
		scc_count = 0;
		for(int i=1; i <= N; i++) 
			if (!deleted[i]) 
				tarjan(i);
		printf("%d\n", initroot + scc_count);
	}
	return 0;
}