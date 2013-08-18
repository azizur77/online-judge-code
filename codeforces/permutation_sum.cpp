#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <map>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))
#define MOD 1000000007

struct key {
	int a, b, idx;
	key(int x, int y, int z) : a(x), b(y), idx(z) {}
	bool operator<(const key &rhs) const {
		if (a != rhs.a) return a < rhs.a;
		if (b != rhs.b) return b < rhs.b;
		return idx < rhs.idx;
	}

};

map<key, ll> M;

int n;

ll solve(int mask, int mask2, int idx) {

	if (idx == n && mask == 0) return 1LL;
	if (__builtin_popcount(mask) < n-idx || __builtin_popcount(mask2) < n-idx) return 0LL;
	
	key k(mask, mask2, idx);
	if (M.find(k) != M.end()) return M[k];


	ll ret = 0;

	for(int i=0; i < n; i++) {
		int j = (i + idx) % n;
		if ((mask2 & (1 << i)) && (mask & (1 << j))) {
			int mask3 = mask & ~(1 << j);
			int mask4 = mask2 & ~(1 << i);
			ret = (ret + solve(mask3, mask4, idx + 1)) % MOD;
		}
	}

	M[k] = ret;
	return ret;
}

int main() {
	ll dpcalc[] = {1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};
	cin >> n;
	cout << dpcalc[n-1] << endl;
	// cin >> n;
	// int mask = (1 << n) - 1;
	// ll ans = solve(mask, mask, 0);
	// for(ll i = 2; i <= n; i++) ans = (ans * i) % MOD;
	// cout << ans << endl;
	return 0;
}