#line 2 "DisjointSemicircles.cpp"
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


class DisjointSemicircles {
	public:
	string getPossibility(vector <int> labels) {
		
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
		cout << "Testing DisjointSemicircles (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1359479226;
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
		DisjointSemicircles _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int labels[] = { -1, 0, -1, -1, 0, -1 };
				_expected = "POSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			case 1:
			{
				int labels[] = { 1, -1, 2, 1, -1, 2 };
				_expected = "IMPOSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			case 2:
			{
				int labels[] = { 2, -1, -1, 0, -1, -1, 2, 0 };
				_expected = "POSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			case 3:
			{
				int labels[] = { -1, 1, 3, -1, 1, 3, -1, -1 };
				_expected = "IMPOSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			case 4:
			{
				int labels[] = { -1, 5, -1, -1, 3, 6, 8, -1, 10, 7, -1, 7, 8, 0, 11, -1, -1, 11, 0, 10, 4, -1, 6, 5, -1, -1, 9, 9, 4, 3 };
				_expected = "POSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			case 5:
			{
				int labels[] = { 4, -1, 2, 4, -1, 3, 3, 12, 2, 5, -1, 0, 9, 9, 8, -1, 12, 8, -1, 6, 0, -1, -1, -1, 5, 6, 10, -1, -1, 10 };
				_expected = "IMPOSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			case 6:
			{
				int labels[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
				_expected = "POSSIBLE";
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}
			/*case 7:
			{
				int labels[] = ;
				_expected = ;
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int labels[] = ;
				_expected = ;
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int labels[] = ;
				_expected = ;
				_received = _obj.getPossibility(vector <int>(labels, labels+sizeof(labels)/sizeof(int))); break;
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
