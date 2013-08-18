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

int main() {
	ll n, x, y;
	cin >> n >> x >> y;

	ll target = (x-n+1 > 0) ? ceil(sqrt(1.0 * x - n + 1)) : 1;
	if (target + n - 1 > y) {
		puts("-1");
	} else {
		cout << target << endl;
		for(int i=0; i < n-1; i++) cout << 1 << endl;
	}
	return 0;
}