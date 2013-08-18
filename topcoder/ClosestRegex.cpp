#line 2 "ClosestRegex.cpp"
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
typedef long long ll;
typedef pair<int, string> IS;

int N, M;
string T, R;
IS memo[55][55];

IS solve(int x, int y) {
	if (x == N && y == M) return IS(0, "");
	if (memo[x][y].X != -1) return memo[x][y];
	memo[x][y] = IS(INF, "");

	if (y < M-1 && R[y+1] == '*') {
		memo[x][y] = min(memo[x][y], solve(x, y+2));

		if (x < N) {
			IS temp = solve(x+1, y);
			temp.X += (T[x] == R[y]) ? 0 : 1;
			temp.Y = string(1, R[y]) + temp.Y;
			memo[x][y] = min(memo[x][y], temp);
		}
	} else if (x < N && y < M) {
			IS temp = solve(x+1, y+1);
			temp.X += (T[x] == R[y]) ? 0 : 1;
			temp.Y = string(1, R[y]) + temp.Y;
			memo[x][y] = min(memo[x][y], temp);
	} 
	return memo[x][y];
}


class ClosestRegex {
	public:
	string closestString(string text, string regex) {
		N = sz(text); M = sz(regex); T = text; R = regex;
		for(int i=0; i < 55; i++) for(int j=0; j < 55; j++) memo[i][j].X = -1;
		IS ans = solve(0, 0);
		if (ans.X >= INF) return "";
		return ans.Y;
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
		cout << "Testing ClosestRegex (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362977258;
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
		ClosestRegex _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "abc";
				string regex = "ab*cd";
				_expected = "acd";
				_received = _obj.closestString(text, regex); break;
			}
			case 1:
			{
				string text = "topcoder";
				string regex = "t*px*coa*de*";
				_expected = "ttpcodee";
				_received = _obj.closestString(text, regex); break;
			}
			case 2:
			{
				string text = "cmu";
				string regex = "c*m*fm*u*";
				_expected = "cfu";
				_received = _obj.closestString(text, regex); break;
			}
			case 3:
			{
				string text = "aaaaacccc";
				string regex = "a*abc*";
				_expected = "aaaaabccc";
				_received = _obj.closestString(text, regex); break;
			}
			case 4:
			{
				string text = "short";
				string regex = "lo*ts*of*let*ter*s";
				_expected = "";
				_received = _obj.closestString(text, regex); break;
			}
			/*case 5:
			{
				string text = ;
				string regex = ;
				_expected = ;
				_received = _obj.closestString(text, regex); break;
			}*/
			/*case 6:
			{
				string text = ;
				string regex = ;
				_expected = ;
				_received = _obj.closestString(text, regex); break;
			}*/
			/*case 7:
			{
				string text = ;
				string regex = ;
				_expected = ;
				_received = _obj.closestString(text, regex); break;
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
