#line 2 "UndoHistory.cpp"
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

inline int match(string a, string b) {
	int m = 0;
	for(int i=0; i < sz(a) && i < sz(b); i++) {
		if (a[i] == b[i])
			m++;
		else
			return m;
	}
	return m;
}

class UndoHistory {
	public:
	int minPresses(vector <string> lines) {
		vector<string> undo;
		undo.push_back("");
		string buffer = "";
		int cost = sz(lines);

		for(int i=0; i < sz(lines); i++) {
			string word = lines[i];
			int best = match(word, buffer), idx = -1;
			int bufmatch = best;
				for(int j=0; j < sz(undo); j++) {
					int k = match(word, undo[j]);
					if (k > best) {
						best = k;
						idx = j;
					}
				}
			if (sz(buffer) == bufmatch && best == bufmatch+1)
				cost += 1;
			else if (idx > 0 || sz(buffer) != best)
				 cost += 2;
			
			for(int x = best+1; x <= sz(word); x++) {
				string buf2 = word.substr(0, x);
				undo.push_back(buf2);
				cost++;
			}
			buffer = word;
		}
		// for(int i=0; i < sz(undo); i++)
			// cout << undo[i] << endl;
		return cost;
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
		cout << "Testing UndoHistory (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1368893408;
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
		UndoHistory _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string lines[] = {"tomorrow", "topcoder"};
				_expected = 18;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 1:
			{
				string lines[] = {"a","b"};
				_expected = 6;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 2:
			{
				string lines[] = {"a", "ab", "abac", "abacus" };
				_expected = 10;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 3:
			{
				string lines[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
				_expected = 39;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 4:
			{
				string lines[] = {"ba","a","a","b","ba"};
				_expected = 13;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			/*case 5:
			{
				string lines[] = ;
				_expected = ;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string lines[] = ;
				_expected = ;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string lines[] = ;
				_expected = ;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
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
