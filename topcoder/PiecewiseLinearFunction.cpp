#line 2 "PiecewiseLinearFunction.cpp"
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
#include <map>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
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
typedef pair<float, float> pt;


class PiecewiseLinearFunction {
	public:
	int maximumSolutions(vector <int> Y) {
		for(int i=1; i < sz(Y); i++)
			if (Y[i] - Y[i-1] == 0)
				return -1;

		int maxsol = 0;

		for(int i=0; i < sz(Y); i++) {
			int y = Y[i]; // point

			int sol = 0;
			bool endflag = false;
			for(int j=1; j < sz(Y); j++) { // line
				int x1 = j, y1 = Y[j-1], y2 = Y[j];


				if ((y2 > y1 && y >= y1 && y <= y2) || (y1 > y2 && y >= y2 && y <= y1)) {
					if (y == y1 && endflag)
						endflag = false;
					else if (y == y2) {
						endflag = true;
						sol++;
					} else {
						endflag = false;
						sol++;
					}
				}
			}
			maxsol = max(maxsol, sol);
		}
		return maxsol;
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
		cout << "Testing PiecewiseLinearFunction (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1374941408;
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
		PiecewiseLinearFunction _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Y[] = {3, 2};
				_expected = 1;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int Y[] = {4, 4};
				_expected = -1;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int Y[] = {1, 4, -1, 2};
				_expected = 3;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int Y[] = {2, 1, 2, 1, 3, 2, 3, 2};
				_expected = 5;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int Y[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
				_expected = 6;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int Y[] = ;
				_expected = ;
				_received = _obj.maximumSolutions(vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
