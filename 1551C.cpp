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
#define MOD                 1000000007 // 998244353
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


static bool cmp(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int getMaxWords(vpii curr_store) {

	sort(all(curr_store), cmp);

	int word_cnt = 0, curr_surplus = 0;

	FORALL (i, curr_store) {
		if (i.first > 0) {
			++word_cnt;
			curr_surplus += i.first;
		}
		else if (curr_surplus > i.second) {
			curr_surplus -= i.second;
			++word_cnt;
		}
		else
			break;
	}

	return word_cnt;
}

void solve() {

	int n;
	cin >> n;

	vpii a_store, b_store, c_store, d_store, e_store;

	int a_surplus = 0, b_surplus = 0, c_surplus = 0, d_surplus = 0, e_surplus = 0;

	FOR (i, 0, n) {
		string s;
		cin >> s;

		int a_cnt = 0, b_cnt = 0, c_cnt = 0, d_cnt = 0, e_cnt = 0;

		FOR (j, 0, sz(s)) {
			if (s[j] == 'a')
				++a_cnt;
			else if (s[j] == 'b')
				++b_cnt;
			else if (s[j] == 'c')
				++c_cnt;
			else if (s[j] == 'd')
				++d_cnt;
			else
				++e_cnt;
		}

		int total_cnt = a_cnt + b_cnt + c_cnt + d_cnt + e_cnt;

		int a_extra = (2 * a_cnt) - total_cnt;
		if (a_extra > 0)
			a_store.eb(mp(a_extra, 0));
		else
			a_store.eb(mp(0, abs(a_extra)));

		int b_extra = (2 * b_cnt) - total_cnt;
		if (b_extra > 0)
			b_store.eb(mp(b_extra, 0));
		else
			b_store.eb(mp(0, abs(b_extra)));

		int c_extra = (2 * c_cnt) - total_cnt;
		if (c_extra > 0)
			c_store.eb(mp(c_extra, 0));
		else
			c_store.eb(mp(0, abs(c_extra)));

		int d_extra = (2 * d_cnt) - total_cnt;
		if (d_extra > 0)
			d_store.eb(mp(d_extra, 0));
		else
			d_store.eb(mp(0, abs(d_extra)));

		int e_extra = (2 * e_cnt) - total_cnt;
		if (e_extra > 0)
			e_store.eb(mp(e_extra, 0));
		else
			e_store.eb(mp(0, abs(e_extra)));
	}

	// FORALL (i, d_store) {
	// 	cout << i.first << " -> " << i.second << '\n';
	// }

	int ans = 0;
	int maxWords = getMaxWords(a_store);
	ans = max(ans, maxWords);

	maxWords = getMaxWords(b_store);
	ans = max(ans, maxWords);

	maxWords = getMaxWords(c_store);
	ans = max(ans, maxWords);

	maxWords = getMaxWords(d_store);
	ans = max(ans, maxWords);

	maxWords = getMaxWords(e_store);
	ans = max(ans, maxWords);

	cout << ans;
}

int32_t main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
