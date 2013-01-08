#line 2 "TheMoviesLevelThreeDivOne.cpp"
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
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll dp[2][951][1901] = {0};

ll solve(int n, vi &a, vi &b) {
	fill(dp, 0);
	int mx = *max_element(all(a));
	mx = max(mx, *max_element(all(b)));
	int shift = mx * n;
	dp[0][shift][shift] = 1;
	int bounds[n];
	REP(i, n) {
		bounds[i] = min(2 * (i+1) * mx, shift);
	}
	for(int i=0; i < n; i++) {
		for(int low = -bounds[i]; low <= 0; low++) {
			for(int sum = -bounds[i]; sum <= bounds[i]; sum++) {
				int cnt = dp[0][low+shift][sum+shift];
				if (cnt > 0) {
					// Add to first queue
					dp[1][min(0, low + a[i]) + shift][sum + a[i] + shift] += cnt;
					// Add to second queue
					dp[1][min(low, sum - b[i]) + shift][sum - b[i] + a[i] + shift] += cnt;
				}
			}
		}
		memcpy(dp[0], dp[1], sizeof (dp[0]));
		fill(dp[1], 0);
	}
	ll nways = 0;
	REP(i, shift) REP(j, 2 * shift + 2) nways += dp[0][i][j];
	return nways;
}

class TheMoviesLevelThreeDivOne {
	public:
	long long find(vector <int> timeJ, vector <int> timeB) {
		int n = sz(timeB);
		return (1LL << n) - solve(n, timeJ, timeB) - solve(n, timeB, timeJ);
	}
};





#undef min






















// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing TheMoviesLevelThreeDivOne (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352183942;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMoviesLevelThreeDivOne _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int timeJ[] = {4, 4};
				int timeB[] = {4, 4};
				_expected = 2LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 1:
			{
				int timeJ[] = {1, 4};
				int timeB[] = {4, 2};
				_expected = 1LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 2:
			{
				int timeJ[] = {10, 10, 10, 10};
				int timeB[] = {1, 1, 1, 10};
				_expected = 3LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			case 3:
			{
				int timeJ[] = {1, 2, 3, 4, 5, 6, 7};
				int timeB[] = {7, 6, 5, 4, 3, 2, 1};
				_expected = 98LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}
			/*case 4:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int timeJ[] = ;
				int timeB[] = ;
				_expected = LL;
				_received = _obj.find(vector <int>(timeJ, timeJ+sizeof(timeJ)/sizeof(int)), vector <int>(timeB, timeB+sizeof(timeB)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
