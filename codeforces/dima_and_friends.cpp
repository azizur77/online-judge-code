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
	int n, s=0, x;
	cin >> n;

	for(int i=0; i < n; i++)  {
		cin >> x;
		s += x;
	}
	int ctr=0;
	for(int i=1; i <= 5; i++) {
		if ((s+i) % (n+1) != 1) {
			ctr++;
		}
	}
			cout << ctr << endl;
	return 0;

}