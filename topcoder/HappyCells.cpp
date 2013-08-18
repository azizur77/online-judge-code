#line 2 "HappyCells.cpp"
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
#define valid(x, y) ((x) >= 0 && (x) < n && (y) >=0 && (y) < m)

class HappyCells {
	public:
	vector <int> getHappy(vector <string> grid) {
		int n = sz(grid);
		int m = sz(grid[0]);

		vector<int> happy(3, 0);

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				if (grid[i][j] == '.') {
					bool diag = 1, orth = 1;
					FOR(a, -1, 2) FOR(b, -1, 2) {
						if ((abs(a) + abs(b)) == 1 && valid(i+a, j+b))
							orth &= (grid[i+a][j+b] == 'X');
						else if ((abs(a) + abs(b)) == 2 && valid(i+a, j+b))
							diag &= (grid[i+a][j+b] == 'X');
					}
					if (diag && orth) happy[0]++;
					else if (!diag && orth) happy[1]++;
					else if (diag && !orth) happy[2]++;
				}
		return happy;
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
		cout << "Testing HappyCells (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362734840;
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
		HappyCells _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {
				                "XXX",
				                "X.X",
				                "XXX"
				                };
				int __expected[] = {1, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"."};
				int __expected[] = {1, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {
				                "XXXXXX",
				                "X.XXXX",
				                "XXX.XX",
				                "X..XXX",
				                "XXXXXX"
				                };
				int __expected[] = {1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"..."};
				int __expected[] = {0, 0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 4:
			{
				string grid[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string grid[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
