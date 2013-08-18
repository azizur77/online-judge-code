#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <stack>
#include <set>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int main() {
	int n, w, t, T=0, W;
	cin >> n;
	vector<int> books1, books2;
	
	for(int i=0; i < n; i++) {
		cin >> t >> w;
		if (t == 1) books1.push_back(w);
		else books2.push_back(w);
	}

	sort(all(books1));
	reverse(all(books1));
	sort(all(books2));
	reverse(all(books2));

	for(int v1=0; v1 < sz(books1); v1++)
		for(int v2=0; v2 < sz(books2); v2++)
	


	return 0;
}