#line 2 "SpiralWalking.cpp"
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


enum {RIGHT, DOWN, LEFT, UP};
bool seen[55][55];
int points = 0, n, m;
vector<string> lm;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int last = 0;

void visit(int x, int y, int dn) {
	if (seen[x][y]) return;
	last = lm[x][y] - '0';
	points += last;
	seen[x][y] = 1;
	if (valid(x + dx[dn], y + dy[dn]) && !seen[x+dx[dn]][y+dy[dn]]) visit(x + dx[dn], y + dy[dn], dn);
	else {
		points -= (lm[x][y] - '0');
		dn = (dn+1) % 4;
		visit(x+dx[dn], y+dy[dn], dn);
	}
}


class SpiralWalking {
	public:
	int totalPoints(vector <string> levelMap) {
		lm = levelMap;
		n = sz(levelMap);
		m = sz(levelMap[0]);
		visit(0, 0, RIGHT);
		return points + last;
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
		cout << "Testing SpiralWalking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362752248;
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
		SpiralWalking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string levelMap[] = {"111",
				                     "111",
				                     "111"};
				_expected = 5;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			case 1:
			{
				string levelMap[] = {"101",
				                     "110"};
				_expected = 3;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			case 2:
			{
				string levelMap[] = {"00",
				                     "10"};
				_expected = 1;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			case 3:
			{
				string levelMap[] = {"86850",
				                     "76439",
				                     "15863",
				                     "24568",
				                     "45679",
				                     "71452",
				                     "05483"};
				_expected = 142;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}
			/*case 4:
			{
				string levelMap[] = ;
				_expected = ;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string levelMap[] = ;
				_expected = ;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string levelMap[] = ;
				_expected = ;
				_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
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
