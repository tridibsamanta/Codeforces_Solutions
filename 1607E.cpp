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

	string s;
	cin >> s;

	int dx = 0, dy = 0;
	int x_min = 0, x_max = 0, y_min = 0, y_max = 0;

	int i = 0;

	while (i < sz(s)) {
		if (s[i] == 'L')
			--dx;
		else if (s[i] == 'R')
			++dx;
		else if (s[i] == 'D')
			++dy;
		else
			--dy;

		int curr_x_min = min(x_min, dx);
		int curr_x_max = max(x_max, dx);

		int curr_y_min = min(y_min, dy);
		int curr_y_max = max(y_max, dy);

		if ((abs(curr_x_min) + curr_x_max + 1 > m) || (abs(curr_y_min) + curr_y_max + 1 > n)) {
			cout << abs(y_min) + 1 << ' ' << abs(x_min) + 1;
			return;
		}

		x_min = curr_x_min;
		x_max = curr_x_max;

		y_min = curr_y_min;
		y_max = curr_y_max;

		++i;
	}

	cout << abs(y_min) + 1 << ' ' << abs(x_min) + 1;
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
