#line 2 "RoadOrFlightHard.cpp"
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

ll roadTimes[400100], flightTimes[400100], memo[41][2];
int _N, _K;

int solve(int curr, int K, bool flying) {
	if (curr == _N) return 0;
	if (memo[K][flying] >= 0) return memo[K][flying];
	ll ret = roadTimes[curr] + solve(curr+1, K, false);
	if (flying) {
		ret = min(ret, flightTimes[curr] + solve(curr+1, K, true));
	}
	else if (K > 0) {
		ret = min(ret, flightTimes[curr] + solve(curr+1, K-1, true));
	}
	memo[K][flying] = ret;
	return ret;
}

ll iterative() {
	ll dp[2][2][42] = {0};
	for(int i = _N-1; i >= 0; i--) {
		REP(k, _K+1) {
			if (k > 0)
				dp[1][0][k] = (ll) min(flightTimes[i] + dp[0][1][k-1], roadTimes[i] + dp[0][0][k]);
			else
				dp[1][0][k] = (ll) roadTimes[i] + dp[0][0][k];
			dp[1][1][k] = (ll) min(flightTimes[i] + dp[0][1][k], roadTimes[i] + dp[0][0][k]);
		}
		REP(f, 2) REP(j, _K+1) 
			dp[0][f][j] = dp[1][f][j];
	}
	return dp[1][0][_K];
}

class RoadOrFlightHard {
	public:
	long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
		_N = N;
		_K = K;
		fill(memo, -1);
		roadTimes[0] = roadFirst % roadMod;
		flightTimes[0] = flightFirst % flightMod;
		FOR(i, 1, N) {
			roadTimes[i] = (ll) (roadTimes[i-1]*roadProd + roadAdd) % roadMod;
		}
		FOR(i, 1, N) flightTimes[i] = (ll) (flightTimes[i-1]*flightProd + flightAdd) % flightMod;
		return iterative();
	}
};




























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
		cout << "Testing RoadOrFlightHard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352129344;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RoadOrFlightHard _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int roadFirst = 14;
				int roadProd = 1;
				int roadAdd = 2;
				int roadMod = 10;
				int flightFirst = 18;
				int flightProd = 1;
				int flightAdd = 10;
				int flightMod = 17;
				int K = 1;
				_expected = 14LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			case 1:
			{
				int N = 3;
				int roadFirst = 4;
				int roadProd = 1;
				int roadAdd = 2;
				int roadMod = 10;
				int flightFirst = 1;
				int flightProd = 1;
				int flightAdd = 10;
				int flightMod = 17;
				int K = 2;
				_expected = 11LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			case 2:
			{
				int N = 3;
				int roadFirst = 4;
				int roadProd = 1;
				int roadAdd = 2;
				int roadMod = 10;
				int flightFirst = 1;
				int flightProd = 1;
				int flightAdd = 6;
				int flightMod = 9;
				int K = 1;
				_expected = 12LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			case 3:
			{
				int N = 5;
				int roadFirst = 85739;
				int roadProd = 94847;
				int roadAdd = 93893;
				int roadMod = 98392;
				int flightFirst = 92840;
				int flightProd = 93802;
				int flightAdd = 93830;
				int flightMod = 92790;
				int K = 3;
				_expected = 122365LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}
			/*case 4:
			{
				int N = ;
				int roadFirst = ;
				int roadProd = ;
				int roadAdd = ;
				int roadMod = ;
				int flightFirst = ;
				int flightProd = ;
				int flightAdd = ;
				int flightMod = ;
				int K = ;
				_expected = LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int roadFirst = ;
				int roadProd = ;
				int roadAdd = ;
				int roadMod = ;
				int flightFirst = ;
				int flightProd = ;
				int flightAdd = ;
				int flightMod = ;
				int K = ;
				_expected = LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int roadFirst = ;
				int roadProd = ;
				int roadAdd = ;
				int roadMod = ;
				int flightFirst = ;
				int flightProd = ;
				int flightAdd = ;
				int flightMod = ;
				int K = ;
				_expected = LL;
				_received = _obj.minTime(N, roadFirst, roadProd, roadAdd, roadMod, flightFirst, flightProd, flightAdd, flightMod, K); break;
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
