#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> nums(n, 0); 
	for(ll i=0; i < n; i++) cin >> nums[i];
	set<ll> check(all(nums));

	sort(all(nums));
	assert(sz(check) == n);

	ll ans = 0;
	for(ll i=0; i < n; i++) {
		ll prev = nums[i];
		ll cnt = 0;
		while (check.find(prev) != check.end()) {
			check.erase(prev);
			prev *= k;
			cnt++;
		}
		ans += (cnt+1) / 2;
	}
	cout << ans << endl;
}