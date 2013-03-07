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
	int d[101], n, s, t, sum=0;
	cin >> n;
	for(int i=0; i < n; i++) {
		cin >> d[i];
		sum += d[i];
	}

	cin >> s >> t;
	int dist = 0;

	for(int i=(s-1+n) % n; (i+n) % n != ((t-1+n) % n); i++)
		dist += d[(i+n) % n];
	cout << min(sum - dist, dist) << endl;
}