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
	int n, k = -1;
	cin >> n;
	vector<unsigned> A(n, 0);
	for(int i=0; i < n; i++) cin >> A[i];


	for(int i=31; i >= 0; i--) {
		bool flag = false;
		if ((A[n-1] >> i) > 0) {
			for(int j=i; j >= 0; j--) {
				k = 0;
				while ((A[n-1-k] >> j) > 0) {
					k++;
				}
				int check = A[n-1];
				for(int x=0; x < k; x++)
					check = check & A[n-1-x];
				cout << check << endl;
				if (check == (1u << j)) {
					flag = true;
					break;
				}
			}
		}
		if (flag) break;
		k = -1;
	}

	cout << k << endl;
	for(int i=0; i < k; i++)
		cout << A[n-1-i] << " ";
	return 0;
}