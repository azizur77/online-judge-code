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

struct entry {int index, a, b;} A[1000006];
int n;

bool cmp (entry x, entry y) { return x.a < y.a; }

int main() {
	cin >> n;
	for(int i=0; i < n; i++) {
		A[i].index = i;
		cin >> A[i].a >> A[i].b;
	}

	sort(A, A+n, cmp);

	int diff1=0, diff2=0;

	string s1(n, 'A');
	string s2(n, 'A');

	int AS = 0, GS = 0;

	for(int i=0; i < n; i++) {
		int idx = A[i].index;
		AS += (idx % 2) ? A[i].a : 0;
		GS += (idx% 2) ? 0: A[i].b;
		if (idx % 2 == 0) {
			s1[idx] = 'G';
		}
	}

	if (abs(AS - GS) <= 500) {
		cout << s1 << endl;
		return 0;
	}

	for(int i=0; i < n; i++) {
		int idx = A[i].index;
		AS += (idx % 2 == 0) ? A[i].a : 0;
		GS += (idx% 2 == 0) ? 0: A[i].b;
		if (idx % 2) {
			s2[idx] = 'G';
		}
	}

	if (abs(diff2) <= 500) {
		cout << s2 << endl;
	} else {
		puts("-1");
	}

		return 0;


}