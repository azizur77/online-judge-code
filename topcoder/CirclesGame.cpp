#line 2 "CirclesGame.cpp"
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


class CirclesGame {
	public:
	string whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
		
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
		cout << "Testing CirclesGame (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1353468553;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CirclesGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0};
				int y[] = {0};
				int r[] = {1};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0, 3};
				int y[] = {0, 0};
				int r[] = {1, 1};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0, 0, 5};
				int y[] = {0, 0, 0};
				int r[] = {1, 2, 1};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 0, 0, 10, 10, 20};
				int y[] = {0, 0, 0, 0, 0, 0};
				int r[] = {1, 2, 3, 1, 2, 1};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {10,20,30,40,50,60,70,80};
				int y[] = {8,7,6,5,4,3,2,1};
				int r[] = {2,2,2,2,2,2,2,2};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {0, 3, 6, 9, 12, -4747, -4777};
				int y[] = {-5858, -5858, -5858, -5858, -5858, 777, 777};
				int r[] = {58, 1, 1, 1, 1, 44, 8};
				_expected = "Bob";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
				int y[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
				int r[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
				_expected = "Alice";
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int r[] = ;
				_expected = ;
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				int r[] = ;
				_expected = ;
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int x[] = ;
				int y[] = ;
				int r[] = ;
				_expected = ;
				_received = _obj.whoCanWin(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(r, r+sizeof(r)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
