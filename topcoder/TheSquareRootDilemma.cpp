#line 2 "TheSquareRootDilemma.cpp"
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

bool is_int(double x) {
	return (((int) x) == x);
}

set<ii> seen;

class TheSquareRootDilemma {
	public:
	int countPairs(int N, int M) {
		// vi set1, set2;
		// for(int i=1; i * i <= N; i++) set1.push_back(i);	
		// for(int i=1; i * i <= M; i++) set2.push_back(i);	
		// for(int i=0; i < sz(set1); i++)
		// 	for(int j=0; j < sz(set2); j++)
		// 		if (set1[i] != set2[j])
		// 			count++;
		for(int i=1; i <= min(M, N); i++)
			for(int j=1; j <= sqrt(M/i + 1) + 1; j++)
				for(int k=1; k <= sqrt(N/i + 1) + 1; k++)
				if (i*j*j <= M && i*k*k <= N)
					seen.insert(ii(i*j*j, i*k*k));
		return sz(seen);
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
		cout << "Testing TheSquareRootDilemma (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358771173;
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
		TheSquareRootDilemma _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				_expected = 2;
				_received = _obj.countPairs(N, M); break;
			}
			case 1:
			{
				int N = 10;
				int M = 1;
				_expected = 3;
				_received = _obj.countPairs(N, M); break;
			}
			case 2:
			{
				int N = 3;
				int M = 8;
				_expected = 5;
				_received = _obj.countPairs(N, M); break;
			}
			case 3:
			{
				int N = 100;
				int M = 100;
				_expected = 310;
				_received = _obj.countPairs(N, M); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
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
