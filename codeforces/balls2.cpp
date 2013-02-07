#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()

bool assign[100005] = {false};
ll acnt[2] = {0LL}, bcnt[2] = {0LL}, values[100005];
int n, q, colors[100005], a, b;

int main() {
	cin >> n >> q;
	for(int i=0; i < n; i++) cin >> values[i];

	for(int i=0; i < n; i++) cin >> colors[i];

	for(int i=1; i < n; i++) {
		if (colors[i] == colors[i-1]) 
			assign[i] = 1;
	}

	for(int i=0; i < n; i++)
		if (assign[i] && values[i] > 0)
			acnt[0] += values[i];
	for(int i=0; i < n; i++)
		if (assign[i] && values[i] < 0)
			acnt[1] -= values[i];

	for(int i=0; i < n; i++)
		if (!assign[i] && values[i] > 0)
			bcnt[0] += values[i];
	for(int i=0; i < n; i++)
		if (!assign[i] && values[i] < 0)
			bcnt[1] -= values[i];
	printf("\n%lld %lld %lld %lld\n", acnt[0], acnt[1], bcnt[0], bcnt[1]);
	for(int i=0; i < q; i++) {
		cin >> a >> b;
		ll res = 0;
		if (a > 0) res += acnt[0]*a;
		else res += -acnt[1]*a;
		if (b > 0) res += bcnt[0] *b;
		else res += -bcnt[1]*b;
		cout << res << endl;

	}
	return 0;
}