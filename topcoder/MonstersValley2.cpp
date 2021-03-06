#line 2 "MonstersValley2.cpp"
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

vi _dread, _price;

int solve(int idx, ll dreadsum) {
	if (idx == sz(_dread)) return 0;
	if (dreadsum < _dread[idx]) return _price[idx] + solve(idx+1, (ll) dreadsum+_dread[idx]);
	return min(solve(idx+1, dreadsum), _price[idx] + solve(idx+1, (ll) dreadsum+_dread[idx]));
}

class MonstersValley2 {
	public:
	int minimumPrice(vector <int> dread, vector <int> price) {
		_dread = dread;
		_price = price;
		return solve(0, 0);
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
		cout << "Testing MonstersValley2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356020143;
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
		MonstersValley2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dread[] = {8e8, 5e8, 10e8};
				int price[] = {1, 1, 2};
				_expected = 2;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 1:
			{
				int dread[] = {1, 2, 4, 1000000000};
				int price[] = {1, 1, 1, 2};
				_expected = 5;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 2:
			{
				int dread[] = {200, 107, 105, 206, 307, 400};
				int price[] = {1, 2, 1, 1, 1, 2};
				_expected = 2;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 3:
			{
				int dread[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
				int price[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
				_expected = 5;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			/*case 4:
			{
				int dread[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int dread[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int dread[] = ;
				int price[] = ;
				_expected = ;
				_received = _obj.minimumPrice(vector <int>(dread, dread+sizeof(dread)/sizeof(int)), vector <int>(price, price+sizeof(price)/sizeof(int))); break;
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
