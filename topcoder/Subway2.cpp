#line 2 "Subway2.cpp"
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
#define EPS 1e-9


class Subway2 {
	public:
	double minTime(int length, int maxAcceleration, int maxVelocity) {
		double t0 = 1.0 * maxVelocity / maxAcceleration;
		if (length < t0 * maxVelocity + EPS) return 2.0 * sqrt(1.0 * length / maxAcceleration);
		return double(length + t0 * maxVelocity) / maxVelocity;
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
		cout << "Testing Subway2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363349510;
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
		Subway2 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 1;
				int maxAcceleration = 2;
				int maxVelocity = 10;
				_expected = 1.4142135623730951;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 1:
			{
				int length = 1;
				int maxAcceleration = 1;
				int maxVelocity = 1;
				_expected = 2.0;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 2:
			{
				int length = 10;
				int maxAcceleration = 1;
				int maxVelocity = 1;
				_expected = 11.0;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 3:
			{
				int length = 1;
				int maxAcceleration = 10;
				int maxVelocity = 1;
				_expected = 1.1;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 4:
			{
				int length = 778;
				int maxAcceleration = 887;
				int maxVelocity = 384;
				_expected = 2.458961621570838;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			case 5:
			{
				int length = 336;
				int maxAcceleration = 794;
				int maxVelocity = 916;
				_expected = 1.301036207838119;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}
			/*case 6:
			{
				int length = ;
				int maxAcceleration = ;
				int maxVelocity = ;
				_expected = ;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}*/
			/*case 7:
			{
				int length = ;
				int maxAcceleration = ;
				int maxVelocity = ;
				_expected = ;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}*/
			/*case 8:
			{
				int length = ;
				int maxAcceleration = ;
				int maxVelocity = ;
				_expected = ;
				_received = _obj.minTime(length, maxAcceleration, maxVelocity); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
