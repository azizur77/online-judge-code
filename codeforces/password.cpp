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


int Z[1000005];
bool seen[1000005];
string S;   

int main() {
	fill(Z, 0);
	fill(seen, 0);
	ios_base::sync_with_stdio(0);
	cin >> S;

	// Z Algorithm
	int L = -1, R = -1;

	for(int i=1; i < sz(S); i++) {
		if (i > R) {
			L = R = i;
			while(R < sz(S) && S[R-L] == S[R]) R++;
			Z[i] = R - L;
			R--;
		}
		else if (Z[i-L] < R-i+1) {
			Z[i] = Z[i-L];
		}
		else {
			L = i;
			while(R < sz(S) && S[R-L] == S[R]) R++;	
			Z[i] = R - L;
			R--;
		}
	}

	int best = 0;

	R = 0;
	for(int i=1; i < sz(S); i++) {
		if (Z[i] == (sz(S) - i) && R >= (sz(S) - i)) {
			best = Z[i];
			break;
		}
		R = max(R, Z[i]);
	}


	if (best > 0)
		cout << S.substr(0, best) << endl;
	else
		cout << "Just a legend" << endl;
 
}