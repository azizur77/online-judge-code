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
#define MOD 1000000007

int A[1005], T[5005];

void build_tree(int x, int a, int b) {
	if (a > b) return;
	if (a == b) {
		T[x] = A[a];
	}
	int lt = 2*x, rt=lt+1, mid = (a+b) / 2;
	build_tree(lt, a, mid);
	build_tree(rt, mid+1, b);
	T[x] = 
}


int main() {
	scanf("%d", &N);
	if (N > 300) {
		printf("%d\n", 0);
	}
	else {
		for(int i=0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		ll product = 1;
		for(int i=0; i < N; i++) {
			for(int j=1; i+j < N; j++) {
				ll range = *max_element(A+i, A+i+j+1) - *min_element(A+i, A+i+j+1);
				product = (product * range) % MOD;
			}
		}
		printf("%lld\n", product % MOD);
	}
	return 0;
}