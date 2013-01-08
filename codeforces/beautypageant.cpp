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
	int n, k;
	vi beauties;
	cin >> n >> k;
	REP(i, n) {
		int x;
		cin >> x;
		beauties.push_back(x);
	}
	sort(all(beauties));
	vector <vi> answers;

	for(int w=1; w <= n; w++) {
		for(int i=0; i <= n-w; i++) {
			vi answer(1, w);
			for (int j=i; j < i+w; j++) answer.push_back(beauties[j]);
			answers.push_back(answer);
		}
	}

	for(int i=0; i < k; i++) {
		int s = sz(answers[i]);
		for(int j=0; j < s - 1; j++) cout << answers[i][j] << " ";
		cout << answers[i][s-1] << endl;
	}



	return 0;
}