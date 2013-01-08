// 10717 - Mint

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

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b, int c, int d) {
	int G1 = a * b / gcd(a, b);
	int G2 = c * d / gcd(c, d);
	int G3 = G1 * G2 / gcd(G1, G2);
	return G3;
}

int main() {
	int N=-1, T=-1;
	while (!(N == 0 && T == 0)) {
		cin >> N >> T;
		vi coins(N);
		vi towers(T);
		REP(i, N) cin >> coins[i];
		REP(j, T) cin >> towers[j];
		REP(i, T) {
			int minlo=INF, minhi=INF;
			REP(a, N) FOR(b, a+1, N) FOR(c, b+1, N) FOR(d, c+1, N) {
				int L = lcm(coins[a], coins[b], coins[c], coins[d]);
				int lo = (towers[i] - (towers[i] / L) * L) % L;
				int hi = ((towers[i] / L + 1) * L - towers[i]) % L;
				if (L > towers[i]) {
					lo = towers[i];
					hi = L - towers[i];
				}
				minlo = min(lo, minlo);
				minhi = min(minhi, hi);
			}
			cout << towers[i] - minlo << " " << towers[i] + minhi << endl;
		}
	}
	return 0;
}