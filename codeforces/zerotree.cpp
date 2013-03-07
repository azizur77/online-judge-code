#include <stdio.h>
#include <iostream>
#include <queue>
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

vi edges[100005];
bool seen[100005];
ll N, a, b, vals[100005];

int main() {
	cin >> N;
	for(int i=0; i < N-1; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for(int i=0; i < N; i++) cin >> vals[i];

	vector<ll> maxlevels(N, 0);
	vector<ll> minlevels(N, 0);
	fill(seen, 0);


	queue<ii> Q;
	Q.push(ii(1, 0));
	while(sz(Q)) {
		ii curr = Q.front();
		Q.pop();

		if (seen[curr.X]) continue;
		seen[curr.X] = 1;

		minlevels[curr.Y] = min(minlevels[curr.Y], vals[curr.Y]);
		maxlevels[curr.Y] = max(maxlevels[curr.Y], vals[curr.Y]);

		for(int i=0; i < sz(edges[curr.X]); i++) 
			Q.push(ii(edges[curr.X][i], curr.Y+1));
	}

	ll ans = 0;
	for(int i=0; i < N; i++) {
		ans += abs(minlevels[i]);
		ans  +=  abs(maxlevels[i]);
	}

	for(ll i=N-1; i >= 0; i--) {
		ans -= abs((i) * (minlevels[i] + maxlevels[i]));
	}

	cout << abs(ans) << endl;

}