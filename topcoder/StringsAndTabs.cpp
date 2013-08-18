#line 2 "StringsAndTabs.cpp"
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


class StringsAndTabs {
	public:
	vector <string> transformTab(vector <string> tab, vector <int> stringsA, vector <int> stringsB, int d) {
		
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
		cout << "Testing StringsAndTabs (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363233315;
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
		StringsAndTabs _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tab[] = {"-----------------",
				                "-------------0-1-",
				                "---------0-2-----",
				                "---0-2-3---------",
				                "-3---------------",
				                "-----------------"};
				int stringsA[] = {28,23,19,14,9,4};
				int stringsB[] = {9};
				int d = 0;
				string __expected[] = {"-3-5-7-8-A-C-E-F-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 1:
			{
				string tab[] = {"-4457754-20024422-4457754-20024200-"};
				int stringsA[] = {0};
				int stringsB[] = {28,23,19,14,9,4};
				int d = 12;
				string __expected[] = {"-----------------------------------", "-----------------------------------", "----00---------------00------------", "-223--32-0--02200-223--32-0--020---", "----------33---------------33---33-", "-----------------------------------" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 2:
			{
				string tab[] = {"-----------------------------------",
				                "-----------------------------------",
				                "----00---------------00------------",
				                "-223--32-0--02200-223--32-0--020---",
				                "----------33---------------33---33-",
				                "-----------------------------------"};
				int stringsA[] = {28,23,19,14,9,4};
				int stringsB[] = {33,28,24,31};
				int d = 12;
				string __expected[] = {"-----------------------------------", "-001--10-----00---001--10-----0----", "---------2002--22---------2002-200-", "----00---------------00------------" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 3:
			{
				string tab[] = {"-----0------2-2222--0-------0-",
				                "----0------2---222---5-----55-",
				                "---0------2-----22----9---999-",
				                "--0------2-------2-----E-EEEE-",
				                "-0------2---------------------",
				                "0------2----------------------"};
				int stringsA[] = {28,23,19,14,9,4};
				int stringsB[] = {33,28,28};
				int d = 12;
				string __expected[] = {"xxx-27-xx-049-999x--7777-777x-", "xxx----xx-------5x---------Cx-", "xxx3---xx0-----99x--------CCx-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 4:
			{
				string tab[] = {"012345---------",
				                "---------UVWXYZ"};
				int stringsA[] = {-2,2};
				int stringsB[] = {0};
				int d = 0;
				string __expected[] = {"xx0123---WXYZxx" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			case 5:
			{
				string tab[] = {"0220----02--",
				                "75--75----57",
				                "------B9B9B9",
				                "--242424----"};
				int stringsA[] = {33,28,24,31};
				int stringsB[] = {33,28,28};
				int d = 0;
				string __expected[] = {"222222222222", "------------", "555555555555" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}
			/*case 6:
			{
				string tab[] = ;
				int stringsA[] = ;
				int stringsB[] = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}*/
			/*case 7:
			{
				string tab[] = ;
				int stringsA[] = ;
				int stringsB[] = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
			}*/
			/*case 8:
			{
				string tab[] = ;
				int stringsA[] = ;
				int stringsB[] = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.transformTab(vector <string>(tab, tab+sizeof(tab)/sizeof(string)), vector <int>(stringsA, stringsA+sizeof(stringsA)/sizeof(int)), vector <int>(stringsB, stringsB+sizeof(stringsB)/sizeof(int)), d); break;
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
