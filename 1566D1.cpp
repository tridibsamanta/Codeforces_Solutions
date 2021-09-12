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


struct FenwickTree {
	int n;
	vi arr;
	vi bit1, bit2;
	FenwickTree(int x) {
		n = x;
		arr.resize(n + 1, 0);
		bit1.resize(n + 1, 0);
		bit2.resize(n + 1, 0);
	}
	void update(bool flag, int i, int x) {
		for (; i <= n; i += (i & -i)) {
			(flag) ? bit2[i] += x : bit1[i] += x;
		}
	}
	void range_update(int l, int r, int x) {
		update(0, l, x);
		update(0, r + 1, -x);
		update(1, l, x * (l - 1));
		update(1, r + 1, -x * r);
	}
	int sum(bool flag, int i) {
		int ans = 0;
		for (; i > 0; i -= (i & -i))
			ans += (flag) ? bit2[i] : bit1[i];
		return ans;
	}
	int prefix_sum(int i) {
		return sum(0, i) * i - sum(1, i);
	}
	int range_sum(int l, int r) {
		return prefix_sum(r) - prefix_sum(l - 1);
	}
};

bool cmp(pii a, pii b) {
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}

void solve() {

	int n, m;
	cin >> n >> m;

	vpii arr(m);

	FOR (i, 0, m) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}

	sort(all(arr), cmp);

	FenwickTree fen(m);

	vi seat(m + 1, 0);

	FOR (i, 0, m) {
		seat[arr[i].second] = i + 1;
	}

	int ans = 0;

	FOR (i, 0, m) {
		int pos = seat[i + 1];
		ans += fen.range_sum(pos, pos);
		fen.range_update(pos, m, 1);
	}

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
