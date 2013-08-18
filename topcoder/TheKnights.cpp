#line 2 "TheKnights.cpp"
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


class TheKnights {
	public:
	double find(int n, int a, int b) {
		
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
		cout << "Testing TheKnights (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362852113;
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
		TheKnights _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int a = 1;
				int b = 1;
				_expected = 3.3333333333333335;
				_received = _obj.find(n, a, b); break;
			}
			case 1:
			{
				int n = 47;
				int a = 7;
				int b = 74;
				_expected = 2.0;
				_received = _obj.find(n, a, b); break;
			}
			case 2:
			{
				int n = 3;
				int a = 2;
				int b = 1;
				_expected = 4.888888888888889;
				_received = _obj.find(n, a, b); break;
			}
			case 3:
			{
				int n = 9999;
				int a = 999;
				int b = 99;
				_expected = 16.25885103191273;
				_received = _obj.find(n, a, b); break;
			}
			case 4:
			{
				int n = 10;
				int a = 1;
				int b = 6;
				_expected = 7.636363636363637;
				_received = _obj.find(n, a, b); break;
			}
			/*case 5:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(n, a, b); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(n, a, b); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(n, a, b); break;
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
