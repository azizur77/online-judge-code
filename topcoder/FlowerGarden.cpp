#line 2 "FlowerGarden.cpp"
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

vi _bloom, _wilt;

bool overlap(int i, int j) {
	bool case1 = _bloom[j] <= _wilt[i] && _wilt[i] <= _wilt[j];
	bool case2 = _bloom[i] <= _wilt[j] && _wilt[j] <= _wilt[i];
	return case1 || case2; 
}


class FlowerGarden {
	public:
	vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
		bool blocks[51][51];
		_bloom = bloom;
		_wilt = wilt;
		fill(blocks, 0);
		int n = sz(height);
		// Does i block j
		REP(i, n)
			REP(j, n)
				if (i != j && height[i] > height[j] && overlap(i, j))
					blocks[i][j] = true;

		vi result;
		bool seen[51] = {0};

		for (int k=0; k < n; k++) {
			int tallest = 0, idx = -1;
			for(int i=0; i < n; i++) {
				if (seen[i]) continue;
				bool flag = true;
				for(int j = 0; j < n; j++) 
					if (j != i && blocks[i][j]) {
						flag = false;
						break;
					}
				if (flag && height[i] > tallest) {
					tallest = height[i];
					idx = i;
				}
			}
			assert(idx != -1);
			result.push_back(tallest);
			seen[idx] = true;
			for(int i=0; i < n; i++)
				blocks[i][idx] = false;
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
		cout << "Testing FlowerGarden (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352689562;
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
		FlowerGarden _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int height[] = {5,4,3,2,1};
				int bloom[] = {1,1,1,1,1};
				int wilt[] = {365,365,365,365,365};
				int __expected[] = { 1,  2,  3,  4,  5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}
			case 1:
			{
				int height[] = {5,4,3,2,1};
				int bloom[] = {1,5,10,15,20};
				int wilt[] = {4,9,14,19,24};
				int __expected[] = { 5,  4,  3,  2,  1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}
			case 2:
			{
				int height[] = {5,4,3,2,1};
				int bloom[] = {1,5,10,15,20};
				int wilt[] = {5,10,15,20,25};
				int __expected[] = { 1,  2,  3,  4,  5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}
			case 3:
			{
				int height[] = {5,4,3,2,1};
				int bloom[] = {1,5,10,15,20};
				int wilt[] = {5,10,14,20,25};
				int __expected[] = { 3,  4,  5,  1,  2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}
			case 4:
			{
				int height[] = {1,2,3,4,5,6};
				int bloom[] = {1,3,1,3,1,3};
				int wilt[] = {2,4,2,4,2,4};
				int __expected[] = { 2,  4,  6,  1,  3,  5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}
			case 5:
			{
				int height[] = {3,2,5,4};
				int bloom[] = {1,2,11,10};
				int wilt[] = {4,3,12,13};
				int __expected[] = { 4,  5,  2,  3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}
			/*case 6:
			{
				int height[] = ;
				int bloom[] = ;
				int wilt[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int height[] = ;
				int bloom[] = ;
				int wilt[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int height[] = ;
				int bloom[] = ;
				int wilt[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOrdering(vector <int>(height, height+sizeof(height)/sizeof(int)), vector <int>(bloom, bloom+sizeof(bloom)/sizeof(int)), vector <int>(wilt, wilt+sizeof(wilt)/sizeof(int))); break;
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
