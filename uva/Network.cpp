// 315 - Network
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

int N, block, current = 0;
bool seen[110];
vi edges[110];

void find_connected(int node) {
	if (seen[node]) return;
	seen[node] = 1;
	current++;
	for(int i=0; i < sz(edges[node]); i++)
		if (edges[node][i] != block)
			find_connected(edges[node][i]);
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		for(int i=1; i <= N; i++) edges[i].clear();
		while(1) {
			int start, temp;
			vi line;
			char c;
			scanf("%d", &start);
			if (start == 0) break;
			c = getchar();
			while(c == ' ' || c == '\n') c = getchar();
			while(c != '\n') {	
				temp = 0;
				while(c != ' ' && c != '\n') {
					temp = temp * 10 + (c - '0');
					c = getchar();
				}
				line.push_back(temp);
				if (c == ' ') c = getchar();
			}
			for(int i=0; i < sz(line); i++) {
				edges[line[i]].push_back(start);
				edges[start].push_back(line[i]);
			}
		}
		int count = 0;
		for(int i=1; i <= N; i++) {
			fill(seen, false);
			current = 0;
			block = i;
			for(int j=1; j <= N; j++)
				if (j != i) {
					find_connected(j);
					break;
				}
			if (current < N-1) count++;
		}
		printf("%d\n", count);
	}
	return 0;
}