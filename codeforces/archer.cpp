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
	double a, b, c, d, p, q, r;
	cin >> a >> b >> c >> d;
	p = a / b;
	q = c / d;
	r = (1 - p) * (1 - q);

	printf("%.12lf\n", p / (1 - r));
	return 0;
}