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

struct node {
	int r;
	string desc;
	int id, minimum;
	bool operator<(const node& other) const {
		if (r != other.r) return r < other.r;
		return id < other.id;
	}
	node (int a, string b, int c) : r(a), desc(b), id(c) {
		minimum = a;
	}
};

int main() {
	multiset<ii> heap;
	stack<node> S;
	int N;
	char s[20];
	scanf("%d", &N);
	for(int i=0; i < N; i++) {
		int rem;
		scanf("%d", &rem);
		if (rem == -1) {
			assert(sz(S));
			int minel = S.top().minimum;
			int cnt = 0;
			while(S.size()) {
				node head = S.top();
				S.pop();
				if (minel == head.r) {
					printf("%d %s\n", cnt, head.desc.c_str());
					break;
				}
				cnt++;
			}
		}
		else if (rem > 0) {
			scanf("%s", s);
			node n(rem, string(s), i);
			if (S.size() > 0) {
				n.minimum = min(S.top().minimum, rem);
			}
			S.push(n);
		}
		else {
			scanf("%s", s);
		}
	}
	return 0;
}