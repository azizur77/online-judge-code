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
typedef 	long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

vector<ii> decompose(ii frac) {
	ll ceiling = ceil(1.0 * frac.Y / frac.X);
	ii f1 = mp(1, ceiling);
	ii f2;
	f2.X = -frac.Y-floor(-1.0 * frac.Y /frac.X)*frac.X;
	f2.Y = ceiling * frac.Y;
	vector<ii> result;
	result.push_back(f1);
	result.push_back(f2);
	return result;
}

vi solve(ii frac) {
	if (frac.X == 1) return vi(1, frac.Y);
	vi result;
	while(1) {
		vector<ii> fractions = decompose(frac);
		result.push_back(fractions[0].Y);
		if (fractions[1].X == 1) {
			result.push_back(fractions[1].Y);
			break;
		}
		else if (fractions[1].X == 0) {
			break;
		}
		else {
			frac = fractions[1];
		}
	}
	return result;
}

void display(vi result) {
	int n = result.size();
	REP(i, n-1) cout << result[i] << " ";
	cout << result[n-1] << endl;
}

int main() {
	ll a = 0, b = 0;
	while(1) {
		cin >> a >> b;
		if (!(a == 1 && b == 1))
			display(solve(mp(a, b)));
		else 
			break;
	}
	return 0;
}