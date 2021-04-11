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
#define FORALL(a,x)         for (auto& a : x)
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

	int n;
	cin >> n;

	n += 2;

	vi b(n);

	FOR (i, 0, n) {
		cin >> b[i];
	}

	sort(all(b));

	ll sum = 0;

	FOR (i, 0, n - 2) {
		sum += b[i];
	}

	if (sum == b[n - 1] || sum == b[n - 2]) {
		FOR (i, 0, n - 2) {
			cout << b[i] << ' ';
		}
		return;
	}

	sum += b[n - 2];

	int x_idx = -1;

	FOR (i, 0, n - 1) {
		if (sum - b[i] == b[n - 1]) {
			x_idx = i;
			break;
		}
	}

	if (x_idx == -1) {
		cout << -1;
		return;
	}

	FOR (i, 0, n - 1) {
		if (i != x_idx)
			cout << b[i] << ' ';
	}
}

int main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}