#line 2 "RevealTriangle.cpp"
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


class RevealTriangle {
	public:
	vector <string> calcTriangle(vector <string> questionMarkTriangle) {
		int n = questionMarkTriangle.size();

		for(int times=0; times < n*n+n; times++)
		for(int i=n-2; i >= 0; i--) 
			for(int j=0; j < questionMarkTriangle[i].size(); j++) 
				if (questionMarkTriangle[i][j] == '?') {
					// Try left
					if (j != 0 && questionMarkTriangle[i][j-1] != '?') {
						int target = questionMarkTriangle[i+1][j-1] - '0';
						int left = questionMarkTriangle[i][j-1] - '0';
						for(int k=0; k < 10; k++) 
							if ((left + k) % 10 == target) {
								questionMarkTriangle[i][j] = char('0' + k);
								break;
							}
					} else if (j != (sz(questionMarkTriangle[i]) - 1) && questionMarkTriangle[i][j+1] != '?') {
						int target = questionMarkTriangle[i+1][j] - '0';
						int right = questionMarkTriangle[i][j+1] - '0';
						for(int k=0; k < 10; k++) 
							if ((right + k) % 10 == target) {
								questionMarkTriangle[i][j] = char('0' + k);
								break;
							}
					}
				}

		return questionMarkTriangle;
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
		cout << "Testing RevealTriangle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362664511;
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
		RevealTriangle _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string questionMarkTriangle[] = {"4??", 
				                                 "?2", 
				                                 "1"};
				string __expected[] = {"457", "92", "1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
			}
			case 1:
			{
				string questionMarkTriangle[] = {"1"};
				string __expected[] = {"1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
			}
			case 2:
			{
				string questionMarkTriangle[] = {"???2", "??2", "?2", "2"};
				string __expected[] = {"0002", "002", "02", "2" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
			}
			case 3:
			{
				string questionMarkTriangle[] = {"??5?", "??9", "?4", "6"};
				string __expected[] = {"7054", "759", "24", "6" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
			}
			/*case 4:
			{
				string questionMarkTriangle[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string questionMarkTriangle[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string questionMarkTriangle[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
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
