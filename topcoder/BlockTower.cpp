#line 2 "BlockTower.cpp"
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

vi H;
int memo[51][2];

int solve(bool prev, int idx) {
	if (idx == sz(H)) return 0;
	if (memo[idx][prev] != -1) return memo[idx][prev];

	if (H[idx] % 2 == 0 && prev) return (memo[idx][prev] = solve(prev, idx+1));

	if (H[idx] % 2 == 0) {
		return (memo[idx][prev] = H[idx] + solve(false, idx+1));
	}
	else {
		return (memo[idx][prev] = max(H[idx] + solve(true, idx+1), solve(false, idx+1)));
	}
}


class BlockTower {
	public:
	int getTallest(vector <int> blockHeights) {
		H = blockHeights;	
		fill(memo, -1);
		return solve(false, 0);
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
		cout << "Testing BlockTower (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352533799;
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
		BlockTower _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int blockHeights[] = {4,7};
				_expected = 11;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 1:
			{
				int blockHeights[] = {7,4};
				_expected = 7;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 2:
			{
				int blockHeights[] = {7};
				_expected = 7;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 3:
			{
				int blockHeights[] = {4};
				_expected = 4;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 4:
			{
				int blockHeights[] = {48,1,50,1,50,1,48};
				_expected = 196;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 5:
			{
				int blockHeights[] = {49,2,49,2,49};
				_expected = 147;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			case 6:
			{
				int blockHeights[] = {44,3,44,3,44,47,2,47,2,47,2};
				_expected = 273;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}
			/*case 7:
			{
				int blockHeights[] = ;
				_expected = ;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int blockHeights[] = ;
				_expected = ;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int blockHeights[] = ;
				_expected = ;
				_received = _obj.getTallest(vector <int>(blockHeights, blockHeights+sizeof(blockHeights)/sizeof(int))); break;
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
