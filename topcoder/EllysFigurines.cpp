#line 2 "EllysFigurines.cpp"
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

vector<string> B;
int memo[51][51], _R, _C, m, n;

int find_moves(int mask, int cont) {
	int moves = 0;
	for(int i=0; i < max(m, n); i++) {
		if (mask & 1)
			moves++;
		mask >>= cont;
	}
	return moves;
}

int minmoves(int mask) {
	vector<string> BB(all(B));
	int rmask = mask;
	for(int i=0; i < m; i++) {
		if (mask & 1) 
			for(int j=0; j < _R && i+j < m; j++)
				BB[i+j] = string(n, '.');
		mask >>= 1;
	}
	bool col[16];
	for(int i=0; i < n; i++) {
		col[i] = false;
		for(int j=0; j < m; j++) {
			if (BB[j][i] == 'X') {
				col[i] = true;
				break;
			}
		}
	}

	int cmask = 0;

	for(int i=0; i < n; i++)
		cmask = col[i] + 2*cmask;
	return find_moves(rmask, _R) + find_moves(cmask, _C);

}

class EllysFigurines {
	public:
	int getMoves(vector <string> board, int R, int C) {
		B = board;
		_R = R;
		_C = C;
		m = sz(board);
		n = sz(board[0]);
		int moves = INF;
		for(int i=0; i < (1<<(m-1)); i++)
			moves = min(moves, minmoves(i));
		return moves;
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
		cout << "Testing EllysFigurines (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362244719;
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
		EllysFigurines _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".X.X.",
				                  "XX..X",
				                  ".XXX.",
				                  "...X.",
				                  ".X.XX"};
				int R = 1;
				int C = 2;
				_expected = 3;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 1:
			{
				string board[] = {".X.X.",
				                  "XX..X",
				                  ".X.X.",
				                  "...X.",
				                  ".X.XX"};
				int R = 2;
				int C = 2;
				_expected = 2;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 2:
			{
				string board[] = {"XXXXXXX"};
				int R = 2;
				int C = 3;
				_expected = 1;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 3:
			{
				string board[] = {"XXXXX",
				                  "X....",
				                  "XXX..",
				                  "X....",
				                  "XXXXX"};
				int R = 1;
				int C = 1;
				_expected = 4;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 4:
			{
				string board[] = {"XXX..XXX..XXX.",
				                  ".X..X....X...X",
				                  ".X..X....X...X",
				                  ".X..X....X...X",
				                  ".X...XXX..XXX.",
				                  "..............",
				                  "...XX...XXX...",
				                  "....X......X..",
				                  "....X....XXX..",
				                  "....X......X..",
				                  "...XXX..XXX..."};
				int R = 1;
				int C = 2;
				_expected = 7;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			/*case 5:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
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
