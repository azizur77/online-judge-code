#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

bool is_int(double x) { return x == floor(x); }

int main() {
	int T, a;
	cin >> T;
	for(int i=0; i < T; i++) {
		cin >> a;
		if (360 % (180 - a))
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}