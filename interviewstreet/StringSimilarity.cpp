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

ll similarity(string s) {
	int n = sz(s);
	vi Z(n, 0);

	int L, R;
	L = R = 0;
	for(int i=1; i < n; i++) {
		if (i > R) {
			R = L = i;
			while(R < n && s[R] == s[R-L]) R++;
			Z[i] = R - L;
			R--;
		}
		else {
			int k = i - L;
			if (Z[k] < R - i + 1) {
				Z[i] = Z[k];
			}
			else {
				L = i;
				while(R < n && s[R] == s[R-L]) R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
	ll sum = n;
	FOR(i, 1, n) sum += (ll) Z[i];
	return sum;
}

int main() {
	int T;
	cin >> T;
	REP(i, T) {
		string s;
		cin >> s;
		cout << similarity(s) << endl;
	}
	return 0;
}