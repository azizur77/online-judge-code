#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <string>
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
	ios_base::sync_with_stdio(0);
	int N, row_ctr=0, col_ctr=0, Q, t, x;
	cin >> N >> Q;
	string s;
	vi rows(N, 0);
	vi cols(N, 0);
	for(int i=0; i < Q; i++) {
		cin >> s >> t >> x;
		if (s[0] == 'R') {
			col_ctr += x;
			rows[t-1] += x;
		}
		else {
			row_ctr += x;
			cols[t-1] += x;
		}
	} 

	int rmax = *max_element(all(rows));
	int cmax = *max_element(all(cols));

	cout << rmax + cmax << endl;

	return 0;
}