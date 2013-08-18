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
	int n, k;
	cin >> n >> k;
	for(int i=1; i <= n-k-1; i++) cout << i << " ";
	for(int i=n; i >= n-k; i--) cout << i << " ";
	cout << endl;
	return 0;
}