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
	int n, a, b;
	cin >> n >> a >> b;

	if ((abs(a - b) > 1) || (a + b + 2 > n) || (a > (n - 1) / 2) || (b > (n - 1) / 2)) {
		cout << -1;
		return;
	}

	if (a > b) {
		int k = a * 2;
		int l = 1, h = n;

		FOR (i, 0, k) {
			if (i & 1) {
				cout << h-- << ' ';
			}
			else {
				cout << l++ << ' ';
			}
		}

		RFOR (i, h + 1, l) {
			cout << i << ' ';
		}
	}
	else if (b > a) {
		int k = b * 2;
		int l = 1, h = n;

		FOR (i, 0, k) {
			if (i & 1) {
				cout << l++ << ' ';
			}
			else {
				cout << h-- << ' ';
			}
		}

		FOR (i, l, h + 1) {
			cout << i << ' ';
		}
	}
	else {
		int k = a * 2 + 1;
		int l = 1, h = n;

		FOR (i, 0, k) {
			if (i & 1) {
				cout << l++ << ' ';
			}
			else {
				cout << h-- << ' ';
			}
		}

		RFOR (i, h + 1, l) {
			cout << i << ' ';
		}
	}
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
