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

int n, last;
ll mod(ll a, ll b) {
	ll p = a % b;
	if (p < 0) return p+b;
	return p;
}

bool cmp(ll a, ll b) {
	return mod(last-a, n) < mod (last-b, n);
}

int main() {
	cin >> n >> last;
	vector<ll> array(n, 0);
	REP(i, n) cin >> array[i];
	last--;
	ll minx=-1, minv=INF;
	vi posns;
	for(int i=0; i < n; i++) {
		if (array[i] < minv) {
			minv = array[i];
			posns.clear();
			posns.push_back(i);
		}
		else if (array[i] == minv) {
			posns.push_back(i);
		}
	}
	vector<ll> copy(all(array));
	sort(all(posns), cmp);
		array = copy;
		minx = posns[0];
		ll diff = mod((last - minx), n);
		for(int i=0; i < n; i++)
			array[i] -= minv;
		int idx = mod(minx+1, n);
		while(idx != mod(last + 1, n)) {
			array[idx]--;
			idx = mod(idx+1, n);
		}
		array[minx] = n * minv + diff;

		for(int i=0; i < n-1; i++) {
			cout << array[i] << " ";
			assert(array[i] >= 0);
		}
		assert(array[n-1] >= 0);
		cout << array[n-1] << endl;
		return 0;
}