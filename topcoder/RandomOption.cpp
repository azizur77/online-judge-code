#line 2 "RandomOption.cpp"
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

int adj[20][20] = {0}, N;

double search() {
	assert(N < 20);
	double nways = 0;
	for(int i=0; i < N; i++) {
		bool seen[20] = {0};
		stack <int> S;
		S.push(i);
		while (sz(S)) {
			int curr = S.top();
			assert(curr < 20);
			S.pop();
			if (seen[curr]) continue;
			seen[curr] = 1;
			bool flag = true;
			for(int j=0; j < N; j++) {
				if (adj[curr][j] && !seen[j]) {
					flag = false;	
					S.push(j);
				}
			}
			if (flag) nways++;
		}
	}
	return nways;
}

double factorial(int n) {
	double fac = 1.0;
	for(int i=2; i <= n; i++) fac *= i;
	return fac;
}

class RandomOption {
	public:
	double getProbability(int keyCount, vector <int> badLane1, vector <int> badLane2) {
		N = keyCount;
		REP(i, N) {
			adj[badLane1[i]][badLane2[i]] = adj[badLane2[i]][badLane1[i]] = 1;
		}
		double res = search() / (factorial(N));
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
		cout << "Testing RandomOption (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1354328215;
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
		RandomOption _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int keyCount = 5;
				int badLane1[] = {0};
				int badLane2[] = {3};
				_expected = 0.6;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}
			case 1:
			{
				int keyCount = 5;
				int badLane1[] = {0, 1, 2};
				int badLane2[] = {1, 2, 0};
				_expected = 0.1;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}
			case 2:
			{
				int keyCount = 5;
				int badLane1[] = {2, 2, 2, 2};
				int badLane2[] = {0, 1, 3, 4};
				_expected = 0.0;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}
			case 3:
			{
				int keyCount = 7;
				int badLane1[] = {0, 1, 2};
				int badLane2[] = {6, 5, 4};
				_expected = 0.3904761904761904;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}
			case 4:
			{
				int keyCount = 7;
				int badLane1[] = {3, 5, 1, 0, 2, 6, 4};
				int badLane2[] = {0, 2, 4, 6, 1, 5, 3};
				_expected = 0.09166666666666667;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int keyCount = ;
				int badLane1[] = ;
				int badLane2[] = ;
				_expected = ;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int keyCount = ;
				int badLane1[] = ;
				int badLane2[] = ;
				_expected = ;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int keyCount = ;
				int badLane1[] = ;
				int badLane2[] = ;
				_expected = ;
				_received = _obj.getProbability(keyCount, vector <int>(badLane1, badLane1+sizeof(badLane1)/sizeof(int)), vector <int>(badLane2, badLane2+sizeof(badLane2)/sizeof(int))); break;
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
