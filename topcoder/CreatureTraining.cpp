#line 2 "CreatureTraining.cpp"
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


ll memo[105][105][105];
vi _count, _power;
int N;

ll solve(int level, int upgradesLeft, int additional) {
	if (memo[level][upgradesLeft][additional] >= 0) 
		return memo[level][upgradesLeft][additional];

	if (level == N) return 0;
	int maxUpgrades = min(_count[level] + additional, upgradesLeft);
	ll ret = 0;
	if (level < N-1) {
		FOR(i, 0, maxUpgrades+1) {
			ll thisLevel = (ll) (_count[level] + additional - i) * _power[level];
			ll nextLevels = solve(level+1, upgradesLeft-i, i);
			ret = max(ret, thisLevel + nextLevels);
		}
	}
	else {
		ret = (ll) _power[level] * (_count[level] + additional);
	}
	return (memo[level][upgradesLeft][additional] = ret);
}


class CreatureTraining {
	public:
	long long maximumPower(vector <int> count, vector <int> power, int D) {
		fill(memo, -1);
		N = sz(power);
		_count = count;
		_power = power;
		return solve(0, D, 0);
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
		cout << "Testing CreatureTraining (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352123987;
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
		CreatureTraining _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int count[] = {1, 2, 3, 4, 5};
				int power[] = {1, 2, 3, 4, 5};
				int D = 10;
				_expected = 65LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}
			case 1:
			{
				int count[] = {1, 2, 3, 4, 5};
				int power[] = {1, 4, 9, 16, 25};
				int D = 10;
				_expected = 309LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}
			case 2:
			{
				int count[] = {1000, 0, 0, 0, 0};
				int power[] = {0, 100, 10, 1000, 0};
				int D = 8;
				_expected = 2200LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}
			case 3:
			{
				int count[] = {1, 2, 3, 4, 5};
				int power[] = {5, 4, 3, 2, 1};
				int D = 50;
				_expected = 35LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}
			case 4:
			{
				int count[] = {0, 5, 0, 0, 5, 0};
				int power[] = {13, 20, 21, 30, 32, 36};
				int D = 12;
				_expected = 318LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}
			case 5:
			{
				int count[] = {0, 2, 1, 0, 0, 1, 2};
				int power[] = {25, 292, 328, 391, 618, 771, 952};
				int D = 11;
				_expected = 5088LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}
			/*case 6:
			{
				int count[] = ;
				int power[] = ;
				int D = ;
				_expected = LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}*/
			/*case 7:
			{
				int count[] = ;
				int power[] = ;
				int D = ;
				_expected = LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
			}*/
			/*case 8:
			{
				int count[] = ;
				int power[] = ;
				int D = ;
				_expected = LL;
				_received = _obj.maximumPower(vector <int>(count, count+sizeof(count)/sizeof(int)), vector <int>(power, power+sizeof(power)/sizeof(int)), D); break;
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
