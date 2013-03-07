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


int fn(int x) {
	int v = 0;
	while(x > 0) {
		if (x % 2) v++;
		x /= 2;
	}
	return v;
}


int main() {
	int n;
	cin >> n;
	vi numbers(n, 0);
	vi values(n, 0);
	vi indices(n, 0);
	for(int i=0; i < n; i++) cin >> numbers[i];
	for(int i=0; i < n; i++) values[i] = fn(numbers[i]);
	for(int i=0; i < n; i++) indices[i] = i;

	sort(all(values));

	ll ctr = 0;
	ll nways = 0;

	for(int i=0; i < n; i++) {
		if (i == 0 || values[i] == values[i-1]) ctr++;
		else {
			if (ctr > 0) {
				ll temp = (ctr*(ctr-1)) / 2LL;
				nways += temp;
			}
			ctr = 1;
		}
	}
	if (ctr > 0) {
				ll temp = (ctr*(ctr-1)) / 2LL;
				nways += temp;

	}

	cout << nways << endl;

	return 0;

}