#line 2 "IntegerPalindrome.cpp"

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
#include <sstream>
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

ll s2long(string a) {
	stringstream ss;
	ss << a;
	ll b;
	ss >> b;
	return b;
}

ll powers[20];

string solve(int idx, int digits, bool zeros=false) {
	if (digits == 0) return "";
	if (digits == 1 && zeros == false) return string(1, '0' + idx);
	if (digits == 1 && zeros == true) return string(1, '0' + idx-1);

	int cpy = idx;
	ll step = powers[digits - 2];

	int start = zeros ? 0 : 1;

	for(int i=start; i <= 9; i++) {
		cpy -= step;
		if (cpy <= 0) {
			string c(1, '0' + i);
			return c + solve(cpy+step, digits - 2, true) + c;
		}
	}
	return "fail";
}

class IntegerPalindrome {
	public:
	long long findByIndex(int K) {
		K++;
		int countdigits[20];
		countdigits[2] = countdigits[1] = 9;
		powers[0] = 1;
		powers[1]= powers[2] = 10;

		for(int i=3; i < 20; i++) {
			countdigits[i] = 10 * countdigits[i-2];
			powers[i] = 10 * powers[i-2];
		}
		int num_digits = 0;
		int idx = K;
		while(idx > 0) {
			num_digits++;
			idx -= countdigits[num_digits];
		} 
		printf("%d %d\n", idx + countdigits[num_digits], num_digits);
		return s2long(solve(idx + countdigits[num_digits], num_digits));
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
		cout << "Testing IntegerPalindrome (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1374167331;
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
		IntegerPalindrome _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 8;
				_expected = 9LL;
				_received = _obj.findByIndex(K); break;
			}
			case 1:
			{
				int K = 9;
				_expected = 11LL;
				_received = _obj.findByIndex(K); break;
			}
			case 2:
			{
				int K = 19;
				_expected = 111LL;
				_received = _obj.findByIndex(K); break;
			}
			case 3:
			{
				int K = 235;
				_expected = 13731LL;
				_received = _obj.findByIndex(K); break;
			}
			case 4:
			{
				int K = 23746;
				_expected = 137484731LL;
				_received = _obj.findByIndex(K); break;
			}
			/*case 5:
			{
				int K = ;
				_expected = LL;
				_received = _obj.findByIndex(K); break;
			}*/
			/*case 6:
			{
				int K = ;
				_expected = LL;
				_received = _obj.findByIndex(K); break;
			}*/
			/*case 7:
			{
				int K = ;
				_expected = LL;
				_received = _obj.findByIndex(K); break;
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
