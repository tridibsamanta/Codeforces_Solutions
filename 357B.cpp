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

	int n, m;
	cin >> n >> m;

	vvi dance(m);

	int d1, d2, d3;
	FOR (i, 0, m) {
		cin >> d1 >> d2 >> d3;

		dance[i].eb(d1);
		dance[i].eb(d2);
		dance[i].eb(d3);
	}

	vi color(n + 1, 0); // 0 -> unassigned
	vb currColor;

	FOR (i, 0, m) {
		d1 = dance[i][0];
		d2 = dance[i][1];
		d3 = dance[i][2];

		currColor.clear();
		currColor.resize(4, false);

		if (color[d1] != 0)
			currColor[color[d1]] = true;
		else if (color[d2] != 0)
			currColor[color[d2]] = true;
		else if (color[d3] != 0)
			currColor[color[d3]] = true;

		if (color[d1] == 0) {
			if (!currColor[1]) {
				color[d1] = 1;
				currColor[1] = true;
			}
			else if (!currColor[2]) {
				color[d1] = 2;
				currColor[2] = true;
			}
			else if (!currColor[3]) {
				color[d1] = 3;
				currColor[3] = true;
			}
		}
		if (color[d2] == 0) {
			if (!currColor[1]) {
				color[d2] = 1;
				currColor[1] = true;
			}
			else if (!currColor[2]) {
				color[d2] = 2;
				currColor[2] = true;
			}
			else if (!currColor[3]) {
				color[d2] = 3;
				currColor[3] = true;
			}
		}
		if (color[d3] == 0) {
			if (!currColor[1]) {
				color[d3] = 1;
				currColor[1] = true;
			}
			else if (!currColor[2]) {
				color[d3] = 2;
				currColor[2] = true;
			}
			else if (!currColor[3]) {
				color[d3] = 3;
				currColor[3] = true;
			}
		}
	}

	FOR (i, 1, n + 1) {
		cout << color[i] << ' ';
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
