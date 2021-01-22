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
#define pb                  push_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
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

	vi arr(n);

	FOR (i, 0, n) {
		cin >> arr[i];
	}

	map<int, vector<int> > mp;

	FOR (i, 0, n) {
		mp[arr[i]].emplace_back(i + 1);
	}

	vector<pair<bool, pair<int, int> > > ap;
	bool isPresent = false;

	for (auto i : mp) {

		int m = sz(i.second);

		if (m == 1) {
			ap.pb(mp(true, mp(i.first, 0)));
			isPresent = true;
		}
		else if (m == 2) {
			ap.pb(mp(true, mp(i.first, i.second[1] - i.second[0])));
			isPresent = true;
		}
		else if (m > 2) {

			int diff = i.second[1] - i.second[0];
			bool isAP = true;

			for (int j = 1; j < m - 1; ++j) {
				if (i.second[j + 1] - i.second[j] != diff) {
					isAP = false;
					break;
				}
			}

			if (isAP) {
				ap.pb(mp(true, mp(i.first, diff)));
				isPresent = true;
			}
		}
	}

	if (!isPresent) {
		cout << 0 << '\n';
	}
	else {

		int m = sz(ap);
		cout << m << '\n';

		FOR (i, 0, m) {
			if (ap[i].first) {
				cout << ap[i].second.first << ' ' << ap[i].second.second << '\n';
			}
		}
	}

}

int main() {

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
