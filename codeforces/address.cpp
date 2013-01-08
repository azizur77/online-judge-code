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
	string addr, ans;
	cin >> addr;
	if (addr.substr(0, 4) == "http") {
		ans += "http://";
		addr = addr.substr(4);
	} 
	else if (addr.substr(0, 3) == "ftp") {
		ans += "ftp://";
		addr = addr.substr(3);
	}
	int pos = addr.rfind("ru");
	ans += addr.substr(0, pos);
	ans += ".ru";

	if (pos + 2 < addr.size()) {
		ans += "/" + addr.substr(pos+2);
	}

	cout << ans << endl;
	return 0	;

}