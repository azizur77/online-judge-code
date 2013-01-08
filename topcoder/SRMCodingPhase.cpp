#line 2 "SRMCodingPhase.cpp"
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

vi _skills, _points;

int memo[101][101][3];
int f[] = {2, 4, 8};

int solve(int t, int idx, int luck) {
	if (idx == 3 || t >= 75) return 0;
	if (memo[t][luck][idx] != -1) return memo[t][luck][idx];

	int limit = min(luck, _skills[idx] - 1) + 1;
	int ret = solve(t, idx+1, luck);
	if (t + _skills[idx] <= 75) 
		ret = max(ret, _points[idx] - f[idx]*_skills[idx] + solve(t + _skills[idx], idx + 1, luck));



	FOR(i, 1, limit) {
		if (t + _skills[idx] - i <= 75)
		ret = max(ret, _points[idx] - f[idx] * _skills[idx] + f[idx] * i + 
			solve(t + _skills[idx] - i, idx + 1, luck - i));
	}

	return (memo[t][luck][idx] = ret);
}

class SRMCodingPhase {
	public:
	int countScore(vector <int> points, vector <int> skills, int luck) {
		fill(memo, -1);
		_points = points;
		_skills = skills;
		return solve(0, 0, luck);
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
		cout << "Testing SRMCodingPhase (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352601352;
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
		SRMCodingPhase _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {250, 500, 1000};
				int skills[] = {10, 25, 40};
				int luck = 0;
				_expected = 1310;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 1:
			{
				int points[] = {300, 600, 900};
				int skills[] = {30, 65, 90};
				int luck = 25;
				_expected = 680;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 2:
			{
				int points[] = {250, 550, 950};
				int skills[] = {10, 25, 40};
				int luck = 75;
				_expected = 1736;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 3:
			{
				int points[] = {256, 512, 1024};
				int skills[] = {35, 30, 25};
				int luck = 0;
				_expected = 1216;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			case 4:
			{
				int points[] = {300, 600, 1100};
				int skills[] = {80, 90, 100};
				int luck = 4;
				_expected = 0;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}
			/*case 5:
			{
				int points[] = ;
				int skills[] = ;
				int luck = ;
				_expected = ;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}*/
			/*case 6:
			{
				int points[] = ;
				int skills[] = ;
				int luck = ;
				_expected = ;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
			}*/
			/*case 7:
			{
				int points[] = ;
				int skills[] = ;
				int luck = ;
				_expected = ;
				_received = _obj.countScore(vector <int>(points, points+sizeof(points)/sizeof(int)), vector <int>(skills, skills+sizeof(skills)/sizeof(int)), luck); break;
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
