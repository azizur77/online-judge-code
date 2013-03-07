#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <string.h>
#include <map>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> pll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))


ll fact[100005], ifact[100005], MOD;

ll modpow(ll a, ll x) {
	if (x == 0) return 1LL;
	ll t = modpow(a, x/2);
	t = (t * t) % MOD;
	if (x % 2)
		return (t * a) % MOD;
	return t;
}

void generate() {
	fact[0] = 1LL;
	for(ll i=1; i < 100005; i++) fact[i] = (fact[i-1] * i) % MOD;
	for(ll i=0; i < 100005; i++) ifact[i] = modpow(fact[i], MOD-2);
}

int main() {
	int n;
	ll m, x;

	foo.push_back(NULL);
	cin >> n;
	vector<pll> numbers;
	for(int i=0; i < 2*n; i++) {
		cin >> x;
		int y = (i % n) + 1;
		numbers.push_back(pll(x, y));
	}
	cin >> m;
	MOD = m;
	generate();
	sort(all(numbers));

	ll ctr = 0, last = 0;
	ll nways = 1;

	for(int i=0; i < 2*n; i++) {
		if (i == 0 || numbers[i].X == numbers[i-1].X) ctr++;
		else {
			if (ctr > 1) {
				ll temp = fact[ctr];
				vector<ll> divide;
				int past = 0;
				for(int j=last; j < i; j++) {
					if (j==past || numbers[j].Y == numbers[j-1].Y) past++;
					else {
						if (past > 1) 
							divide.push_back(past);
						past = 1;
					}
				}
				if (past > 1) divide.push_back(past);
				for(int j=0; j < sz(divide); j++) {
					temp = (temp * ifact[divide[j]]) % m;
				}
				nways = (nways * temp) % m;
			}
			ctr = 1;
			last = i;
		}
	}
	if (ctr > 1) {
				ll temp = fact[ctr];
				vector<ll> divide;
				int past = 0;
				for(int j=last; j < 2*n; j++) {
					if (j==last || numbers[j].Y == numbers[j-1].Y) past++;
					else {
						if (past > 1) 
							divide.push_back(past);
						past = 1;
					}
				}
				if (past > 1) divide.push_back(past);
				for(int j=0; j < sz(divide); j++) {
					// printf("%lld\n", ifact[divide[j]]);
					temp = (temp * ifact[divide[j]]) % m;
				}
				nways = (nways * temp) % m;
	}
	cout << nways << endl;

	return 0;
}