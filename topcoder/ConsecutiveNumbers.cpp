#line 2 "ConsecutiveNumbers.cpp"
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


class ConsecutiveNumbers {
	public:
	vector <int> missingNumber(vector <int> numbers) {
		bool check[55] = {0};
		int minel = *min_element(all(numbers));
		int maxel = *max_element(all(numbers));
		if (maxel - minel > sz(numbers)) return vi();
		set<int> dups(all(numbers));
		if (sz(dups) != sz(numbers)) return vi();
		for(int i=0; i < sz(numbers); i++) 
			if (numbers[i] - minel < 55)
				check[numbers[i] - minel] = 1;
		int counter = 0;
		for(int i=minel; i <= maxel; i++) if (check[i-minel]) counter++;

		if (counter == maxel - minel + 1) {
			vi res;
			if (minel > 1)	res.push_back(minel-1);
			res.push_back(maxel+1);
			return res;
		} else if (counter == maxel - minel) {
			vi res;
			for(int i=minel; i <= maxel; i++) if (!check[i - minel]) { res.push_back(i); break; }
			return res;
		} else {
			return vi();
		}
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
		cout << "Testing ConsecutiveNumbers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362642110;
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
		ConsecutiveNumbers _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {10,7,12,8,11};
				int __expected[] = {9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 1:
			{
				int numbers[] = {3,6};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 2:
			{
				int numbers[] = {5,6,7,8};
				int __expected[] = {4, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 3:
			{
				int numbers[] = {1000000000};
				int __expected[] = {999999999, 1000000001 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 4:
			{
				int numbers[] = {1,6,9,3,8,12,7,4,11,5,10};
				int __expected[] = {2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 5:
			{
				int numbers[] = {1};
				int __expected[] = {2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			/*case 6:
			{
				int numbers[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int numbers[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.missingNumber(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
