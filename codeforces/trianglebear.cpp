#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	int x, y, z;
	cin >> x >> y;
	z = abs(x) + abs(y);
	if (x > 0 && y > 0) 
		printf("%d %d %d %d\n", 0, z, z, 0);
	else if (x < 0 && y > 0) 
		printf("%d %d %d %d\n", -z, 0, 0, z);
	else if (x < 0 && y < 0)
		printf("%d %d %d %d\n", -z, 0, 0, -z);
	else
		printf("%d %d %d %d\n", 0, -z, z, 0);
}