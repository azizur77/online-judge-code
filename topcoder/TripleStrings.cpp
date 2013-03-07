#line 2 "TripleStrings.cpp"
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

struct node {
	string a, b, c;
	int l;
	const bool operator<(const node& rhs) const {
		if (a != rhs.a) return a < rhs.a;
		if (b != rhs.b) return b < rhs.b;
		return c < rhs.c;
	}
	// node(string x, string y, string z, int w) : a(x), b(y), c(z), l(w) {}
};

class TripleStrings {
	public:
	int getMinimumOperations(string init, string goal) {
		int i;
		for(i=0; i < sz(init); i++) 
			if (init.substr(i) == goal.substr(0, sz(goal) - i)) break;
		return 2*i;
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
		cout << "Testing TripleStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361617398;
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
		TripleStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string init = "ooxxox";
				string goal = "xoxoxo";
				_expected = 6;
				_received = _obj.getMinimumOperations(init, goal); break;
			}
			case 1:
			{
				string init = "oooxxoo";
				string goal = "oooxxoo";
				_expected = 0;
				_received = _obj.getMinimumOperations(init, goal); break;
			}
			case 2:
			{
				string init = "ox";
				string goal = "xo";
				_expected = 2;
				_received = _obj.getMinimumOperations(init, goal); break;
			}
			case 3:
			{
				string init = "ooxxooxx";
				string goal = "xxoxoxoo";
				_expected = 12;
				_received = _obj.getMinimumOperations(init, goal); break;
			}
			case 4:
			{
				string init = "oxxoxxoooxooooxxxoo";
				string goal = "oxooooxxxooooxoxxxo";
				_expected = 16;
				_received = _obj.getMinimumOperations(init, goal); break;
			}
			case 5:
			{
				string init = "xxxoxoxxooxooxoxooo";
				string goal = "oxxooxxooxxoxoxooxo";
				_expected = 36;
				_received = _obj.getMinimumOperations(init, goal); break;
			}
			/*case 6:
			{
				string init = ;
				string goal = ;
				_expected = ;
				_received = _obj.getMinimumOperations(init, goal); break;
			}*/
			/*case 7:
			{
				string init = ;
				string goal = ;
				_expected = ;
				_received = _obj.getMinimumOperations(init, goal); break;
			}*/
			/*case 8:
			{
				string init = ;
				string goal = ;
				_expected = ;
				_received = _obj.getMinimumOperations(init, goal); break;
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
