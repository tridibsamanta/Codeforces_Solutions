/*
 ~ Author    : @tridib_2003
*/

#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 998244353 // 1000000007
#define vi                  vector<int>
#define vb                  vector<bool>
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
#define print(a)            cout << a << '\n'
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


bool isUpper(char c) {
	return (c >= 'A' && c <= 'Z');
}

void solve() {

	int n;
	cin >> n;

	vector<string> bad;

	string s, ls;
	FOR (i, 0, n) {
		cin >> s;

		ls = "";
		FOR (j, 0, sz(s)) {
			if (isUpper(s[j]))
				ls += (s[j] + 32);
			else
				ls += s[j];
		}

		bad.eb(ls);
	}

	string w, t = "";
	cin >> w;

	FOR (i, 0, sz(w)) {
		if (isUpper(w[i]))
			t += (w[i] + 32);
		else
			t += w[i];
	}

	char letter;
	cin >> letter;

	vpii range;

	FOR (i, 0, n) {
		int idx = t.find(bad[i]);

		while (idx != (string::npos)) {
			range.pb({idx, idx + sz(bad[i]) - 1});
			idx = t.find(bad[i], idx + 1);
		}
	}

	sort(all(range));

	int l = -1, r = -1;
	int prev_l = -1, prev_r = -1;

	FOR (i, 0, sz(range)) {
		l = range[i].first;
		r = range[i].second;

		if ((prev_l != -1) && (prev_r != -1) && (l >= prev_l && r <= prev_r))
			continue;

		if ((prev_l != -1) && (l <= prev_r))
			l = prev_r + 1;

		FOR (j, l, r + 1) {
			bool uppercase = false;

			if (isUpper(w[j]))
				uppercase = true;

			if (t[j] != letter) {
				w[j] = (uppercase ? letter - 32 : letter);
			}
			else {
				if (letter == 'a')
					w[j] = (uppercase ? 'B' : 'b');
				else
					w[j] = (uppercase ? 'A' : 'a');
			}
		}

		prev_l = l;
		prev_r = r;
	}

	cout << w;
}

int32_t main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
