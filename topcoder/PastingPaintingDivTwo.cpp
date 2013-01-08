#line 2 "PastingPaintingDivTwo.cpp"
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


int canvas[2][2501][2501] = {0};

class PastingPaintingDivTwo {
	public:
	long long countColors(vector <string> clipboard, int T) {
		int n = sz(clipboard);
		

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
		cout << "Testing PastingPaintingDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1354330088;
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
		PastingPaintingDivTwo _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string clipboard[] = {
				                     "..B",
				                     "B..",
				                     "BB."
				                     };
				int T = 3;
				_expected = 10LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 1:
			{
				string clipboard[] = {
				                     "B...",
				                     "....",
				                     "....",
				                     "...B"
				                     };
				int T = 2;
				_expected = 4LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 2:
			{
				string clipboard[] = {"BBB"};
				int T = 10000;
				_expected = 30000LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 3:
			{
				string clipboard[] = {"."};
				int T = 1000000000;
				_expected = 0LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 4:
			{
				string clipboard[] = {
				                     "BB.",
				                     ".B."
				                     };
				int T = 100;
				_expected = 201LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 5:
			{
				string clipboard[] = {
				                     "..........B..........",
				                     ".........B.B.........",
				                     "........B...B........",
				                     ".......B.....B.......",
				                     "......B..B.B..B......",
				                     ".....B...B.B...B.....",
				                     "....B...........B....",
				                     "...B...B.....B...B...",
				                     "..B.....BBBBBB....B..",
				                     ".B..........BB.....B.",
				                     "BBBBBBBBBBBBBBBBBBBBB"
				                     };
				int T = 1000000000;
				_expected = 21000000071LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			/*case 6:
			{
				string clipboard[] = ;
				int T = ;
				_expected = LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}*/
			/*case 7:
			{
				string clipboard[] = ;
				int T = ;
				_expected = LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}*/
			/*case 8:
			{
				string clipboard[] = ;
				int T = ;
				_expected = LL;
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
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
