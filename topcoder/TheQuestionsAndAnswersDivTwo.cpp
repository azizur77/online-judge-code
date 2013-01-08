#line 2 "TheQuestionsAndAnswersDivTwo.cpp"
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


class TheQuestionsAndAnswersDivTwo {
	public:
	int find(vector <string> questions) {
		set<string> nodups(all(questions));
		return (1 << sz(nodups));	
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
		cout << "Testing TheQuestionsAndAnswersDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1353425713;
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
		TheQuestionsAndAnswersDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string questions[] = {"How_are_you_doing?", "How_do_you_like_our_country?", "How_are_you_doing?"};
				_expected = 4;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
			}
			case 1:
			{
				string questions[] = {"Whazzup?"};
				_expected = 2;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
			}
			case 2:
			{
				string questions[] = {"Are_you_ready?", "Are_you_ready?", "Are_you_ready?", "Are_you_ready?"};
				_expected = 2;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
			}
			case 3:
			{
				string questions[] = {"Do_you_like_my_story?", "Do_you_like_my_story", "DO_YOU_LIKE_MY_STORY?", "Do__you__like__my__story?"};
				_expected = 16;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
			}
			/*case 4:
			{
				string questions[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string questions[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string questions[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(questions, questions+sizeof(questions)/sizeof(string))); break;
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
