#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
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
	int n, s, t;
	cin >> n >> s >> t;
	vector<int> link(n+1, 0);
	vector<int> seen(n+1, 0);
	for(int i=1; i <= n; i++) cin >> link[i];
	int steps = -1;

	queue<ii> Q;
	Q.push(ii(s, 0));

	while(Q.size() > 0) {
		ii curr = Q.front();
		Q.pop();
		if (seen[curr.X]) continue;
		seen[curr.X] = 1;

		if (curr.X == t) {
			steps = curr.Y;
			break;
		}

		Q.push(ii(link[curr.X], curr.Y+1));
	}

	cout << steps << endl;

	return 0;
}