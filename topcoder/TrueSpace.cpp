#line 2 "TrueSpace.cpp"
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


class TrueSpace {
	public:
	long long calculateSpace(vector <int> sizes, int clusterSize) {
		ll ans = 0;
		for(int i=0; i < sz(sizes); i++)
			ans += ll (ceil(1.0 * sizes[i] / clusterSize)) * ll(clusterSize);
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
		cout << "Testing TrueSpace (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363231512;
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
		TrueSpace _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sizes[] = {600};
				int clusterSize = 512;
				_expected = 1024LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}
			case 1:
			{
				int sizes[] = {16,32,128,128,0};
				int clusterSize = 32768;
				_expected = 131072LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}
			case 2:
			{
				int sizes[] = {4096, 33792, 76800};
				int clusterSize = 1024;
				_expected = 114688LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}
			case 3:
			{
				int sizes[] = {1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000, 1000000000, 1000000000,
				               1000000000, 1000000000};
				int clusterSize = 1048576;
				_expected = 50017075200LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}
			case 4:
			{
				int sizes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				int clusterSize = 8;
				_expected = 0LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}
			/*case 5:
			{
				int sizes[] = ;
				int clusterSize = ;
				_expected = LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}*/
			/*case 6:
			{
				int sizes[] = ;
				int clusterSize = ;
				_expected = LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
			}*/
			/*case 7:
			{
				int sizes[] = ;
				int clusterSize = ;
				_expected = LL;
				_received = _obj.calculateSpace(vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int)), clusterSize); break;
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
