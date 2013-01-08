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
	int n, t, x, y, totA=0, totB=0, pingA=0, pingB=0;
	cin >> n;
	REP(i, n) {
		cin >> t >> x >> y;
		if (t == 1) {
			totA += 10;
			pingA += x;
		}
		else {
			totB += 10;
			pingB += x;
		}
	}
	if (pingA * 2 >= totA) cout << "LIVE" << endl;
	else cout << "DEAD" << endl;

	if (pingB*2 >= totB) cout << "LIVE" << endl;
	else cout << "DEAD" << endl;
	return 0;
}