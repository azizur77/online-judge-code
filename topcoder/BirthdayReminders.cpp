#line 2 "BirthdayReminders.cpp"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
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

struct birthday {
	int oindex, findex, occno, day;
	string name, occasion;
	birthday(int oi, int fi, int o, int d, string n, string os) : 
		oindex(oi), findex(fi), occno(o), day(d), name(n), occasion(os) {}
	string print() {
		stringstream ss;
		ss << day << ". " + name + " " + occasion + " (" << occno << ")";
		return ss.str();
	}

};

bool cmp(birthday x, birthday y) {
	if (x.day != y.day) return x.day < y.day;
	if (x.oindex != y.oindex) return x.oindex < y.oindex;
	return x.findex < y.findex;
}


class BirthdayReminders {
	public:
	vector <string> remind(vector <string> friendNames, vector <int> birthDates, int currentDate, vector <string> occasions, vector <int> days, int k) {
		vector<birthday> birthdays;

		for(int i=0; i < sz(friendNames); i++) {
			for(int j=0; j < sz(days); j++) {
				int ctr = 0;
				int onum = (currentDate - 1 - birthDates[i]) / days[j];
				int bd = birthDates[i] + onum * days[j];
				while (ctr < k) {
					if (bd < currentDate) {
						onum = (currentDate + days[j] - 1 - birthDates[i]) / days[j];
						bd = onum * days[j] + birthDates[i];
					} else {
						bd += days[j];
						++onum;
					}
					if (bd >= currentDate) {
						birthdays.push_back(birthday(j, i, onum, bd, friendNames[i], 
							occasions[j]));
						ctr++;
					}
				}
			}
		}
		sort(all(birthdays), cmp);
		vector<string> results;
		for(int i=0; i < k; i++) results.push_back(birthdays[i].print());
		return results;
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
		cout << "Testing BirthdayReminders (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363231649;
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
		BirthdayReminders _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string friendNames[] = {"John", "Jack", "Bill"};
				int birthDates[] = {50, 100, 150};
				int currentDate = 500;
				string occasions[] = {"birthday", "decimal birthday", "binary birthday"};
				int days[] = {365, 1000, 512};
				int k = 10;
				string __expected[] = {"515. Bill birthday (1)", "562. John binary birthday (1)", "612. Jack binary birthday (1)", "662. Bill binary birthday (1)", "780. John birthday (2)", "830. Jack birthday (2)", "880. Bill birthday (2)", "1050. John decimal birthday (1)", "1074. John binary birthday (2)", "1100. Jack decimal birthday (1)" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.remind(vector <string>(friendNames, friendNames+sizeof(friendNames)/sizeof(string)), vector <int>(birthDates, birthDates+sizeof(birthDates)/sizeof(int)), currentDate, vector <string>(occasions, occasions+sizeof(occasions)/sizeof(string)), vector <int>(days, days+sizeof(days)/sizeof(int)), k); break;
			}
			case 1:
			{
				string friendNames[] = {"Zero", "Two", "Three"};
				int birthDates[] = {0, 2, 3};
				int currentDate = 24;
				string occasions[] = {"threeday", "twoday"};
				int days[] = {3,2};
				int k = 10;
				string __expected[] = {"24. Zero threeday (8)", "24. Three threeday (7)", "24. Zero twoday (12)", "24. Two twoday (11)", "25. Three twoday (11)", "26. Two threeday (8)", "26. Zero twoday (13)", "26. Two twoday (12)", "27. Zero threeday (9)", "27. Three threeday (8)" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.remind(vector <string>(friendNames, friendNames+sizeof(friendNames)/sizeof(string)), vector <int>(birthDates, birthDates+sizeof(birthDates)/sizeof(int)), currentDate, vector <string>(occasions, occasions+sizeof(occasions)/sizeof(string)), vector <int>(days, days+sizeof(days)/sizeof(int)), k); break;
			}
			case 2:
			{
				string friendNames[] = {"Jessica Alba", "Angelina Jolie", "Paris Hilton", "Britney Spears"};
				int birthDates[] = {4135, 1980, 4065, 4353};
				int currentDate = 14091;
				string occasions[] = {"Venus year", "Earth year", "Mars year", "Jupiter year", "Saturn year"};
				int days[] = {225, 365, 687, 4332, 10760};
				int k = 20;
				string __expected[] = {"14130. Angelina Jolie Venus year (54)", "14190. Paris Hilton Venus year (45)", "14208. Britney Spears Earth year (27)", "14253. Britney Spears Venus year (44)", "14260. Jessica Alba Venus year (45)", "14285. Paris Hilton Earth year (28)", "14346. Angelina Jolie Mars year (18)", "14355. Angelina Jolie Venus year (55)", "14355. Jessica Alba Earth year (28)", "14370. Paris Hilton Mars year (15)", "14390. Angelina Jolie Earth year (34)", "14415. Paris Hilton Venus year (46)", "14440. Jessica Alba Mars year (15)", "14478. Britney Spears Venus year (45)", "14485. Jessica Alba Venus year (46)", "14573. Britney Spears Earth year (28)", "14580. Angelina Jolie Venus year (56)", "14640. Paris Hilton Venus year (47)", "14650. Paris Hilton Earth year (29)", "14658. Britney Spears Mars year (15)" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.remind(vector <string>(friendNames, friendNames+sizeof(friendNames)/sizeof(string)), vector <int>(birthDates, birthDates+sizeof(birthDates)/sizeof(int)), currentDate, vector <string>(occasions, occasions+sizeof(occasions)/sizeof(string)), vector <int>(days, days+sizeof(days)/sizeof(int)), k); break;
			}
			/*case 3:
			{
				string friendNames[] = ;
				int birthDates[] = ;
				int currentDate = ;
				string occasions[] = ;
				int days[] = ;
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.remind(vector <string>(friendNames, friendNames+sizeof(friendNames)/sizeof(string)), vector <int>(birthDates, birthDates+sizeof(birthDates)/sizeof(int)), currentDate, vector <string>(occasions, occasions+sizeof(occasions)/sizeof(string)), vector <int>(days, days+sizeof(days)/sizeof(int)), k); break;
			}*/
			/*case 4:
			{
				string friendNames[] = ;
				int birthDates[] = ;
				int currentDate = ;
				string occasions[] = ;
				int days[] = ;
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.remind(vector <string>(friendNames, friendNames+sizeof(friendNames)/sizeof(string)), vector <int>(birthDates, birthDates+sizeof(birthDates)/sizeof(int)), currentDate, vector <string>(occasions, occasions+sizeof(occasions)/sizeof(string)), vector <int>(days, days+sizeof(days)/sizeof(int)), k); break;
			}*/
			/*case 5:
			{
				string friendNames[] = ;
				int birthDates[] = ;
				int currentDate = ;
				string occasions[] = ;
				int days[] = ;
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.remind(vector <string>(friendNames, friendNames+sizeof(friendNames)/sizeof(string)), vector <int>(birthDates, birthDates+sizeof(birthDates)/sizeof(int)), currentDate, vector <string>(occasions, occasions+sizeof(occasions)/sizeof(string)), vector <int>(days, days+sizeof(days)/sizeof(int)), k); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
