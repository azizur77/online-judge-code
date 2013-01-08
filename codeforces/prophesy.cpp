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
	string prop;
	cin >> prop;
	int MOMAX[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int counter[32][13][4], len = sz(prop);
	fill(counter, 0);
	for(int start=0; start <= len - 10; start++) {
		int day, month, year;
		if (prop[start] == '-' || prop[start+1] == '-') continue;
		day = (prop[start] - '0') * 10 + (prop[start+1] - '0');
		if (day <= 0) continue;
		if (prop[start+2] != '-') continue;
		if (prop[start+3] == '-' || prop[start+4] == '-') continue;
		month = (prop[start+3] - '0') * 10 + (prop[start+4] - '0');
		if (month > 12) continue;
		if (month <= 0) continue;
		if (day > MOMAX[month-1]) continue;
		if (prop[start+5] != '-') continue;
		if (prop[start+6] != '2' || prop[start+7] != '0' || prop[start+8] != '1') continue;
		year = prop[start+9] - '3';
		if (year > 2 || year < 0) continue;
		counter[day][month][year]++;			
	}
	int mday=0, mmonth=0, myear=0, mctr = -INF;
	for(int day=1; day < 32; day++)
		for(int month=1; month < 13; month++)
			for(int year=0; year < 3; year++)
				if (mctr < counter[day][month][year]) {
					mday = day;
					mmonth = month;
					myear = year;
					mctr = counter[day][month][year];
				}
	printf("%02d-%02d-%d\n", mday, mmonth, myear+2013);
	return 0;
}