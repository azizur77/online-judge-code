#line 2 "TheSumOfLuckyNumbers.cpp"
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
typedef pair<int, vi> ivi;
typedef long long ll;

bool seen[1000005];
int parent[1000005];

vector<string> numbers;
vi nums;

int atoi(string s) {
	int res = 0;
	for(int i=0; i < sz(s); i++)
		res = 10 * res + (s[i] - '0');
	return res;
}

void generate() {
	stack<string> S;
	set<string> seen;

	S.push("");

	while (sz(S) > 0) {
		string curr = S.top();
		S.pop();
		if (seen.find(curr) != seen.end()) continue;
		seen.insert(curr);
		if (curr != "") numbers.push_back(curr);
		if (sz(curr) >= 6) continue;
		S.push(curr + "4");
		S.push(curr + "7");
	}

	// sort(all(numbers));

	for(int i=0; i < sz(numbers); i++)
		nums.push_back(atoi(numbers[i]));
	sort(all(nums));
}

class TheSumOfLuckyNumbers {
	public:
	vector <int> sum(int n) {
		generate();
		fill(seen, 0);
		fill(parent, -1);
		queue<int> Q;

		Q.push(n);


		while(Q.size() > 0) {
			int curr = Q.front();
			Q.pop();

			if (seen[curr]) continue;
			if (curr > 0) seen[curr] = 1;

			if (curr == 0) {
				break;
			}
			
			for(int i=0; i < sz(nums); i++) 
				if (curr >= nums[i] && !seen[curr - nums[i]]) {
					if (parent[curr - nums[i]] == -1) {
						parent[curr - nums[i]] = curr;
						Q.push(curr - nums[i]);
					}
				}
			
		}
		vi res;
		for(int u=0; parent[u] != -1; u = parent[u]) {
			res.push_back(parent[u] - u);
		}
		sort(all(res));
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
		cout << "Testing TheSumOfLuckyNumbers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362655611;
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
		TheSumOfLuckyNumbers _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 11;
				int __expected[] = {4, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
			}
			case 1:
			{
				int n = 12;
				int __expected[] = {4, 4, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
			}
			case 2:
			{
				int n = 13;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
			}
			case 3:
			{
				int n = 1000000;
				int __expected[] = {4, 4, 4, 44, 44 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
			}
			/*case 4:
			{
				int n = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.sum(n); break;
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
