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


void solve() {

	int n, l, x, y;
	cin >> n >> l >> x >> y;

	set<int> marks;

	int m;
	FOR (i, 0, n) {
		cin >> m;
		marks.insert(m);
	}

	bool measure_x = false, measure_y = false;

	FORALL (i, marks) {
		if (marks.count(i + x))
			measure_x = true;
		if (marks.count(i + y))
			measure_y = true;
	}

	if (measure_x && measure_y) {
		cout << 0;
		return;
	}

	if (measure_x) {
		cout << 1 << '\n' << y;
		return;
	}

	if (measure_y) {
		cout << 1 << '\n' << x;
		return;
	}

	FORALL (i, marks) {

		int mark = i + x;

		if (mark < l && (marks.count(mark - y) || marks.count(mark + y))) {
			cout << 1 << '\n' << mark;
			return;
		}

		mark = i - x;

		if (mark > 0 && (marks.count(mark - y) || marks.count(mark + y))) {
			cout << 1 << '\n' << mark;
			return;
		}

		mark = i + y;

		if (mark < l && (marks.count(mark - x) || marks.count(mark + x))) {
			cout << 1 << '\n' << mark;
			return;
		}

		mark = i - y;

		if (mark > 0 && (marks.count(mark - x) || marks.count(mark + x))) {
			cout << 1 << '\n' << mark;
			return;
		}
	}

	cout << 2 << '\n' << x << ' ' << y;
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
