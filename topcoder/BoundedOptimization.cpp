#line 2 "BoundedOptimization.cpp"
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


class BoundedOptimization {
	public:
	double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum) {
		
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
		cout << "Testing BoundedOptimization (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1352569603;
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
		BoundedOptimization _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string expr[] = {"ba+cb"};
				int lowerBound[] = {0,0,1};
				int upperBound[] = {1,2,1};
				int maxSum = 3;
				_expected = 2.25;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}
			case 1:
			{
				string expr[] = {"ab"};
				int lowerBound[] = {0, 0, 10};
				int upperBound[] = {20, 20, 20};
				int maxSum = 12;
				_expected = 1.0;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}
			case 2:
			{
				string expr[] = {"ca+fc+fa+d","b+da+","dc+c","b","+ed+eb+ea"};
				int lowerBound[] = {10,11,12,13,14,15};
				int upperBound[] = {15,16,17,18,19,20};
				int maxSum = 85;
				_expected = 2029.25;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}
			case 3:
			{
				string expr[] = {"db+ea+ik+kh+je+","fj+lk+i","d+jb+h","a+gk+mb+ml+lc+mh+cf+fd+","gc+ka+gf+bh+mj+eg+bf+hf+l","b+al+ja+da+i",
				                "f+g","h+ia+le+ce+gi+d","h+mc+fe+dm+im+kb+bc+","ib+ma+eb+mf+jk+kc+mg+mk+","gb+dl+ek+hj+dg+hi","+ch+ga+ca+fl+ij+fa+jl+dc+dj+fk","+li+jg"};
				int lowerBound[] = {57,29,50,21,49,29,88,33,84,76,95,55,11};
				int upperBound[] = {58,80,68,73,52,84,100,79,93,98,95,69,97};
				int maxSum = 845;
				_expected = 294978.3333333333;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}
			/*case 4:
			{
				string expr[] = ;
				int lowerBound[] = ;
				int upperBound[] = ;
				int maxSum = ;
				_expected = ;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}*/
			/*case 5:
			{
				string expr[] = ;
				int lowerBound[] = ;
				int upperBound[] = ;
				int maxSum = ;
				_expected = ;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}*/
			/*case 6:
			{
				string expr[] = ;
				int lowerBound[] = ;
				int upperBound[] = ;
				int maxSum = ;
				_expected = ;
				_received = _obj.maxValue(vector <string>(expr, expr+sizeof(expr)/sizeof(string)), vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int)), maxSum); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
