#line 2 "StandInLine.cpp"
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


class StandInLine {
	public:
	vector <int> reconstruct(vector <int> left) {
		int n = sz(left);
		vi series(n, 0);
		for(int i=0; i < n; i++) series[i] = i+1;
		do {
			bool flag = true;
			for(int i=0; i < n; i++) {
				int ctr = 0;
				for(int j=0; j < i; j++) 
					if (series[j] > series[i]) ctr++;
				if (ctr != left[series[i] - 1]) {
					flag = false;
					break;
				}
			}
			if (flag) break;
		} while(next_permutation(all(series)));
		return series;
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
		cout << "Testing StandInLine (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361371076;
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
		StandInLine _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int left[] = {2, 1, 1, 0 };
				int __expected[] = {4, 2, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
			}
			case 1:
			{
				int left[] = {0, 0, 0, 0, 0 };
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
			}
			case 2:
			{
				int left[] = {5, 4, 3, 2, 1, 0 };
				int __expected[] = {6, 5, 4, 3, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
			}
			case 3:
			{
				int left[] = {6, 1, 1, 1, 2, 0, 0 };
				int __expected[] = {6, 2, 3, 4, 7, 5, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
			}
			/*case 4:
			{
				int left[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int left[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int left[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(vector <int>(left, left+sizeof(left)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
