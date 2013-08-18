#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define INF ll(1e9)
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int n, A[210000];
int done[210000];
ll memo[210000];
bool loop = 0;

ll solve(int idx) {
	if (idx < 1 || idx > n) return 0;
	if (memo[idx] == -2e8) { loop = 1; return -2e8;}
	if (memo[idx] != -1) return memo[idx];
	if (loop || done[idx] == 1) { loop = 1; return -2e8;}
	int x = idx;
	done[x] = 1;
	
	ll &y = memo[idx];
	y = 0;
	ll temp = A[idx];

	y += temp;
	idx += temp;

	if (idx <1 || idx > n) return y;
	
	y += A[idx];
	idx -= A[idx];

	temp = solve(idx);
	if (loop) y = -2e8;
	else y += temp;

	done[x] = 2;

	return y;

}


int main() {
	fill(A, 0);
	scanf("%d", &n);
	for(int i=2; i <= n; i++) scanf("%d", &A[i]);

	fill(memo, -1);
	fill(done, 0);

	if (n == 2 && A[2] == 0) {
		puts("-1");
		return 0;
	}

	for(int i=1; i < n; i++) {
		A[1] = i;
		ll ans = i;
		done[1] = 1;
		if (1 + i <= n && (1 + i) > 1) {
			ans += A[1 + i];
			loop = 0;
			ll q = solve(1 + i - A[1 + i]);
			if (loop) ans = -1;
			else ans += q;
		} 
		cout << ans << endl;
	}
	return 0;
}