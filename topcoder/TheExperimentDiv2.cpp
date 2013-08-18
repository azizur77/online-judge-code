#line 2 "TheExperimentDiv2.cpp"
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


class TheExperimentDiv2 {
	public:
	vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
		vector<int> sponges(sz(leftEnd), 0);
		for(int i=0; i < sz(leftEnd); i++) {
			for(int j=leftEnd[i]; j < leftEnd[i] + L; j++) {
				sponges[i] += intensity[j];
				intensity[j] = 0;
			}
		}	
		return sponges;
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
		cout << "Testing TheExperimentDiv2 (256.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365729009;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheExperimentDiv2 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int intensity[] = {3, 4, 1, 1, 5, 6};
				int L = 3;
				int leftEnd[] = {3, 1, 0};
				int __expected[] = {12, 5, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
			}
			case 1:
			{
				int intensity[] = {5, 5};
				int L = 2;
				int leftEnd[] = {0, 0};
				int __expected[] = {10, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
			}
			case 2:
			{
				int intensity[] = {92, 11, 1000, 14, 3};
				int L = 2;
				int leftEnd[] = {0, 3};
				int __expected[] = {103, 17 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
			}
			case 3:
			{
				int intensity[] = {2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13};
				int L = 4;
				int leftEnd[] = {1, 7, 4, 5, 8, 0};
				int __expected[] = {39, 14, 110, 0, 13, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
			}
			/*case 4:
			{
				int intensity[] = ;
				int L = ;
				int leftEnd[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int intensity[] = ;
				int L = ;
				int leftEnd[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int intensity[] = ;
				int L = ;
				int leftEnd[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineHumidity(vector <int>(intensity, intensity+sizeof(intensity)/sizeof(int)), L, vector <int>(leftEnd, leftEnd+sizeof(leftEnd)/sizeof(int))); break;
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
