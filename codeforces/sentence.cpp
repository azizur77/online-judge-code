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
	char t1[150];
	string s;
	int t;
	cin >> t;
	REP(i, t) {
		cin.getline(t1, 150);
		s = t1;
		int l = s.size(), a = 0, b = 0;
		if (l >= 5) {
		 a = s.substr(l-5, 5) == "lala.";
		 b = s.substr(0, 5) == "miao.";
		}
		if (a == 1 && b == 0) {
			puts("Freda's");
		} else if (a == 0 && b == 1) {
			puts("Rainbow's");
		} else {
			puts("OMG>.< I don't know!");
		}
	}
}