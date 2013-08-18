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
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int a, b, c, d, res, g;
	cin >> a >> b >> c >> d;

	g = gcd(a*d, b*c);
	int p = a * d / g, q = b * c / g;

	if (p <= q) {
		printf("%d/%d\n", q - p, q);
	} else {
		printf("%d/%d\n", p - q, p);
	}
	return 0;
}