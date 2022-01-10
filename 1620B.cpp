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


void solve() {
	int w, h;
	cin >> w >> h;

	int c_x1;
	cin >> c_x1;

	vi x1(c_x1);

	FOR (i, 0, c_x1) {
		cin >> x1[i];
	}

	int c_x2;
	cin >> c_x2;

	vi x2(c_x2);

	FOR (i, 0, c_x2) {
		cin >> x2[i];
	}

	int c_y1;
	cin >> c_y1;

	vi y1(c_y1);

	FOR (i, 0, c_y1) {
		cin >> y1[i];
	}

	int c_y2;
	cin >> c_y2;

	vi y2(c_y2);

	FOR (i, 0, c_y2) {
		cin >> y2[i];
	}

	int x1_d1 = x1[c_x1 - 1] - x1[0];
	int x1_d2 = x2[c_x2 - 1] - x2[0];

	int area1 = max(x1_d1, x1_d2) * h;

	int y1_d1 = y1[c_y1 - 1] - y1[0];
	int y1_d2 = y2[c_y2 - 1] - y2[0];

	int area2 = max(y1_d1, y1_d2) * w;

	cout << max(area1, area2);
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
