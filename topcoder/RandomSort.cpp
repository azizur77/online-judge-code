#line 2 "RandomSort.cpp"
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
#include <map>
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

vi sorted, perm;
int n;
double moves = 0.0;
map<vi, double> memo;

double solve() {
	if (perm == sorted) return 0;
	if (memo.find(perm) != memo.end()) return memo[perm];
	double swaps = 0.0, cnt = 0;

	for(int i=0; i < n; i++)
		for(int j=i+1; j < n; j++)
			if (perm[j] < perm[i]) {
				cnt += 1;
				swap(perm[i], perm[j]);
				swaps += solve();
				swap(perm[i], perm[j]);
			}
	if (cnt > 0) memo[perm] = 1.0 + swaps/cnt;
	else memo[perm] = 0;
	return memo[perm];
}

class RandomSort {
	public:
	double getExpected(vector <int> permutation) {
		n = sz(permutation);
		sorted = permutation;
		perm = permutation;
		sort(all(sorted));
		return solve();
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
		cout << "Testing RandomSort (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362643351;
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
		RandomSort _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int permutation[] = {1,3,2};
				_expected = 1.0;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 1:
			{
				int permutation[] = {4,3,2,1};
				_expected = 4.066666666666666;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 2:
			{
				int permutation[] = {1};
				_expected = 0.0;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			case 3:
			{
				int permutation[] = {7,8,1,6,4,2,3,5};
				_expected = 5.666666666666666;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}
			/*case 4:
			{
				int permutation[] = ;
				_expected = ;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int permutation[] = ;
				_expected = ;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int permutation[] = ;
				_expected = ;
				_received = _obj.getExpected(vector <int>(permutation, permutation+sizeof(permutation)/sizeof(int))); break;
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
