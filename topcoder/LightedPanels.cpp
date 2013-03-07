#line 2 "LightedPanels.cpp"
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
typedef unsigned long long ll;
typedef pair<ll, int> ii;

int n, m;

inline bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

class LightedPanels {
	public:
	int minTouch(vector<string> board) {
		int moves = 0;
		n = sz(board);
		m = sz(board[0]);

		for(int i=1; i < n; i++)
			for(int j=1; j < m; j++) {
				if (board[i][j] == '.')
			}
	}
	int minTouch1(vector <string> board) {
		n = sz(board);
		m = sz(board[0]);

		ll root = 0;
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				if(board[i][j] == '*') 
					root |= (1ULL << (i*n+j));

		ll goal = (1ULL << (n*m)) - 1;


		queue<ii> Q;
		set<ll> seen;
		Q.push(ii(root, 0));

		ll used = 0;

		while(Q.size() > 0) {
			ii curr = Q.front();
			Q.pop();
			if (seen.find(curr.X) != seen.end()) continue;
			seen.insert(curr.X);

			if (curr.X == goal) {
				return curr.Y;
			}

			for(int i=0; i < n; i++)
				for(int j=0; j < m; j++) {
					ll copy = curr.X;
					for(int dx=-1; dx <= 1; dx++)
						for(int dy=-1; dy <= 1; dy++)
							if (valid(i+dx, j+dy)) 
								copy ^= 1ULL << ((i+dx)*n + j + dy);
					if (seen.find(copy) == seen.end())
						Q.push(ii(copy, curr.Y+1));
				}
			}
		return -1;
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
		cout << "Testing LightedPanels (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362587431;
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
		LightedPanels _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"*****",
				                  "*...*",
				                  "*...*",
				                  "*...*",
				                  "*****"};
				_expected = 1;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {".*"};
				_expected = -1;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"**.",
				                  "**.",
				                  "..."};
				_expected = 2;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"*...",
				                  "**..",
				                  "..**",
				                  "...*"};
				_expected = 10;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minTouch(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
