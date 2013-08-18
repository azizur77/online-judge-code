#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
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

vector<int> edges[2001];
bool forbidden[2001][2001];
int manager[2001], seen[2001];

int main() {
	int n;
	cin >> n;
	fill(manager, -1);
	fill(seen, 0);
	fill(forbidden, 0);

	for(int i=0; i < n; i++) {
		int man;
		cin >> man;
		manager[i+1] = man;
	}	

	int depth = 0;

	for(int i=1; i <= n; i++) {
		int d = 1;
		int ptr = i;
		while(manager[ptr] != -1) {
			ptr = manager[ptr];
			d++;
		}
		depth = max(depth,d);
	}
	cout << depth << endl;

	return 0;
}