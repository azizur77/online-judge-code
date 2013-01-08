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
	int n;
	cin >> n;
	int counts[25][61];
	fill(counts, 0);
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		counts[a][b]++;
	}
	int cashiers = 0;
	REP(i, 25) REP(j, 61) cashiers = max(cashiers, counts[i][j]); 
	cout << cashiers << endl;
	return 0;
}