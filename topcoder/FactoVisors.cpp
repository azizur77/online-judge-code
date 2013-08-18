#line 2 "FactoVisors.cpp"
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

map<int, int> factorize (int num) {
	map<int, int> M;
	int copy = num;
	for(int i=2; i * i <= copy; i++) {
		while (num % i == 0) {
			M[i]++;
			num /= i;
		}
	}
	if (num > 1) M[num] += 1;
	return M;
}

map<int, int> gcdM(map<int, int> P, map<int, int> Q) {
	map<int, int>::iterator it;
	map<int, int> M;
	for(it = P.begin(); it != P.end(); it++) {
		if (Q.find((*it).X) == Q.end()) continue;
		M[(*it).X] = min((*it).Y, Q[(*it).X]);
	}
	return M;
}

map<int, int> lcmM(map<int, int> P, map<int, int> Q) {
	map<int, int>::iterator it;
	map<int, int> M;
	for(it = P.begin(); it != P.end(); it++) {
		int key = (*it).X, val = (*it).Y;
		if (Q.find(key) == Q.end()) M[key] = val;
		M[key] = max(val, Q[key]);
	}
	for(it = Q.begin(); it != Q.end(); it++) {
		int key = (*it).X, val = (*it).Y;
		if (P.find(key) == P.end()) M[key] = val;
		M[key] = max(val, P[key]);
	}
	return M;
}

void debug(map<int, int> M) {
	map<int, int>::iterator it;
	for(it = M.begin(); it != M.end(); it++) {
		int key = (*it).X, val = (*it).Y;
		cout << key << ": " << val << endl;
	}
	cout << endl;
}

class FactoVisors {
	public:
	int getNum(vector <int> divisor, vector <int> multiple) {
		set<int> D (all(divisor));
		vector<int> divisors(all(D));

		set<int> m (all(multiple));
		vector<int> multiples(all(m));

		map<int, int> L, G;

		for(int i=0; i < sz(divisors); i++) {
			L = lcmM(L, factorize(divisors[i]));
		}

		G = factorize(multiples[0]);
		for(int i=1; i < sz(multiples); i++) {
			G = gcdM(G, factorize(multiples[i]));
		}

		map<int, int>::iterator it;
		for(it = L.begin(); it != L.end(); it++) {
			int key = (*it).X, val = (*it).Y;
			if (val > 0 && G.find(key) == G.end()) return 0;
			if (G[key] < val) return 0;
			G[key] -= val;
		}

		ll ans = 1;

		for(it = G.begin(); it != G.end(); it++) {
			int val = (*it).Y;
			ans = ans * (val+1);
		}
		return ans;
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
		cout << "Testing FactoVisors (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362735561;
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
		FactoVisors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int divisors[] = {23, 23, 1, 575, 25, 1, 5, 1, 1, 5, 575, 575, 23, 23, 23, 5, 575, 23, 115, 5, 115, 1, 575, 5, 575, 23, 23, 575, 25, 25, 1, 23, 115, 575, 115, 5, 5, 575, 5, 1, 25, 25};
				int multiples[] = {632761050, 949141575, 316380525, 949141575, 949141575, 632761050, 949141575, 632761050, 316380525};
				_expected = 8;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}
			case 1:
			{
				int divisors[] = {1};
				int multiples[] = {1000000000, 500000000, 600000000, 700000000, 800000000, 900000000, 400000000, 300000000};
				_expected = 81;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}
			case 2:
			{
				int divisors[] = {6,9};
				int multiples[] = {96,180};
				_expected = 0;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}
			case 3:
			{
				int divisors[] = {2,4};
				int multiples[] = {256};
				_expected = 7;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}
			case 4:
			{
				int divisors[] = {1000,10000,100000};
				int multiples[] = {1000000000};
				_expected = 25;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}
			/*case 5:
			{
				int divisors[] = ;
				int multiples[] = ;
				_expected = ;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int divisors[] = ;
				int multiples[] = ;
				_expected = ;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int divisors[] = ;
				int multiples[] = ;
				_expected = ;
				_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
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
