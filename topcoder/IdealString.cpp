#line 2 "IdealString.cpp"
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

ii parent[105][1000];

class IdealString {
	public:
	string construct(int length) {
		for(int i=0; i < length+1; i++)
			for(int j=0; j < length+1; j++)
				parent[i][j] = ii(-1, -1);

		queue<ii> Q;
		bool found = false;
		Q.push(ii(1, 1));
		ii last;

		while(Q.size()) {
			ii curr = Q.front();
			Q.pop();
			if (curr.Y > length) continue;
			else if (curr.Y == length) {
				found = true;
				last = curr;
				break;
			}

			for(int i=curr.Y+1; i > curr.X; i--)
				if (parent[i][curr.Y + i] == ii(-1, -1)) {
					parent[i][curr.Y + i] = curr; 
					Q.push(ii(i, curr.Y+i));
				}
		}

		if (!found) return "";

		string ans (length, '?');
		ans[0] = 'A';
		vector<int> indices;

		for(ii u = last; u != ii(1, 1); u = parent[u.X][u.Y])
			indices.push_back(u.X - 1);
		reverse(all(indices));

		int max_count[26] = {0}, curr_count[26] = {0};

		for(int i=0; i < sz(indices); i++) {
			ans[indices[i]] = 'A' + i + 1;
			max_count[i+1] = indices[i] + 1;
		}


		for(int i=0; i < sz(ans); i++)
			if (ans[i] != '?')
				curr_count[ans[i]-'A']++;


		for(char c='A'; c <= 'Z'; c++) {
			int idx = 0;
			while(idx < length && curr_count[c-'A'] < max_count[c-'A']) {
				if (ans[idx] == '?') {
					ans[idx] = c;
					curr_count[c-'A']++;
				}
				idx++;
			}
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
		cout << "Testing IdealString (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1362718650;
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
		IdealString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 1;
				_expected = "A";
				_received = _obj.construct(length); break;
			}
			case 1:
			{
				int length = 3;
				_expected = "ABB";
				_received = _obj.construct(length); break;
			}
			case 2:
			{
				int length = 2;
				_expected = "";
				_received = _obj.construct(length); break;
			}
			case 3:
			{
				int length = 6;
				_expected = "ABCBCC";
				_received = _obj.construct(length); break;
			}
			case 4:
			{
				int length = 7;
				_expected = "ABBCCCC";
				_received = _obj.construct(length); break;
			}
			case 5:
			{
				int length = 5;
				_expected = "";
				_received = _obj.construct(length); break;
			}
			/*case 6:
			{
				int length = ;
				_expected = ;
				_received = _obj.construct(length); break;
			}*/
			/*case 7:
			{
				int length = ;
				_expected = ;
				_received = _obj.construct(length); break;
			}*/
			/*case 8:
			{
				int length = ;
				_expected = ;
				_received = _obj.construct(length); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
