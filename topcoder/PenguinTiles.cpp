#line 2 "PenguinTiles.cpp"
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


class PenguinTiles {
	public:
	int minMoves(vector <string> tiles) {
		int n = sz(tiles);
		int m = sz(tiles[0]);
		for(int i=0; i < n; i++)
			for(int j=0; j < m; j++)
				if (tiles[i][j] == '.') {
					int ctr = 0;
					if (i != n-1) ctr++;
					if (j != m-1) ctr++;
					return ctr;
				}
		return 2;
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
		cout << "Testing PenguinTiles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358768263;
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
		PenguinTiles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tiles[] = {"PP",
				                  "P."};
				_expected = 0;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 1:
			{
				string tiles[] = {"PPPPPPPP",
				                  ".PPPPPPP"};
				_expected = 1;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 2:
			{
				string tiles[] = {"PPP",
				                  "P.P",
				                  "PPP"};
				_expected = 2;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 3:
			{
				string tiles[] = {"P.",
				                  "PP",
				                  "PP",
				                  "PP"};
				_expected = 1;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 4:
			{
				string tiles[] = {".PPP",
				                  "PPPP",
				                  "PPPP",
				                  "PPPP"};
				_expected = 2;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			/*case 5:
			{
				string tiles[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string tiles[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string tiles[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
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
