#line 2 "HeatDeath.cpp"
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


class HeatDeath {
	public:
	int maxTime(vector <int> energy) {
		
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
		cout << "Testing HeatDeath (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352689341;
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
		HeatDeath _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int energy[] = { 5, 7, 9 };
				_expected = 3;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
			}
			case 1:
			{
				int energy[] = { 5, 6, 5, 6 };
				_expected = 0;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
			}
			case 2:
			{
				int energy[] = { 1, 1, 1, 1, 1, 999, 999, 999, 999, 999 };
				_expected = 12435;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
			}
			case 3:
			{
				int energy[] = { 354, 903, 100, 951, 669, 311, 339, 500, 942, 72, 712, 54, 64,
				                 572, 7, 977, 74, 524, 314, 160, 526, 729, 114, 691, 771, 704,
				                 288, 47, 735, 85, 694, 124, 349, 905, 611, 371, 885, 738, 165,
				                 442, 138, 348, 605, 239, 535, 33, 142, 946, 4, 231 };
				_expected = 214090;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
			}
			/*case 4:
			{
				int energy[] = ;
				_expected = ;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int energy[] = ;
				_expected = ;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int energy[] = ;
				_expected = ;
				_received = _obj.maxTime(vector <int>(energy, energy+sizeof(energy)/sizeof(int))); break;
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
