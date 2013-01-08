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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	int k, y, n;
	cin >> y >> k >> n;
	vi result;
	for(int m = 0; m <= n; m+=k)
		if (m - y > 0) result.push_back(m-y);
	if (result.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	REP(i, result.size()-1) cout << result[i] << " ";
	cout << result[result.size() - 1] << endl; 
	return 0;
}	