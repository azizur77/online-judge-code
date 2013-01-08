#line 2 "TheFansAndMeetingsDivTwo.cpp"
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


class TheFansAndMeetingsDivTwo {
	public:
	double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB) {
		double probs[2][100];
		fill(probs, 0);
		int n = minJ.size();
		for(int i=0; i < n; i++) {
			int a = maxJ[i] - minJ[i] + 1;
			for(int j=minJ[i]; j <= maxJ[i]; j++) {
				probs[0][j] += 1.0 / ((double) a*n);
			}

			int b = maxB[i] - minB[i] + 1;
			for(int j=minB[i]; j <= maxB[i]; j++) {
				probs[1][j] += 1.0 / ((double) b*n);
			}
		}
		double res = 0;
		for(int i=0; i <= 100; i++)
			res += probs[0][i] * probs[1][i];
		return res;
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
		cout << "Testing TheFansAndMeetingsDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1353425947;
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
		TheFansAndMeetingsDivTwo _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int minJ[] = {1};
				int maxJ[] = {3};
				int minB[] = {1};
				int maxB[] = {1};
				_expected = 0.3333333333333333;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
			}
			case 1:
			{
				int minJ[] = {5, 7, 7, 1, 6, 1, 1};
				int maxJ[] = {8, 9, 7, 3, 9, 5, 3};
				int minB[] = {9, 12, 10, 14, 50, 9, 10};
				int maxB[] = {9, 13, 50, 15, 50, 12, 11};
				_expected = 0.014880952380952378;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
			}
			case 2:
			{
				int minJ[] = {44};
				int maxJ[] = {47};
				int minB[] = {4};
				int maxB[] = {7};
				_expected = 0.0;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
			}
			case 3:
			{
				int minJ[] = {1, 6, 3, 1, 4, 3, 5, 1};
				int maxJ[] = {7, 8, 5, 7, 9, 7, 9, 3};
				int minB[] = {5, 1, 5, 3, 1, 2, 4, 1};
				int maxB[] = {9, 2, 7, 9, 4, 5, 4, 9};
				_expected = 0.11562305130385474;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
			}
			/*case 4:
			{
				int minJ[] = ;
				int maxJ[] = ;
				int minB[] = ;
				int maxB[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int minJ[] = ;
				int maxJ[] = ;
				int minB[] = ;
				int maxB[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int minJ[] = ;
				int maxJ[] = ;
				int minB[] = ;
				int maxB[] = ;
				_expected = ;
				_received = _obj.find(vector <int>(minJ, minJ+sizeof(minJ)/sizeof(int)), vector <int>(maxJ, maxJ+sizeof(maxJ)/sizeof(int)), vector <int>(minB, minB+sizeof(minB)/sizeof(int)), vector <int>(maxB, maxB+sizeof(maxB)/sizeof(int))); break;
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
