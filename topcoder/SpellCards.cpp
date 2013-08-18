#line 2 "SpellCards.cpp"
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

vector<int> L, D;
int memo[51][51], flag[51], size;

int solve(int start, int end) {
	if (memo[start][end] != -1) return memo[start][end];
	int ans = 0;

	int currentLength;
	if (start <= end)
		currentLength = end - start + 1;
	else
		currentLength = size - start + (end + 1);

	assert(currentLength > 0);

	for(int i=0; i < currentLength; i++) {
		int j = (start + i) % size;
		assert(L[j] > 0);
		if (L[j] < currentLength)
			ans = max(ans, D[j] + solve( (start + ((i + L[j]) % currentLength)) % size, 
				(start + (currentLength - 1 + i) % currentLength) % size));
		else if (L[j] == currentLength)
			ans = max(ans, D[j]);
	}

	memo[start][end] = ans;
	return ans;
}

class SpellCards {
	public:
	int maxDamage(vector <int> level, vector <int> damage) {
		fill(memo, -1);
		L = level;
		D = damage;
		size = sz(level);
		return solve(0, size-1);
	}
};
/*
0 2
	2 2
	2 0
		0 0
		2 2
	0 1
*/



























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
		cout << "Testing SpellCards (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1369151214;
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
		SpellCards _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int level[] = {1,1,1};
				int damage[] = {10,20,30};
				_expected = 60;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 1:
			{
				int level[] = {3,3,3};
				int damage[] = {10,20,30};
				_expected = 30;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 2:
			{
				int level[] = {4,4,4};
				int damage[] = {10,20,30};
				_expected = 0;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 3:
			{
				int level[] = {50,1,50,1,50};
				int damage[] = {10,20,30,40,50};
				_expected = 60;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 4:
			{
				int level[] = {2,1,1};
				int damage[] = {40,40,10};
				_expected = 80;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 5:
			{
				int level[] = {1,2,1,1,3,2,1};
				int damage[] = {10,40,10,10,90,40,10};
				_expected = 170;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 6:
			{
				int level[] = {1,2,2,3,1,4,2};
				int damage[] = {113,253,523,941,250,534,454};
				_expected = 1918;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			/*case 7:
			{
				int level[] = ;
				int damage[] = ;
				_expected = ;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int level[] = ;
				int damage[] = ;
				_expected = ;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int level[] = ;
				int damage[] = ;
				_expected = ;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
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
