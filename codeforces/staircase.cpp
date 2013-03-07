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
	ll n, m, h, w;
	cin >> n;

	vector<ll> heights(n, 0);
	for(int i=0; i < n; i++) cin >> heights[i];
	for(int i=1; i < n; i++) heights[i] = max(heights[i-1], heights[i]);

	int pos = 0;
	cin >> m;

	for(int i=0; i < m; i++) {
		cin >> w >> h;
		w--;
		cout << max(heights[pos], heights[min(n-1, w)]) << endl;
		ll tail = max(heights[pos], heights[min(n-1, w)]) + h;
		pos = lower_bound(heights.begin() + pos, heights.end(), tail) - heights.begin() - 1;
		heights[pos] = tail;
		// printf("%d %lld\n", pos, tail);
	}

	return 0;

}