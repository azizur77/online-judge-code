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
	int n;
	cin >> n;
	vector<ll> array(n, 0);
	for(int i=0; i < n; i++) cin >> array[i];

	sort(all(array));

	ll cost = 0;
	for(int i=0; i < n; i++) cost += abs(array[i] - i - 1);

	cout << cost << endl;

	return 0;
}