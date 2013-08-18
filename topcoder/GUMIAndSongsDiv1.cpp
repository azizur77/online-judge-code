#line 2 "GUMIAndSongsDiv1.cpp"
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

map<int, int> cache[55][55];
vi dur, ton;
int N;

bool cmp(int a, int b) {
	return ton[a] < ton[b];
}

int solve(int left, int idx, int last) {
	if (idx == N || left < 0) return 0;
	if (cache[idx][last].find(left) != cache[idx][last].end())
		return cache[idx][last][left];

	int res = 0;
	int diff = ton[idx] - ton[last];

	if ((diff + dur[idx]) > left)
		return 0;

	res = max(solve(left, idx+1, last), 1 + solve(left - diff - dur[idx], idx + 1, idx));
	cache[idx][last][left] = res;
	return res;
}

class GUMIAndSongsDiv1 {
	public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		dur = duration;
		ton = tone;
		N = sz(duration);
		sort(all(dur), cmp);
		sort(all(ton));

		return solve(T, 0, 0);
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
		cout << "Testing GUMIAndSongsDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1376320207;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GUMIAndSongsDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int duration[] = {3, 5, 4, 11};
				int tone[] = {2, 1, 3, 1};
				int T = 17;
				_expected = 3;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 1:
			{
				int duration[] = {100, 200, 300};
				int tone[] = {1, 2, 3};
				int T = 99;
				_expected = 0;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 2:
			{
				int duration[] = {1, 2, 3, 4};
				int tone[] = {1, 1, 1, 1};
				int T = 100;
				_expected = 4;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 3:
			{
				int duration[] = {9, 11, 13, 17};
				int tone[] = {2, 1, 3, 4};
				int T = 20;
				_expected = 1;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 4:
			{
				int duration[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
				                  67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97};
				int tone[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
				              61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3};
				int T = 212;
				_expected = 12;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			/*case 5:
			{
				int duration[] = ;
				int tone[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}*/
			/*case 6:
			{
				int duration[] = ;
				int tone[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}*/
			/*case 7:
			{
				int duration[] = ;
				int tone[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
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
