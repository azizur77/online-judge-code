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

struct node {
	int x, y, d;
	node(int a, int b, int c) : x(a), y(b), d(c) {}
};

int main() {
	int n, p;

	cin >> n >> p;

	vi prev(n+1, -1);
	vi next(n+1, -1);
	vi flow(n+1, 1<<30);
	vector<bool> visited(n+1, false);

	for(int i=0; i < p; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		flow[x] = min(flow[x], z);
		flow[y] = min(flow[y], z);
		prev[y] = x;
		next[x] = y;
	}

	vector<node> ans;

	for(int i=1; i <= n; i++) 
		if (!visited[i] && prev[i] == -1) {
			int curr = i;
			int maxflow = flow[i];
			while (curr != -1 && !visited[curr]) {
				visited[curr] = 1;
				maxflow = min(maxflow, flow[curr]);
				if (next[curr] == -1 && curr != i) ans.push_back(node(i, curr, maxflow));
				curr = next[curr];
			}
		}

	cout << ans.size() << endl;
	for(int i=0; i < sz(ans); i++)
		cout << ans[i].x << " " << ans[i].y << " " << ans[i].d << endl;

	return 0;

}