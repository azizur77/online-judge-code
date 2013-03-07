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
	int x, n, t;
	cin >> n >> t;
	vector<int> books(n+1, 0);
	for(int i=1; i <= n; i++) {
		cin >> x;
		books[i] = x + books[i-1];
	}

	int maxbooks = 0, left=0;

	for(int right=1; right <= n; right++) {
		while(books[right] - books[left] > t) left++;
		maxbooks = max(maxbooks, right-left);
	}

	cout << maxbooks << endl;

	return 0;
}