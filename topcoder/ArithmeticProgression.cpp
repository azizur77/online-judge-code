#line 2 "ArithmeticProgression.cpp"
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


class ArithmeticProgression {
	public:
	double minCommonDifference(int a0, vector <int> seq) {
		int prev = a0;
		vi diffs;
		for(int i=0; i < sz(seq); i++) {
			if (seq[i] - prev < 0) return -1;
			diffs.push_back(seq[i] - prev);
			prev = seq[i];
		}
		if (sz(diffs) == 0) return 0.0;
		int maX = *max_element(all(diffs));
		int miN = *min_element(all(diffs));
		if (maX - miN >= 2) return -1;
		double sum = 0.0;
		for (int i = 0; i < sz(diffs); ++i) {
			sum += diffs[i];
		}
		sum /= sz(diffs);
		return sum;
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
		cout << "Testing ArithmeticProgression (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363350935;
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
		ArithmeticProgression _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a0 = 0;
				int seq[] = {6, 13, 20, 27};
				_expected = 6.75;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int a0 = 1;
				int seq[] = {2, 3, 4, 5, 6};
				_expected = 1.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int a0 = 3;
				int seq[] = {};
				_expected = 0.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int a0 = 3;
				int seq[] = {3, 3, 3, 3, 4};
				_expected = 0.2;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int a0 = 1;
				int seq[] = {-3};
				_expected = -1.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 5:
			{
				int a0 = 0;
				int seq[] = {6, 14};
				_expected = -1.0;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a0 = ;
				int seq[] = ;
				_expected = ;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a0 = ;
				int seq[] = ;
				_expected = ;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a0 = ;
				int seq[] = ;
				_expected = ;
				_received = _obj.minCommonDifference(a0, vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
