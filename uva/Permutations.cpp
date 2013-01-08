// 941 - Permutations
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
typedef unsigned long long ull;

ull fact[21];


ull count_perms(string s) {
	sort(all(s));
	ull f = fact[sz(s)];
	for(int i=0; i < sz(s); i++) {
		int den = 0;
		char p = s[i];
		while(s[i] == p) {
			i++;
			den++;
		}
		f /= fact[den];
	}
	return f;
}

int main() {
	fact[0] = 1;
	for(int i=1; i < 21; i++) fact[i] = i * fact[i-1];
	int T;
	ull k;
	string S;
	cin >> T;
	while(T--) {
		cin >> S >> k;
		k++;
		sort(all(S));

		string state = S, pi;
		for(int i=0; i < sz(S); i++) {
			bool seen[26] = {0};
			sort(all(state));
			for(int j=0; j < sz(state); j++) {
				if (seen[state[j] - 'a']) continue;
				seen[state[j] - 'a'] = 1;
				string temp = state.substr(0, j) + state.substr(j+1);
				ull cp = count_perms(temp);
				// printf("(dbg) %llu, %llu, %c, %s\n", cp, k, state[j], temp.c_str());
				if (k <= cp) {
					pi += state[j];
					state = temp;
					break;
				} 
				k -= cp;
			}
		}
		cout << pi << endl;
	}
	return 0;
}