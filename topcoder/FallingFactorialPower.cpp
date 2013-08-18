#line 2 "FallingFactorialPower.cpp"
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


class FallingFactorialPower {
	public:
	double compute(int n, int k) {
		if (k == 0) return 1;
		else if (k > 0) {
			double r = 1.0;
			for(int i=n; i > n-k; i--) r *= i;
			return r;
		}
		else {
			double r = 1.0;
			for(int i=1; i <= -k; i++)
				r *= (1.0 / double(n+i));
			return r;
		}
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
		cout << "Testing FallingFactorialPower (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362717438;
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
		FallingFactorialPower _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 7;
				int k = 3;
				_expected = 210.0;
				_received = _obj.compute(n, k); break;
			}
			case 1:
			{
				int n = 10;
				int k = 1;
				_expected = 10.0;
				_received = _obj.compute(n, k); break;
			}
			case 2:
			{
				int n = 5;
				int k = 0;
				_expected = 1.0;
				_received = _obj.compute(n, k); break;
			}
			case 3:
			{
				int n = 3;
				int k = -1;
				_expected = 0.25;
				_received = _obj.compute(n, k); break;
			}
			case 4:
			{
				int n = 2;
				int k = -3;
				_expected = 0.016666666666666666;
				_received = _obj.compute(n, k); break;
			}
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.compute(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.compute(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.compute(n, k); break;
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
