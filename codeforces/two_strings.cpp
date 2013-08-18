#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))
#define MOD 1000000007LL

int n;
string s, w;
vi qs, qw;

ll modpow(ll a, ll x) {
	if (x == 0) return 1ll;
	ll t = modpow(a, x/2);

	if (x & 1) {
		return (a * ((t*t) % MOD)) % MOD;
	} else {
		return (t * t) % MOD;
	}
}

ll solve(int idx, int mask) {
	if (mask == 3) {
		return (modpow(10LL, qs[idx]) * modpow(10LL, qw[idx])) % MOD;		
	}	else if (idx >= n) return 0LL;

	ll ans = 0;
	ll eq=0, fg=0, sg=0;
	char a = s[idx], b = w[idx];

	if (a == '?' && b == '?') {
		eq = 10;
		fg = sg = 45;
	} else if (a == '?') {
		eq = 1;
		sg = b - '0';
		fg = 9 - (b - '0');
	} else if (b == '?') {
		eq = 1;
		fg = a - '0';
		sg = 9 - (a - '0');
	} else {
		eq = a == b;
		fg = a > b;
		sg = a < b;
	}

	switch (mask) {
		case 0:
			ans = (ans + (eq * solve(idx+1, 0) % MOD)) % MOD;
			ans = (ans + (fg * solve(idx+1, 2) % MOD)) % MOD;
			ans = (ans + (sg * solve(idx+1, 1) % MOD)) % MOD;
			break;
		case 2:
			ans = (ans + ((eq+fg) * solve(idx+1, 2) % MOD)) % MOD;
			ans = (ans + (sg * solve(idx+1, 3) % MOD)) % MOD;
			break;
		case 1:
			ans = (ans + ((eq+sg) * solve(idx+1, 1) % MOD)) % MOD;
			ans = (ans + (fg * solve(idx+1, 3) % MOD)) % MOD;
			break;
	}
	return ans;
}

int main() {
	cin >> n;
	qs.resize(n, 0);
	qw.resize(n, 0);
	cin >> s >> w;

	for(int i=n-1; i >= 0; i--) {
		qs[i] = s[i] == '?' + ((i < n-1) ? qs[i+1] : 0);
		qw[i] = w[i] == '?' + ((i < n-1) ? qw[i+1] : 0);
	}

	cout << solve(0, 0) << endl;
}