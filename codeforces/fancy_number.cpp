#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

vector<int> get_counts(string &s) {
	vector<int> counts (10, 0);
	for(int i=0; i < sz(s); i++) counts[s[i] - '0']++;
	return counts; 
}

pair<int, string> find_cost(int dig, int k, string s) {
	vector<int> counts = get_counts(s);
	if (counts[dig] >= k) return make_pair(0, s);
	vector<int> delta(10, 0);
	int required = k - counts[dig];


	for(int i=1; i <= 9; i++) {
		if (dig + i <= 9) {
			delta[dig+i] = min(counts[dig+i], required);
			required -= delta[dig+i];
		} 
		if (dig - i >= 0) {
			delta[dig-i] = min(counts[dig-i], required);
			required -= delta[dig-i];
		}
	}

	int cost = 0;
	for(int i=0; i <= 9; i++) {
		cost += abs(dig-i) * delta[i];
	}

	for(int d=0; d <= 9; d++) {
		if (dig + d <= 9)
		for(int i=0; i < sz(s); i++)
			if (delta[dig+d] > 0 && (s[i] - '0') == dig + d) {
				s[i] = '0' + dig;
				delta[dig+d]--; 
			}

		if (dig-d >= 0)
		for(int i=sz(s)-1; i >= 0; i--)
			if (delta[dig-d] > 0 && (s[i] - '0') == dig - d) {
				s[i] = '0' + dig;
				delta[dig-d]--; 
			}
	}
	return make_pair(cost, s);
}

int main() {
	int n, k;
	string s;

	cin >> n >> k >> s;

	pair<int, string> best (1<<30, "");

	for(int i=0; i <= 9; i++) best = min(best, find_cost(i, k, s));

	cout << best.X << endl << best.Y << endl;

	return 0;

}