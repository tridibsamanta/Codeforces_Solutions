/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define vvi                 vector<vector<int> >
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int n;
	cin >> n;

	vpii res;

	for (int i = 3; i < n; ++i) {
		if (i != 4 && i != 16) {
			res.eb(mp(i, i + 1));
		}
	}

	if (n > 16) {

		int val = n;

		while (val > 1) {
			res.eb(mp(n, 16));
			val = (val + 15) / 16;
		}
	}

	if (n >= 16) {
		res.eb(mp(16, 4));
		res.eb(mp(16, 4));
	}
	else {

		int val = n;

		while (val > 1) {
			res.eb(mp(n, 2));
			val = (val + 1) / 2;
		}

	}

	if (n > 4) {
		res.eb(mp(4, 2));
		res.eb(mp(4, 2));
	}

	cout << sz(res) << '\n';

	for (auto itr : res) {
		cout << itr.first << ' ' << itr.second << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
