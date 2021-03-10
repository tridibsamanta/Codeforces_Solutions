/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define vvi                 vector<vector<int> >
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int n;
	cin >> n;

	n *= 2;

	vi cards(n);

	FOR (i, 0, n) {
		cin >> cards[i];
	}

	vvi occ(5001, vi {});

	FOR (i, 0, n) {
		occ[cards[i]].eb(i + 1);
	}

	vpii ans;

	FOR (i, 1, 5001) {
		if (sz(occ[i]) & 1) {
			cout << -1;
			return;
		}

		for (int j = 0; j < sz(occ[i]); j += 2) {
			ans.eb(mp(occ[i][j], occ[i][j + 1]));
		}
	}

	FOR (i, 0, sz(ans)) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}

}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
		// cout << '\n';
	}

	return 0;
}