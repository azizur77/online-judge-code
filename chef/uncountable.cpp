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
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll fact[800001], invfac[800001];

#define add(a, b)   (((a)+(b)) % MOD)
#define mul(a, b)   (((a) * (b)) % MOD)

ll modpow(int a, int pow) {
	if (pow == 0) return 1;
	ll temp = modpow(a, pow/2);
	return (pow % 2 == 0) ? mul(temp, temp) : mul(a, mul(temp, temp));
}

ll modpow_iter(ll a, int pow) {
	ll res = 1;
	while(pow > 0) {
		if (pow % 2) res = mul(res, a);
		pow >>= 1;
		a = mul(a, a); 
	}
	return res;
}

void findfacts() {
	
	for(int i=0; i < 2; i++) {
		fact[i] = invfac[i] = 1;
	}
	for(ll i=2; i < 800001; i++) fact[i] = mul(i, fact[i-1]);
	for(int i=2; i < 800001; i++)  invfac[i] = modpow_iter(fact[i], MOD-2);
}

// inline ll choose(ll n, ll r) {
// 	return mul(fact[n], mul(invfac[n-r], invfac[r]));
// }
#define choose(n, r) (mul(fact[(n)], mul(invfac[(n)-(r)], invfac[(r)])))

#define dbg(x)	printf("(dbg) %lld\n", x);

ll solve(ll N, ll M, ll A, ll B) {
	ll res = choose(M+N, M);
	for(ll i=B-1; i >=0 ; i--) {
		res = add(res, -mul(choose(N-A+i, i), choose(A-1+M-i, A-1)));
	}
	if (res < 0) res += MOD;
	return res;
}


int main() {
	int t;
	findfacts();
	scanf("%d", &t);
	for(int i=0; i < t; i++) {
		ll a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		printf("%lld\n", solve(a, b, c, d));
	}
}



