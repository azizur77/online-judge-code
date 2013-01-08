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
	ll dp[102], a[102];
	int n;
	scanf("%d", &n);
	REP(i, n) cin >> a[i];
	for(int i=0; i < n; i++) 
		dp[i] = 1 + ((i > 0) ? dp[i-1] : 0) + (i+1)*(a[i]-1);
	cout << dp[n-1] << endl;
	return 0;
}