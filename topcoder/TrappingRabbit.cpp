#line 2 "TrappingRabbit.cpp"
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


class TrappingRabbit {
	public:
	int findMinimumTime(vector <int> trapX, vector <int> trapY) {
		int n = sz(trapX);
		int m = INF;
		for(int i=0; i < n; i++) {
			m = min(abs(trapX[i] - 1) + abs(trapY[i] - 1), m);
		}
		return m;
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
		cout << "Testing TrappingRabbit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1354326622;
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
		TrappingRabbit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int trapX[] = {4,6,8};
				int trapY[] = {1,2,1};
				_expected = 3;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			case 1:
			{
				int trapX[] = {5,4,3};
				int trapY[] = {5,4,3};
				_expected = 4;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			case 2:
			{
				int trapX[] = {3,4,5};
				int trapY[] = {5,4,3};
				_expected = 6;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			case 3:
			{
				int trapX[] = {958,375,195,686,483,629,377};
				int trapY[] = {104,505,882,357,759,400,869};
				_expected = 878;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}
			/*case 4:
			{
				int trapX[] = ;
				int trapY[] = ;
				_expected = ;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int trapX[] = ;
				int trapY[] = ;
				_expected = ;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int trapX[] = ;
				int trapY[] = ;
				_expected = ;
				_received = _obj.findMinimumTime(vector <int>(trapX, trapX+sizeof(trapX)/sizeof(int)), vector <int>(trapY, trapY+sizeof(trapY)/sizeof(int))); break;
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
