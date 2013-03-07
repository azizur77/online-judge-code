#line 2 "RobotHerb.cpp"
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


ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, -1, 0, 1};


class RobotHerb {
	public:
	long long getdist(ll T, vector <int> a) {
		vector<ll> X, Y, dns;
		bool seen[4] = {false};
		ll idx = 3;
		while(1) {
			if (seen[idx]) break;
			seen[idx] = true; 
			dns.push_back(idx);

			ll x=0, y=0;
			
			for(int i=0; i < sz(a); i++) {
				x = x + (dx[idx] * a[i]);
				y = y + (dy[idx] * a[i]);
				idx = (idx+a[i]) % 4;
			}
			X.push_back(x);
			Y.push_back(y);
		}

		ll X1=0, Y1=0;

		int pos = 0;
		for(int i=0; i < sz(dns); i++) {
			if (dns[i] == idx) {
				pos = i;
				break;
			}
		}

		for(int i=0; i < pos; i++) {
			X1 += X[i];
			Y1 += Y[i];
		}

		int cycle = sz(dns) - pos;

		for(int i=pos; i < sz(dns); i++) {
			X1 += (T / cycle) * X[i];
			Y1 += (T / cycle) * Y[i];
		}

		for(int i=pos; i < (pos + ((T-pos)%cycle)); i++) {
			X1 += X[i];
			Y1 += Y[i];
		}

		ll res = abs(X1) + abs(Y1);
		return res;
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
		cout << "Testing RobotHerb (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1360757413;
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
		RobotHerb _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int T = 1;
				int a[] = {1,2,3};
				_expected = 2LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int T = 100;
				int a[] = {1};
				_expected = 0LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int T = 5;
				int a[] = {1,1,2};
				_expected = 10LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int T = 1000000000;
				int a[] = {100};
				_expected = 100000000000LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int T = 570;
				int a[] = {2013,2,13,314,271,1414,1732};
				_expected = 4112LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
