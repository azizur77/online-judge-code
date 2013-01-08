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
	int T;
	cin >> T;
	for(int t=0; t < T; t++) {
		int n;
		cin >> n;
		vi shop(n);
		for(int i=0; i < n; i++) cin >> shop[i];
		sort(all(shop));
		reverse(all(shop));
		int disc = 0;
		for(int i=2; i < n; i+=3) disc += shop[i];
		cout << disc << endl;
	}	
	return 0;
}