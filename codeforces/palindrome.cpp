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
#define MAXN 5005

bool seen[MAXN][MAXN], dp[MAXN][MAXN];
string str;
int n;

void search(int l, int r) {
	dp[l][r] = true;
	if (seen[l][r]) return;
	if (l > 0 && str[l-1] == str[r]) {
		search(l-1, r);
	}
	if (l > 0 && r < n-1 && str[l-1] == str[r+1]) {
		search(l-1, r+1);
	}
	if (r < n-1 && str[l] == str[r+1]) {
		search(l, r+1);
	}
	seen[l][r] = 1; 
}

int main() {
	fill(seen, 0);
	fill(dp, 0);
	cin >> str;
	n = sz(str);
	for(int i=0; i < n; i++) {
		search(i, i);
		if (i < n-1) {
			if (str[i] == str[i+1])
				search(i, i+1);
		}
	}
	int q;
	cin >> q;
	REP(i, q) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << dp[l][r] << endl;
	}
	return 0;
}