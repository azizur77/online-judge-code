#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

const double pi = atan(1) * 4.0;

double angle(int x, int y) {
	if (x == 0) {
		if (y > 0) return 90.0;
		else if (y == 0) return 0.0;
		return -90.0;
	}
	else if (y == 0) {
		if (x > 0) return 0.0;
		else if (x == 0) return 0.0;
		return 180.0;
	}
	double ratio = 1.0 * (double) y / (double) x;
	double temp = atan(ratio) * 180.0 / pi;
	if (x < 0 && y < 0) {
		return 180.0 - temp;
	}
	else if (x < 0 && y > 0) {
		return 180.0 + temp;
	}
	return temp;
}

double angle2(int x, int y) {
	double a = atan2(y, x) * 180.0 / pi;
	if (a < 0) a += 360.0;
	return a;
}

int main() {
	int n, x, y;
	cin >> n;
	if (n <= 1) {
		printf("%.10lf\n", 0.0);
		return 0;
	}
	double mina = 180.0, maxa = -180.0;
	for(int i=0; i < n; i++) {
		cin >> x >> y;
		double ang = angle2(x, y);
		mina = min(mina, ang);
		maxa = max(maxa, ang);
	}
	if (n == 2) {
		double ag = min(maxa - mina, 360.0 - maxa - mina);
		printf("%.10lf\n", ag);
		return 0;
	}
	assert(mina <= maxa);
	printf("%.10lf\n", maxa-mina);
	return 0;
}
