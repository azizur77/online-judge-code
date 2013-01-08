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

string tolower(string a) {
	for(int i=0; i < sz(a); i++) 
		if (a[i] >= 65 && a[i] <= 90)
			a[i] += 32;
	return a;
}

struct team {
	string name;
	int wins, ties, defeats, gf, ga;
	team(string n) : name(n) {
		wins = ties = defeats = gf = ga = 0;
	}
	const int games() const {
		return wins + ties + defeats;
	}
	const int gd() const {
		return gf - ga;
	}
	const int points() const {
		return 3 * wins + ties;
	}
	const bool operator<(team const &other) const {
		if (points() != other.points()) return points() > other.points();
		if (wins != other.wins) return wins > other.wins;
		if (gd() != other.gd()) return gd() > other.gd();
		if (gf != other.gf) return gf > other.gf;
		if (games() != other.games()) return games() < other.games();
		return tolower(name) < tolower(other.name); 
	}

};

string readline() {
	string buf;
	char c = getchar();
	while (c == '\n') c = getchar();
	while(c != '\n') {
		buf += c;
		c = getchar();
	}
	return buf;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t < T; t++) {
		string tournament, teamA, teamB;
		tournament = readline();
		cout << tournament << endl;
		
		map<string, team*> teams;
		int nteams, nmatches, g1, g2;
		scanf("%d", &nteams);
		REP(i, nteams) {
			string s = readline();
			teams[s] = new team(s);
		}
		scanf("%d", &nmatches);
		REP(i, nmatches) {
			// scanf("%s#%d@%d#%s", s1, &g1, &g2, s2);
			string s1, s2;
			while (true) {
				char a = getchar();
				if (a == '#') break;
				if (a != '\n') s1 += a; 
			}
			scanf("%d@%d#", &g1, &g2);
			while (true) {
				char a = getchar();
				if (a == '\n') break;
				s2 += a; 
			}

			teamA = s1;
			teamB = s2;
			if (g1 > g2) {
				teams[teamA]->wins++;
				teams[teamB]->defeats++;
			}
			else if (g1 < g2) {
				teams[teamB]->wins++;
				teams[teamA]->defeats++;
			}
			else {
				teams[teamA]->ties++;
				teams[teamB]->ties++;
			}
			teams[teamA]->gf += g1;
			teams[teamA]->ga += g2;
			teams[teamB]->ga += g1;
			teams[teamB]->gf += g2;
		}
		vector<team> rankings;
		map<string, team*>::iterator it;
		for(it = teams.begin(); it != teams.end(); it++) {
			rankings.push_back(*(*it).Y);
		}
		sort(all(rankings));
		for(int i=0; i < rankings.size(); i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
				i+1, rankings[i].name.c_str(), rankings[i].points(), rankings[i].games(), rankings[i].wins, 
				rankings[i].ties, rankings[i].defeats, rankings[i].gd(), 
				rankings[i].gf, rankings[i].ga);
		}
		if (t < T-1) printf("\n");
	}
	return 0;
}
