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
	string str;
	cin >> str;
	int first=0;
	while(first < sz(str) && str[first] != '0') first++;
	if (sz(str) == first) 
		cout << str.substr(0, sz(str)-1) << endl;
	else {
		string ans = str.substr(0, first) + str.substr(first+1);
		cout << ans << endl;
	}
	return 0;
}