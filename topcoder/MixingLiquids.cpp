#line 2 "MixingLiquids.cpp"
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


class MixingLiquids {
	public:
	double howMuch(vector <int> percent, vector <int> amount, int need) {
		
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
		cout << "Testing MixingLiquids (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361385397;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MixingLiquids _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int percent[] = {0, 100};
				int amount[] = {20, 30};
				int need = 50;
				_expected = 40.0;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}
			case 1:
			{
				int percent[] = {0, 100};
				int amount[] = {20, 30};
				int need = 60;
				_expected = 50.0;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}
			case 2:
			{
				int percent[] = {90, 70, 80};
				int amount[] = {10, 10, 10};
				int need = 50;
				_expected = 0.0;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}
			case 3:
			{
				int percent[] = {30, 80, 60};
				int amount[] = {40, 10, 15};
				int need = 57;
				_expected = 35.18518518518519;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}
			case 4:
			{
				int percent[] = {50,50,50};
				int amount[] = {395,971,964};
				int need = 50;
				_expected = 2330.0;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}
			/*case 5:
			{
				int percent[] = ;
				int amount[] = ;
				int need = ;
				_expected = ;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}*/
			/*case 6:
			{
				int percent[] = ;
				int amount[] = ;
				int need = ;
				_expected = ;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
			}*/
			/*case 7:
			{
				int percent[] = ;
				int amount[] = ;
				int need = ;
				_expected = ;
				_received = _obj.howMuch(vector <int>(percent, percent+sizeof(percent)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int)), need); break;
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
