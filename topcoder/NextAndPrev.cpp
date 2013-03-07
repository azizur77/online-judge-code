#line 2 "NextAndPrev.cpp"
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


class NextAndPrev {
	public:
	int getMinimum(int nextCost, int prevCost, string start, string goal) {
		
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
		cout << "Testing NextAndPrev (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362575536;
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
		NextAndPrev _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int nextCost = 5;
				int prevCost = 8;
				string start = "aeaae";
				string goal = "bcbbc";
				_expected = 21;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 1:
			{
				int nextCost = 5;
				int prevCost = 8;
				string start = "aeaae";
				string goal = "bccbc";
				_expected = -1;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 2:
			{
				int nextCost = 1;
				int prevCost = 1;
				string start = "srm";
				string goal = "srm";
				_expected = 0;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 3:
			{
				int nextCost = 1000;
				int prevCost = 39;
				string start = "a";
				string goal = "b";
				_expected = 975;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 4:
			{
				int nextCost = 123;
				int prevCost = 456;
				string start = "pqrs";
				string goal = "abab";
				_expected = -1;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 5:
			{
				int nextCost = 100;
				int prevCost = 19;
				string start = "topcoder";
				string goal = "ssszsffs";
				_expected = 676;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 6:
			{
				int nextCost = 1;
				int prevCost = 1000;
				string start = "csk";
				string goal = "wog";
				_expected = 64;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 7:
			{
				int nextCost = 7;
				int prevCost = 6;
				string start = "qwerty";
				string goal = "jjjjjj";
				_expected = 125;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			case 8:
			{
				int nextCost = 306;
				int prevCost = 26;
				string start = "me";
				string goal = "ii";
				_expected = 572;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}
			/*case 9:
			{
				int nextCost = ;
				int prevCost = ;
				string start = ;
				string goal = ;
				_expected = ;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}*/
			/*case 10:
			{
				int nextCost = ;
				int prevCost = ;
				string start = ;
				string goal = ;
				_expected = ;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
			}*/
			/*case 11:
			{
				int nextCost = ;
				int prevCost = ;
				string start = ;
				string goal = ;
				_expected = ;
				_received = _obj.getMinimum(nextCost, prevCost, start, goal); break;
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
