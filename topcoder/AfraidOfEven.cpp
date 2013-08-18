#line 2 "AfraidOfEven.cpp"
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


class AfraidOfEven {
	public:
	vector <int> restoreProgression(vector <int> seq) {
		int n = sz(seq);
		// check diffs 
		int diff = seq[1] - seq[0];
		int flag = 1;
		for(int i=1; i < sz(seq); i++)
			if (seq[i] - seq[i-1] != diff) {
				flag = 0;
				break;
			}
		if (flag) return seq;

		// check odd terms
		int odd_flag = 1, prev = seq[2] - seq[0];

		for(int i=0; i < sz(seq); i+=2) {
			int curr = (i == 0) ? prev : (seq[i] - seq[i-2]);
			if (seq[i] % 2 == 0 || curr != prev) {
				odd_flag = 0;
				break;
			}
		}
		
		int even_flag = 1;
		prev = seq[3] - seq[1];


		for(int i=1; i < sz(seq); i+=2) {
			int curr = (i == 0) ? prev : (seq[i] - seq[i-2]);
			if (seq[i] % 2 == 0 || curr != prev) {
				even_flag = 0;
				break;
			}
		}


		int first;
		if (odd_flag) {
			first = seq[0];
			diff = (seq[2] - seq[0]) / 2;
		} else {
			diff = (seq[3] - seq[1]) / 2;
			first = seq[1] - diff;
		}

		if (odd_flag && ((n-1) * diff + first < 0)) {
			diff = (seq[3] - seq[1]) / 2;
			first = seq[1] - diff;
		} else if (odd_flag && even_flag) {
			diff = (seq[3] - seq[1]) / 2;
			first = seq[1] - diff;
		}

		seq[0] = first;
		for(int i=1; i < sz(seq); i++)
			seq[i] = seq[i-1] + diff;
		return seq;
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
		cout << "Testing AfraidOfEven (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1374930618;
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
		AfraidOfEven _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seq[] = {1, 1, 3, 1, 5};
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int seq[] = {9, 7, 5, 3, 1};
				int __expected[] = {9, 7, 5, 3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int seq[] = {999, 999, 999, 999};
				int __expected[] = {999, 999, 999, 999 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int seq[] = {7, 47, 5, 113, 73, 179, 53};
				int __expected[] = {14, 47, 80, 113, 146, 179, 212 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int seq[] = {749, 999, 125, 1};
				int __expected[] = {1498, 999, 500, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 5:
			{
				int seq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int seq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int seq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
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
