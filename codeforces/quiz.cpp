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
#define MOD 1000000009LL

ll modpow(ll a, ll x) {
	if(x == 0) return 1LL;
	ll t = modpow(a, x/2) % MOD;
	ll sq = (t * t) % MOD;
	if (x % 2)
		return (a * sq) % MOD;
	else
		return sq;
}

int main() {
	ll n, m, k, x, xp, y, res = 0;
	cin >> n >> m >> k;
	x = min((n-m) * (k-1), m);
	xp = (m - x) % k;
	y = (m - x) / k;
	if (y > 0)
		res = (k * ((modpow(2LL, y+1) - 2 + MOD) % MOD)) % MOD;
	res = ((res + x) % MOD + xp) % MOD;
	cout << res << endl;
	return 0;
}