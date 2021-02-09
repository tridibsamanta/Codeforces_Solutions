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
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int n;
	cin >> n;

	unordered_map<int, int> hm;

	FOR (i, 0, n) {
		int x;
		cin >> x;
		++hm[x];
	}

	n /= 3;

	if (hm[5] != 0 || hm[7] != 0 || hm[1] != n || hm[2] + hm[3] != n || hm[4] + hm[6] != n) {
		cout << -1;
		return;
	}

	if (hm[4] > 0) {
		if (hm[2] - hm[4] < 0) {
			cout << -1;
			return;
		}
		else {
			FOR (i, 0, hm[4]) {
				cout << "1 2 4" << '\n';
			}
			hm[2] -= hm[4];
		}
	}

	if (hm[6] > 0) {
		if (hm[2] + hm[3] != hm[6]) {
			cout << -1;
			return;
		}
		else {
			if (hm[2] > 0) {
				FOR (i, 0, hm[2]) {
					cout << "1 2 6" << '\n';
				}
			}
			if (hm[3] > 0) {
				FOR (i, 0, hm[3]) {
					cout << "1 3 6" << '\n';
				}
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
		cout << '\n';
	}

	return 0;
}