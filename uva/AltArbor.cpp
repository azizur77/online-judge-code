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
#include <sstream>
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

int dp[10005][21];
vi children[10005];
bool parent[10005];

int solve(int node, int color) {
	if (dp[node][color] != -1) return dp[node][color];
	int &ret = dp[node][color];
	ret = color;
	for(int i=0; i < sz(children[node]); i++) {
		int cost = INF;
		for(int j=1; j <= 20; j++)
			if (j != color)
				cost = min(cost, solve(children[node][i], j));
		ret += cost;
	}
	return ret;
}


vi getints() {
	vi res;
	int k = 0;
	char a;
	a = getchar();
	while(a == '\n' || a == ' ') a = getchar();
	k = k * 10 + (a - '0');
	while((a=getchar())!=':')
		k = k * 10 + (a - '0');
	res.push_back(k);
	a = getchar();
	while(a != '\n') {
		a = getchar();
		k = 0;
		while (a != ' ' && a != '\n') {
			k = k * 10 + (a - '0');
			a = getchar();
		}
		res.push_back(k);
	}
	// printf("size of %d is %d\n", res[0], sz(res) - 1);
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n > 0) {
		for(int i=0; i < n; i++) 
			for(int j=0; j <= 20; j++)
			 	dp[i][j] = -1;
		for(int i=0; i < n; i++) parent[i] = false;
		for(int i=0; i < n; i++) children[i].clear();
		for(int i=0; i < n; i++) {
			vi ints = getints();
			if (sz(ints) > 1) {
				for(int j=1; j < sz(ints); j++) 
					parent[ints[j]] = 1;
				children[ints[0]] = vi(ints.begin()+1, ints.end());
			}
		}
		int root = -1, total = 0;
		for(int i=0; i < n; i++)
			if (!parent[i]) {
				root = i;
				int ans = INF;
				for(int j=1; j <= min(20, n); j++)
					ans = min(ans, solve(i, j));
				total += ans;
			}
		printf("%d\n", total);
		scanf("%d", &n);
	}
	return 0;
}