#line 2 "ValueHistogram.cpp"
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


class ValueHistogram {
	public:
	vector <string> build(vector <int> values) {
		int counts[10] = {0};
		for(int i=0; i < sz(values); i++) 
			counts[values[i]]++;
		int H = *max_element(counts, counts+10) + 1;
		vector<string> hist(H, "..........");
		for(int i=0; i < 10; i++)
			for(int j=0; j < counts[i]; j++)
				hist[H-1 - j][i] = 'X';
		return hist;		
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
		cout << "Testing ValueHistogram (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356019806;
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
		ValueHistogram _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int values[] = {2, 3, 5, 5, 5, 2, 0, 8};
				string __expected[] = {"..........", ".....X....", "..X..X....", "X.XX.X..X." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int values[] = {9, 9, 9, 9};
				string __expected[] = {"..........", ".........X", ".........X", ".........X", ".........X" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int values[] = {6, 4, 0, 0, 3, 9, 8, 8};
				string __expected[] = {"..........", "X.......X.", "X..XX.X.XX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
				string __expected[] = {"..........", "XXXXXXXXXX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 4:
			{
				int values[] = {6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3};
				string __expected[] = {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 5:
			{
				int values[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int values[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int values[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.build(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
