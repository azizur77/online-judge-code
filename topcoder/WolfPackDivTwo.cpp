#line 2 "WolfPackDivTwo.cpp"
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
using std::queue;
using std::vector;
using std::max;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef long long ll;
#define M 52
#define MOD 1000000007

ll dp[105][105][52];
ll tmp[105][105][52];
bool seen[105][105][52];

struct node {
	ll x, y, m, fx, fy;
	node(ll a, ll b, ll c, ll d, ll e) : x(a), y(b), m(c), fx(d), fy(e) {}
};

class WolfPackDivTwo {
	public:
	int calc(vector <int> x, vector <int> y, int m) {
		fill(dp, 0LL);

		for(int i=0; i < sz(x); i++) {
			queue<node> Q;
			fill(seen, 0);
			fill(tmp, 0LL);
			Q.push(node(x[i], y[i], 0ll, x[i], y[i]));
			tmp [x[i] + M] [y[i] + M] [0] = 1ll;

			while(Q.size() > 0) {
				node curr = Q.front();
				Q.pop();
				tmp[curr.x + M][curr.y + M][curr.m] = (tmp[curr.x + M][curr.y + M][curr.m] + 
						tmp[curr.fx + M][curr.fy + M][curr.m-1]) % MOD;
				if (seen[curr.x + M][curr.y + M][curr.m]) continue;
				seen[curr.x + M][curr.y + M][curr.m] = 1;

				if (curr.m == m) {
					continue;
				}

				Q.push(node(curr.x + 1, curr.y, curr.m+1, curr.x, curr.y));
				Q.push(node(curr.x - 1, curr.y, curr.m+1, curr.x, curr.y));
				Q.push(node(curr.x , curr.y+1, curr.m+1, curr.x, curr.y));
				Q.push(node(curr.x , curr.y-1, curr.m+1, curr.x, curr.y));
			}
			for(int j=0; j  < 105; j++)
				for(int k=0; k < 105; k++)
					dp[j][k][i] = tmp[j][k][m];
		}



		ll ans = 0; 		
		for(int i=0; i < 105; i++)
			for(int j=0; j < 105; j++) {
				ll prod = 1;
				for(int k=0; k < sz(x); k++) {
					prod = (prod * dp[i][j][k]) % MOD;
				}
				ans = (ans + prod) % MOD;
			}
		return ans;
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
		cout << "Testing WolfPackDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363310877;
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
		WolfPackDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {3,5};
				int y[] = {0,0};
				int m = 1;
				_expected = 1;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}
			case 1:
			{
				int x[] = {0,1};
				int y[] = {0,0};
				int m = 1;
				_expected = 0;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}
			case 2:
			{
				int x[] = {0,2,4};
				int y[] = {0,0,0};
				int m = 2;
				_expected = 4;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}
			case 3:
			{
				int x[] = {7,8};
				int y[] = {8,7};
				int m = 1;
				_expected = 2;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}
			case 4:
			{
				int x[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8};
				int y[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18};
				int m = 12;
				_expected = 0;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}
			case 5:
			{
				int x[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8};
				int y[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18};
				int m = 31;
				_expected = 573748580;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int m = ;
				_expected = ;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int m = ;
				_expected = ;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				int m = ;
				_expected = ;
				_received = _obj.calc(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), m); break;
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
