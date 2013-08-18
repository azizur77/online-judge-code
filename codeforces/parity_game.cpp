#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <string>
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
	string a, b;
	cin >> a >> b;
	int count_ones_a = 0, count_ones_b = 0, parity = 0;

	for(int i=0; i < sz(a); i++) {
		if (a[i] == '1') {
			count_ones_a++;
			parity ^= 1;
		}
	}
	for(int i=0; i < sz(b); i++) {
		if (b[i] == '1') count_ones_b++;
	}

	if (parity) {
		puts((count_ones_b <= count_ones_a + 1) ? "YES" : "NO");
	} else {
		puts((count_ones_b <= count_ones_a) ? "YES" : "NO");
	}

	return 0;

}