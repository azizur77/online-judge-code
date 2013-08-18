#line 2 "SentenceDecomposition.cpp"
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
#define INF (int)1e7
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef long long ll;

int K = 0, memo[51], N;
string S;
map<string, vs>  words;

int solve(int start) {
	if (start == N) return 0;
	if (memo[start] != -1) return memo[start]; 
	int best = INF;
	for(int i=1; i <= min(N-start, K); i++) {
		string t = S.substr(start, i);
		string u = t;
		sort(all(t));
		if (words.find(t) != words.end()) {
			for(int j=0; j < words[t].size(); j++) {
				int cost = 0;
				for(int k=0; k < sz(words[t][j]); k++) cost += (words[t][j][k] != u[k]);
				best = min(best, cost + solve(start + i));
			}
		}
	}
	return (memo[start] = best);
}

class SentenceDecomposition {
	public:
	int decompose(string sentence, vector <string> validWords) {
		for(int i=0; i < sz(validWords); i++) {
			string w = validWords[i];
			K = max(K, sz(w));
			sort(all(w));
			words[w].push_back(validWords[i]);
		}

		for(int i=0; i < 51; i++) memo[i] = -1;


		S = sentence;
		N = sz(sentence);

		int ans = solve(0);
		if (ans > INF/2) return -1;
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
		cout << "Testing SentenceDecomposition (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1363163406;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SentenceDecomposition _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string sentence = "neotowheret";
				string validWords[] = {"one", "two", "three", "there"};
				_expected = 8;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 1:
			{
				string sentence = "abba";
				string validWords[] = {"ab", "ac", "ad"};
				_expected = 2;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 2:
			{
				string sentence = "thisismeaningless";
				string validWords[] = {"this", "is", "meaningful"};
				_expected = -1;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 3:
			{
				string sentence = "ommwreehisymkiml";
				string validWords[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
				_expected = 10;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 4:
			{
				string sentence = "ogodtsneeencs";
				string validWords[] = {"go", "good", "do", "sentences", "tense", "scen"};
				_expected = 8;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			case 5:
			{
				string sentence = "sepawaterords";
				string validWords[] = {"separate","words"};
				_expected = -1;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}
			/*case 6:
			{
				string sentence = ;
				string validWords[] = ;
				_expected = ;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string sentence = ;
				string validWords[] = ;
				_expected = ;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string sentence = ;
				string validWords[] = ;
				_expected = ;
				_received = _obj.decompose(sentence, vector <string>(validWords, validWords+sizeof(validWords)/sizeof(string))); break;
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
