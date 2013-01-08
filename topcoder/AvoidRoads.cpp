#line 2 "AvoidRoads.cpp"
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


class AvoidRoads {
	public:
	long long numWays(int width, int height, vector <string> bad) {
		bool badroads[105][105][2];
		fill(badroads, false);
		ll dp[105][105];
		fill(dp, 0);

		for(int i=0; i < sz(bad); i++) {
			int a, b, c, d;
			sscanf(bad[i].c_str(), "%d %d %d %d", &a, &b, &c, &d);
			if (c - a > 0) badroads[a][b][0] = 1;
			else if (a - c > 0) badroads[c][d][0] = 1;
			else if (d - b > 0) badroads[a][b][1] = 1;
			else if (b - d > 0) badroads[c][d][1] = 1;
		}


		for(int i=width; i >= 0; i--)
			for(int j=height; j >= 0; j--) {
				if (i == width && j == height) dp[i][j] = 1;
				else {
					if (i+1 <= width && !badroads[i][j][0]) dp[i][j] += dp[i+1][j];
					if (j+1 <= height && !badroads[i][j][1]) dp[i][j] += dp[i][j+1];
				}
			}
		return dp[0][0];
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
		cout << "Testing AvoidRoads (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352693256;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AvoidRoads _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 6;
				int height = 6;
				string bad[] = {"0 0 0 1","6 6 5 6"};
				_expected = 252LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			case 1:
			{
				int width = 1;
				int height = 1;
				string bad[] = {};
				_expected = 2LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			case 2:
			{
				int width = 35;
				int height = 31;
				string bad[] = {};
				_expected = 6406484391866534976LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			case 3:
			{
				int width = 2;
				int height = 2;
				string bad[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
				_expected = 0LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}
			/*case 4:
			{
				int width = ;
				int height = ;
				string bad[] = ;
				_expected = LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				string bad[] = ;
				_expected = LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				string bad[] = ;
				_expected = LL;
				_received = _obj.numWays(width, height, vector <string>(bad, bad+sizeof(bad)/sizeof(string))); break;
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
