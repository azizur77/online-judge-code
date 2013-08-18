#line 2 "CollectingUsualPostmarks.cpp"
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


class CollectingUsualPostmarks {
	public:
	int numberOfPostmarks(vector <int> prices, vector <int> have) {
		int money = 0;
		for(int i=0; i < sz(have); i++) money += prices[have[i]];
		sort(all(prices));
		int cnt = 0;
		while (cnt < sz(prices)) {
			if (money - prices[cnt] >= 0) {
				cnt++;
				money -= prices[cnt-1];
			}
			else break;
		}
		return cnt;
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
		cout << "Testing CollectingUsualPostmarks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1364190087;
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
		CollectingUsualPostmarks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int prices[] = {13,10,14,20};
				int have[] = {3,0,2,1};
				_expected = 4;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
			}
			case 1:
			{
				int prices[] = {7,5,9,7};
				int have[] = {};
				_expected = 0;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
			}
			case 2:
			{
				int prices[] = {4,13,9,1,5};
				int have[] = {1,3,2};
				_expected = 4;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
			}
			case 3:
			{
				int prices[] = {16,32,13,2,17,10,8,8,20,17};
				int have[] = {7,0,4,1,6,8};
				_expected = 8;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
			}
			/*case 4:
			{
				int prices[] = ;
				int have[] = ;
				_expected = ;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int prices[] = ;
				int have[] = ;
				_expected = ;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int prices[] = ;
				int have[] = ;
				_expected = ;
				_received = _obj.numberOfPostmarks(vector <int>(prices, prices+sizeof(prices)/sizeof(int)), vector <int>(have, have+sizeof(have)/sizeof(int))); break;
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
