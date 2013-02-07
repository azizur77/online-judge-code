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

int main() {
	int x, hits = 0;
	cin >> x;
	hits = x;

	for(int i=1; i <= x-1; i++) hits += (i * (x-i));

	cout << hits << endl;

	return 0;
}