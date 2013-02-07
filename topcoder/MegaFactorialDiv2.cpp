#line 2 "MegaFactorialDiv2.cpp"
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

int prime[1006];
vector<ll> factors[1006];

void gen() {
	fill(prime, -1);
	int ctr = 0;

	for(int i=2; i <= 1005; i++) {
		bool flag = true;

		for(int j=2; j <= sqrt(i) + 1; j++)
			if (i % j == 0 && i != j) {
				flag = false;
				break;
			}

		if (flag)
			prime[i] = ctr++;
	}

	for(int cur=1; cur <= 1005; cur++)
		{
			int j = cur;
			factors[cur] = vector<ll> (175, 0);
			for(int i=2; i <= sqrt(cur); i++) if (prime[i] != -1) {
				while (j % i == 0) {
					j /= i;
					factors[cur][prime[i]]++;
				}
			}
			if (j > 0 && prime[j] != -1)
				factors[cur][prime[j]]++;
		}
}

#define MOD 1000000009

class MegaFactorialDiv2 {
	public:
	int countDivisors(int N, int K) {
		gen();
		// for(int i=1; i <= N; i++) {
		// 	cout << i << ": ";
		// 	for(int j=0; j < 175; j++)
		// 		if (factors[i][j])
		// 			printf("(%d, %d) ", j, factors[i][j]);
		// 	cout << endl;
		// }

		vector<ll> prev[K+1], curr[K+1];

		for(int i=0; i <= K; i++)
			prev[i] = vector<ll>(175, 0);

		for(int i=1; i <= N; i++) {
			curr[0] = vector<ll>(175, 0);
			// if (prime[i] != -1) curr[0][prime[i]] = 1;
			 curr[0] = factors[i];

			for(int j=1; j <= K; j++) {
				curr[j] = vector<ll> (175, 0);
				for(int k=0; k < 175; k++) 
					curr[j][k] = (prev[j][k] + curr[j-1][k]) % MOD;
			}
			// if(i < N)
			for(int j=0; j <= K; j++)
				prev[j] = curr[j];
		}

		ll result = 1LL;


		for(int i=0; i < 175; i++) {
			ll temp = (ll) (curr[K][i] + 1LL) % MOD;
			// if (temp > 1)
			// cout << i << " " << temp << " " << endl;
			result = (result*temp) % MOD;
		}

		return result;
		
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
		cout << "Testing MegaFactorialDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1360204378;
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
		MegaFactorialDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 1;
				_expected = 4;
				_received = _obj.countDivisors(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 2;
				_expected = 6;
				_received = _obj.countDivisors(N, K); break;
			}
			case 2:
			{
				int N = 4;
				int K = 2;
				_expected = 18;
				_received = _obj.countDivisors(N, K); break;
			}
			case 3:
			{
				int N = 6;
				int K = 3;
				_expected = 1392;
				_received = _obj.countDivisors(N, K); break;
			}
			case 4:
			{
				int N = 34;
				int K = 69;
				_expected = 321266186;
				_received = _obj.countDivisors(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countDivisors(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countDivisors(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countDivisors(N, K); break;
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
