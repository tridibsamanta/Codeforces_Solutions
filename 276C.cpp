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
#define vll                 vector<long long>
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)         for (auto& (i) : (a))
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

bool cmp_pii(pii a, pii b) {
	if (a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

const int MAXN = 1e5 + 5;

void solve() {

	int n, q;
	cin >> n >> q;

	vi arr(n);

	FOR (i, 0, n) {
		cin >> arr[i];
	}

	rsort(arr);

	vpii queries, freq(n + 2);

	FOR (i, 0, n + 2) {
		freq[i].first = 0;
		freq[i].second = i;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		++(freq[l].first);
		--(freq[r + 1].first);

		queries.eb(mp(l, r));
	}

	freq.erase(freq.begin());

	FOR (i, 1, n + 1) {
		freq[i].first += freq[i - 1].first;
	}

	sort(all(freq), cmp_pii);

	vll pref(n + 1, 0);

	FOR (i, 0, n) {
		pref[freq[i].second] = arr[i];
	}

	FOR (i, 2, n + 1) {
		pref[i] += pref[i - 1];
	}

	ll res = 0;

	FORALL (i, queries) {
		int l = i.first;
		int r = i.second;

		res += (pref[r] - pref[l - 1]);
	}

	cout << res;
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
