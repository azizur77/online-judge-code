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

string s, t;

int main() {
	cin >> s >> t;
	int z1=0, z2=0;
	for(int i=0; i < sz(s); i++) if (s[i] == '1') z1++;
	for(int i=0; i < sz(t); i++) if (t[i] == '1') z2++;
	if (z1 == 0 || z2 == 0 || sz(s) != sz(t)) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}