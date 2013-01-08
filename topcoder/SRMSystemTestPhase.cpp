#line 2 "SRMSystemTestPhase.cpp"
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


class SRMSystemTestPhase {
	public:
	int countWays(vector <string> description) {
		
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
		cout << "Testing SRMSystemTestPhase (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352602868;
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
		SRMSystemTestPhase _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string description[] = {"YYY"};
				_expected = 27;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}
			case 1:
			{
				string description[] = {"YNN",
				                        "NYN"};
				_expected = 6;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}
			case 2:
			{
				string description[] = {"YNN",
				                        "NNN",
				                        "NNY"};
				_expected = 4;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}
			case 3:
			{
				string description[] = {"NNN",
				                        "NNN"};
				_expected = 1;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}
			case 4:
			{
				string description[] = {"YYY",
				                        "YNY",
				                        "NYY",
				                        "YYN",
				                        "YYY",
				                        "YNN"};
				_expected = 15176;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}
			/*case 5:
			{
				string description[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string description[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string description[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(description, description+sizeof(description)/sizeof(string))); break;
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
