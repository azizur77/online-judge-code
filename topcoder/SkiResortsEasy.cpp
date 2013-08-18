#line 2 "SkiResortsEasy.cpp"
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


class SkiResortsEasy {
	public:
	int minCost(vector <int> altitude) {
		int prev = INF, cost = 0;
		for(int i=0; i < sz(altitude); i++) {
			if (altitude[i] > prev) {
				cost += altitude[i] - prev;
			}
			prev = min(prev, altitude[i]);
		}
		return cost;
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
		cout << "Testing SkiResortsEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363309818;
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
		SkiResortsEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int altitude[] = {30, 20, 20, 10};
				_expected = 0;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 1:
			{
				int altitude[] = {5, 7, 3};
				_expected = 2;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 2:
			{
				int altitude[] = {6, 8, 5, 4, 7, 4, 2, 3, 1};
				_expected = 6;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 3:
			{
				int altitude[] = {749, 560, 921, 166, 757, 818, 228, 584, 366, 88};
				_expected = 2284;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			case 4:
			{
				int altitude[] = {712, 745, 230, 200, 648, 440, 115, 913, 627, 621, 186, 222, 741, 954, 581, 193, 266, 320, 798, 745};
				_expected = 6393;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}
			/*case 5:
			{
				int altitude[] = ;
				_expected = ;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int altitude[] = ;
				_expected = ;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int altitude[] = ;
				_expected = ;
				_received = _obj.minCost(vector <int>(altitude, altitude+sizeof(altitude)/sizeof(int))); break;
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
