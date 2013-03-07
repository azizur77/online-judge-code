#line 2 "SpeedRadar.cpp"
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


class SpeedRadar {
	public:
	double averageSpeed(int minLimit, int maxLimit, vector <int> readings) {
		
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
		cout << "Testing SpeedRadar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362283250;
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
		SpeedRadar _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int minLimit = 1;
				int maxLimit = 50;
				int readings[] = {45, 40, 50};
				_expected = 45.0;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
			}
			case 1:
			{
				int minLimit = 1;
				int maxLimit = 50;
				int readings[] = {42,43,44,45,46,47,48,49,50,51};
				_expected = 46.0;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
			}
			case 2:
			{
				int minLimit = 1;
				int maxLimit = 50;
				int readings[] = {42,46,48,50,52};
				_expected = 0.0;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
			}
			case 3:
			{
				int minLimit = 20;
				int maxLimit = 60;
				int readings[] = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54};
				_expected = 41.68421052631579;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
			}
			/*case 4:
			{
				int minLimit = ;
				int maxLimit = ;
				int readings[] = ;
				_expected = ;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int minLimit = ;
				int maxLimit = ;
				int readings[] = ;
				_expected = ;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int minLimit = ;
				int maxLimit = ;
				int readings[] = ;
				_expected = ;
				_received = _obj.averageSpeed(minLimit, maxLimit, vector <int>(readings, readings+sizeof(readings)/sizeof(int))); break;
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
