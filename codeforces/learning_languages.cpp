#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int n, adj[101][101], comp[101], m, ctr=0;
vi langs[101];

void connect(int i) {
	if (comp[i] != -1) return;
	comp[i] = ctr;
	for(int j=1; j <= n; j++)
		if (adj[i][j])
			connect(j);
}

int main() {
	cin >> n >> m;
	int tl=0;
	for(int i=1; i <= n; i++) {
		int k, x;
		cin >> k;
		for(int j=0; j < k; j++) {
			tl++;
			cin >> x;
			langs[x].push_back(i);
		} 
	} 

	if (tl == 0) {
		cout << n << endl;
		return 0;
	}

	fill(adj, 0);

	for(int i=1; i <= m; i++) 
		for(int j=0; j < sz(langs[i]); j++)
			for(int k=0; k < sz(langs[i]); k++) 
				if (langs[i][j] != langs[i][k]) 
					adj[langs[i][k]][langs[i][j]] = adj[langs[i][j]][langs[i][k]] = 1;
	
	fill(comp, -1);

	for(int i=1; i <= n; i++) 
		if (comp[i] == -1) {
			connect(i);
			ctr++;
		}
	
	cout << ctr-1 << endl;

	return 0;

}