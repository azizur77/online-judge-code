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

ll numbers[101];

int main() {
	ll tries = 0;

	int n;
	cin >> n;
	for(int i=1; i <= n; i++) cin >> numbers[i];

	for(int i=1; i <= n; i++) tries += (numbers[i] - 1) * ll(i);

	tries += n;

	cout << tries << endl;

	return 0;
}