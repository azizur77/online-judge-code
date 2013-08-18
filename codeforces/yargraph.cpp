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

int adj[505][505] = {0}, n, deleted[505] = {0};

long long dijkstra(int node) {
	
}

int main() {
	cin >> n;
	for(int i=1; i <= n; i++)
		for(int j=1; j <= n; j++)
			cin >> adj[i][j];

}