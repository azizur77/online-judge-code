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

int adj[55][55], comp[55][55];
int n, m, ctr=0;

void connect(int x, int y) {
	if (!adj[x][y]) return;
	if (comp[x][y] != -1) return;
	comp[x][y] = ctr;
	for(int i=-1; i <= 1; i++)
		for(int j=-1; j <= 1; j++)
			if ((abs(i) + abs(j) == 1) && (x+i) >= 0 && (x+i) < n && (y+i) >= 0 && (y+j) < m) {
				connect(x+i, y+j);
			}
}

int main() {
	fill(adj, 0);
	fill(comp, -1);

	string s;
	cin >> n >> m;
	for(int i=0; i < n; i++) {
		cin >> s;
		for(int j=0; j < m; j++)
			adj[i][j] = (s[j] == 'B');
	} 

	for(int i=0; i < n; i++)
		for(int j=0; j < m; j++)
			if (adj[i][j] == 1 && comp[i][j] == -1) {
				ctr++;
				connect(i, j);
			}
	if (ctr > 1) {
		puts("NO");
		return 0;
	}
	bool flag = true;

	for(int i=0; i < n; i++)
		for(int j=0; j < m-2; j++) 
			if (adj[i][j] == 1 && adj[i][j+1] == 0) {
				int pos = j+1;
				while(pos < m && adj[i][pos] == 0) pos++;
				if (pos < m) flag = false;  
			}

	for(int j=0; j < m; j++)
		for(int i=0; i < n-2; i++) 
			if (adj[i][j] == 1 && adj[i+1][j] == 0) {
				int pos = i+1;
				while(pos < n && adj[pos][j] == 0) pos++;
				if (pos < n) flag = false;
			}

	if (flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}