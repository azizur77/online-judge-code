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

int main() {
	string club;
	cin >> club;
	vi dp(sz(club), 1);
	FOR(i, 1, sz(club)) {
		if (club[i] == club[i-1])
			dp[i] = dp[i-1] + 1;
	}
	int plus = 0, minus = 0;
	REP(i, sz(club)) {
		if (club[i] == '+') plus++;
		else minus++;
	}
	cout << max(abs(minus-plus), *max_element(all(dp))) << endl;
	return 0;
}