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

/*
Observation:

	1.	The minimum height at which a box having width 'w' can be dropped
		is the height of the w'th stair. Let's call it 'min_h'.

		The reason behind this is let's say at the current stair we are
		able to drop a box having width <= 'w', then as we move over to the
		next stair we are basically expanding the available width by 1.
		Hence we can drop a box having width (w+1) in the next stair.

	2.	What happens if some part of a box is already at 'min_h'.
		Well, in this case we have no other option but to place the current box
		at the top of the most recently dropped box 'top_h'.
		And its obvious that the height 'top_h' is > 'min_h'.

Conclusion:

	1.	Height at which the base of the current box lands is
		= max(The minimum height at which the current box can be dropped,
			  The top height of the most recently dropped box)

		i.e. max(min_h, top_h)
*/

void solve() {

	int n;
	cin >> n;

	vi stair(n);

	FORALL (i, stair) {
		cin >> i;
	}

	int m, w, h;
	cin >> m;

	ll top_h = 0;

	FOR (i, 0, m) {

		cin >> w >> h;

		ll min_h = stair[w - 1];

		top_h = max(min_h, top_h);
		cout << top_h  << '\n';

		top_h += h;
	}
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
