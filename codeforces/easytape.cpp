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


vi counts(string prog) {
	vi result(10, 0);
	int curr = 0, dn = 1;
	vector<char> program(all(prog));
	int n = program.size();
	bool zflag = false;
	bool dflag = false;
	while(curr >= 0 && curr < program.size()) {
		int prev = curr - dn;
		// cout << "(dbg) " << string(all(program)) << endl;

		if (zflag || (dflag && (program[curr] == '<' || program[curr] == '>'))) {
			program.erase(program.begin() + prev);
			if (dn == 1) curr--;
		}
		zflag = dflag = 0;


		if (program[curr] >= '0' && program[curr] <= '9') {
			result[program[curr] - '0']++;
			if (program[curr] > '0') {
				program[curr]--;
			}
			else zflag = true;
		}
		else {
			dflag = true;
			if (program[curr] == '<') dn = -1;
			else if (program[curr] == '>') dn = 1;
		}
		curr += dn;
	}
	return result;
}

int main() {
	string program;
	int n, q;
	cin >> n >> q >> program;
	REP(i, q) {
		int l, r;
		cin >> l >> r;
		vi ans = counts(program.substr(l-1, r-l+1));
		REP(j, 9) cout << ans[j] <<  " ";
		cout << ans[9] << endl;
	}
	return 0;
}