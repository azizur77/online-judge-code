#line 2 "ArcadeManao.cpp"
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
#include <queue>
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


struct node
{
	int x, y, cost;
	node(int a, int b, int c) : x(a), y(b), cost(c) {}
	const bool operator<(const node& rhs) const {
		return cost > rhs.cost;
	}
};

bool seen[55][55] = {0};

class ArcadeManao {
	public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		priority_queue<node> heap;
		coinRow--;
		coinColumn--;
		heap.push(node(coinRow, coinColumn, 0));
		int n = sz(level);
		int m = sz(level[0]);

		while (heap.size()) {
			node curr = heap.top();
			heap.pop();
			if (seen[curr.x][curr.y]) continue;
			seen[curr.x][curr.y] = 1;

			if (curr.x == n-1)
				return curr.cost;

			// left, right
			if (curr.y > 0 && level[curr.x][curr.y-1] == 'X')
				heap.push(node(curr.x, curr.y-1, curr.cost));
			if (curr.y < m-1 && level[curr.x][curr.y+1] == 'X')
				heap.push(node(curr.x, curr.y+1, curr.cost));
			// top, down
			for(int i=curr.x-1; i >= 0; i--) {
				if (level[i][curr.y] == 'X')
					heap.push(node(i, curr.y, max(curr.cost, curr.x - i)));
			}
			for(int i=curr.x+1; i < n; i++) {
				if (level[i][curr.y] == 'X')
					heap.push(node(i, curr.y, max(curr.cost, i - curr.x)));
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
		cout << "Testing ArcadeManao (576.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365729338;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 576.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ArcadeManao _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string level[] = {"XXXX....",
				                  "...X.XXX",
				                  "XXX..X..",
				                  "......X.",
				                  "XXXXXXXX"};
				int coinRow = 2;
				int coinColumn = 4;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 1:
			{
				string level[] = {"XXXX",
				                  "...X",
				                  "XXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 1;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 2:
			{
				string level[] = {"..X..",
				                  ".X.X.",
				                  "X...X",
				                  ".X.X.",
				                  "..X..",
				                  "XXXXX"};
				int coinRow = 1;
				int coinColumn = 3;
				_expected = 4;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 3:
			{
				string level[] = {"X"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 0;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 4:
			{
				string level[] = {"XXXXXXXXXX",
				                  "...X......",
				                  "XXX.......",
				                  "X.....XXXX",
				                  "..XXXXX..X",
				                  ".........X",
				                  ".........X",
				                  "XXXXXXXXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			/*case 5:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 6:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 7:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
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
