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

bool distinct(int y) {
	bool seen[10] = {false};
	for(; y > 0; y /= 10) {
		if (seen[y % 10]) return false;
		seen[y % 10] = 1;
	}
	return true;
}


int main() {
	int year;
	cin >> year;
	year++;
	while (!distinct(year)) year++;
	cout << year << endl;
	return 0;
}