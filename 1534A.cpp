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
#define MOD                 1000000007
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

	vector<string> grid(n);

	FOR (i, 0, n) {
		string s = "";

		FOR (j, 0, m) {
			char c;
			cin >> c;

			s.pb(c);
		}

		grid[i] = s;
	}

	// construct the first possible answer grid
	vector<string> grid1(n);

	FOR (i, 0, n) {
		string s = "";

		if (i & 1) {
			FOR (j, 0, m) {
				if (j & 1)
					s.pb('R');
				else
					s.pb('W');
			}
		}
		else {
			FOR (j, 0, m) {
				if (j & 1)
					s.pb('W');
				else
					s.pb('R');
			}
		}

		grid1[i] = s;
	}

	// construct the second possible answer grid
	vector<string> grid2(n);

	FOR (i, 0, n) {
		string s = "";

		if (i & 1) {
			FOR (j, 0, m) {
				if (j & 1)
					s.pb('W');
				else
					s.pb('R');
			}
		}
		else {
			FOR (j, 0, m) {
				if (j & 1)
					s.pb('R');
				else
					s.pb('W');
			}
		}

		grid2[i] = s;
	}

	// try to match the given grid with any one of the two answer grids
	bool check1 = true, check2 = true;

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] != '.') {
				if (grid[i][j] != grid1[i][j]) {
					check1 = false;
					break;
				}
			}
		}

		if (!check1)
			break;
	}

	if (check1) {
		cout << "YES" << '\n';

		FOR (i, 0, n) {
			FOR (j, 0, m) {
				cout << grid1[i][j];
			}
			cout << '\n';
		}

		return;
	}

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] != '.') {
				if (grid[i][j] != grid2[i][j]) {
					check2 = false;
					break;
				}
			}
		}

		if (!check2)
			break;
	}

	if (!check2) {
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout << grid2[i][j];
		}
		cout << '\n';
	}
}

int32_t main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
