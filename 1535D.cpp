/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)        for (auto& (i) : (a))
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
#define rsort(a)            sort((a).rbegin(), (a).rend())
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define max3(a, b, c)       max((a), max((b), (c)))
#define min3(a, b, c)       min((a), min((b), (c)))
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int k;
	cin >> k;

	string s;
	cin >> s;

	int teams = (1 << k), nodes = 1 << (k + 1);
	vi ans(nodes);

	FOR (i, teams, nodes) {
		ans[i] = 1;
	}

	// printall(ans);

	s.pb('*');
	reverse(all(s));

	int n = sz(s);

	for (int i = n - 1; i > 0; --i) {
		if (s[i] == '0')
			ans[i] = ans[2 * i + 1];
		else if (s[i] == '1')
			ans[i] = ans[2 * i];
		else
			ans[i] = ans[2 * i + 1] + ans[2 * i];
	}

	// printall(ans);

	int q;
	cin >> q;

	while (q--) {
		int p;
		char c;
		cin >> p >> c;

		p = teams - p;
		s[p] = c;

		while (p) {
			if (s[p] == '0')
				ans[p] = ans[2 * p + 1];
			else if (s[p] == '1')
				ans[p] = ans[2 * p];
			else
				ans[p] = ans[2 * p + 1] + ans[2 * p];

			p /= 2;
		}

		cout << ans[1] << '\n';
	}
}

int32_t main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
