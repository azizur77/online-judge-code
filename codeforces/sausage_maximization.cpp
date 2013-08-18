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
typedef unsigned long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))


ll A[1000005], pre[1000005], post[1000005];

int main() {
	int n;
	cin >> n;

	for(int i=0; i < n; i++) cin >> A[i];

	for(int i=0; i < n; i++) {
		pre[i] = ((i > 0) ? pre[i-1] : 0ULL) ^  A[i];
	}

	for(int i=n-1; i >= 0; i--) {
		post[i] = ((i < n-1) ? post[i+1] : 0ULL) ^ A[i];
	}

	ll maxval = 0;

	for(int i=0; i < n-1; i++) {
		ll val = pre[i] ^ post[i+1];
		maxval = max(maxval, val);
	}
	maxval = max(maxval, max(pre[n-1], post[0]));

	cout << maxval << endl;

	return 0;
}