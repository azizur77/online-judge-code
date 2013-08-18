#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

struct op {
	ll x, y, d;
	op(ll a, ll b, ll c) : x(a), y(b), d(c) {}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr(n+1, 0ll);
	vector<op> ops;


	for(int i=0; i < n; i++) cin >> arr[i];

	for(int i=0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ops.push_back(op(x, y, z));
	}

	vector<ll> diffop(m+2, 0);

	for(int i=0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		diffop[x] += 1;
		diffop[y+1] -= 1;
	}

	ll p = 0;
	for(int i=1; i <= m; i++) {
		p += diffop[i];
		ops[i-1].d *= p;
	}

	// create diff array
	vector<ll> diff(n+2, 0);
	diff[1] = arr[0];
	for(int i=1; i < n; i++)
		diff[i+1] = arr[i] - arr[i-1];

	// Apply ops
	for(int i=0; i < m; i++) {
		diff[ops[i].x] += ops[i].d;
		diff[ops[i].y + 1] -= ops[i].d;
	}

	p = 0;
	for(int i=1; i <= n; i++) {
		p += diff[i];
		arr[i-1] = p;
	}

	for(int i=0; i < n-1; i++) cout << arr[i] << " ";
	if (n > 0)
		cout << arr[n-1] << endl;

	return 0;
}