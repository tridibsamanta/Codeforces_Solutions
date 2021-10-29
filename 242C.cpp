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


static int row8D[] = { -1, -1, -1, 0, 0, 1, 1, 1};
static int col8D[] = { -1, 0, 1, -1, 1, -1, 0, 1};

void solve() {

	int x0, y0, x1, y1, n;
	cin >> x0 >> y0 >> x1 >> y1 >> n;

	set<pii> cell;

	int r, a, b;
	FOR (i, 0, n) {
		cin >> r >> a >> b;

		FOR (j, a, b + 1) {
			cell.insert({r, j});
		}
	}

	queue<pair<int, pair<int, int>>> q; // {dist, {row, col}}
	q.push({0, {x0, y0}});

	while (!q.empty()) {

		pair<int, pii> curr = q.front();
		q.pop();

		int curr_x = curr.second.first;
		int curr_y = curr.second.second;
		int curr_d = curr.first;

		FOR (i, 0, 8) {
			int adj_x = curr_x + row8D[i];
			int adj_y = curr_y + col8D[i];

			if (cell.count({adj_x, adj_y})) {

				if (adj_x == x1 && adj_y == y1) {
					cout << curr_d + 1;
					return;
				}

				q.push({curr_d + 1, {adj_x, adj_y}});
				cell.erase({adj_x, adj_y});
			}
		}
	}

	cout << -1;
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
