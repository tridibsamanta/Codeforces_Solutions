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

#define int                 long long
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


const int MAXN = 2 * 1e7 + 7;

vector<int> spf;

void SPF() {
	spf.clear();
	spf.resize(MAXN);

	iota(spf.begin(), spf.end(), 0);

	for (int i = 2; i * i < MAXN; ++i) {
		if (spf[i] == i) {
			for (int64_t j = int64_t(i) * i; j < MAXN; j += i) {
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

vi getDivisors(int x) {
	vi ans;

	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			int d1 = x / i;
			int d2 = i;

			ans.eb(d1);

			if (d1 != d2)
				ans.eb(d2);
		}
	}

	return ans;
}

int getCount(int c, int d, int r) {

	int m = r + d;

	if (m % c)
		return 0;

	r = m / c;

	int cnt = 0;

	while (spf[r] != 1) {
		++cnt;

		int val = spf[r];

		while (spf[r] == val)
			r /= spf[r];
	}

	return (1LL << cnt);
}

void solve() {

	int c, d, x;
	cin >> c >> d >> x;

	int ans = 0;

	vi div = getDivisors(x);

	FOR (i, 0, sz(div)) {
		ans += getCount(c, d, div[i]);
	}

	cout << ans;
}

int32_t main() {

	FIO;

	SPF();

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
