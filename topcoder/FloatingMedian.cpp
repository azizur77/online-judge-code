#line 2 "FloatingMedian.cpp"
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
#define MAXN 66000

int tree[MAXN];

void update(int idx, int val)  {
	while(idx < MAXN) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int read(int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int _K;
int search(int target) {
	int lo = 0, hi = 65537, ret = 65537;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if (read(mid+1) >= target) {
			ret = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return ret;
}

class FloatingMedian {
	public:
	long long sumOfMedians(int seed, int mul, int add, int N, int K) {
		_K = K;
		vi arr(N, 0);
		arr[0] = seed;
		FOR(i, 1, N) arr[i] = ((ll) mul * arr[i-1] + add) % 65536;
		ll medcnt = 0;
		int median = (K+1) / 2;
		for(int i=0; i < K; i++) {
			update(arr[i]+1, 1);
		}
		
		medcnt = search(median);

		for(int i=K; i < N; i++) {
			update(arr[i-K]+1, -1);
			update(arr[i]+1, 1);
			medcnt += search(median);
		}
		return medcnt;
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
		cout << "Testing FloatingMedian (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352887787;
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
		FloatingMedian _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seed = 1;
				int mul = 2;
				int add = 0;
				int N = 250000;
				int K = 23;
				_expected = 80LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 1:
			{
				int seed = 10;
				int mul = 0;
				int add = 13;
				int N = 5;
				int K = 2;
				_expected = 49LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 2:
			{
				int seed = 4123;
				int mul = 2341;
				int add = 1231;
				int N = 7;
				int K = 3;
				_expected = 102186LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 3:
			{
				int seed = 47;
				int mul = 5621;
				int add = 1;
				int N = 125000;
				int K = 1700;
				_expected = 4040137193LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			case 4:
			{
				int seed = 32321;
				int mul = 46543;
				int add = 32552;
				int N = 17;
				int K = 17;
				_expected = 25569LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}
			/*case 5:
			{
				int seed = ;
				int mul = ;
				int add = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}*/
			/*case 6:
			{
				int seed = ;
				int mul = ;
				int add = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
			}*/
			/*case 7:
			{
				int seed = ;
				int mul = ;
				int add = ;
				int N = ;
				int K = ;
				_expected = LL;
				_received = _obj.sumOfMedians(seed, mul, add, N, K); break;
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
