#line 2 "CurvyonRails.cpp"
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


class CurvyonRails {
	public:
	int getmin(vector <string> field) {
		
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
		cout << "Testing CurvyonRails (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1360761534;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CurvyonRails _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {".."
				                 ,".."};
				_expected = 0;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 1:
			{
				string field[] = {"wCCww"
				                 ,"wCC.."
				                 ,"..w.."
				                 ,"....w"
				                 ,"ww..w"};
				_expected = 0;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 2:
			{
				string field[] = {"C.w"
				                 ,"..."
				                 ,".C."};
				_expected = 1;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 3:
			{
				string field[] = {"."};
				_expected = -1;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 4:
			{
				string field[] = {"w"};
				_expected = 0;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 5:
			{
				string field[] = {"CC..CCCw.CwC..CC.w.C",
				                  "C.CCCwCCC.w.w..C.w..",
				                  "wwww...CC.wC.Cw.CC..",
				                  "CC..CC.w..w.C..CCCC.",
				                  "CC.CCC..CwwCCC.wCC..",
				                  "w.C..wwCC.CC.wwwCC..",
				                  ".CC.CC..CCC..CC.CC.C",
				                  "Cw....C.C.CCC...CC..",
				                  "CC.C..Cww.C.CwwwC..w",
				                  "wCCww..C...CCCCCCC.w",
				                  "C.CCw.CC.ww...C.CCww",
				                  "C.C.C.CCwCC..wCCw.Cw",
				                  "CCC.C...w..C.wC.wCCw",
				                  "CC.C..C..CCC.CC.C...",
				                  "C.ww...CCC..CC...CCC",
				                  "...CCC.CwwwC..www.C.",
				                  "wwCCCCC.w.C.C...wCwC",
				                  "CCwC.CwCCC.C.w.Cw...",
				                  "C.w.wC.CC.CCC.C.w.Cw",
				                  "CCw.CCC..C..CC.CwCCw",
				                  "C.wwwww.CwwCCwwwwwww"};
				_expected = 9;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			/*case 6:
			{
				string field[] = ;
				_expected = ;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string field[] = ;
				_expected = ;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string field[] = ;
				_expected = ;
				_received = _obj.getmin(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
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
