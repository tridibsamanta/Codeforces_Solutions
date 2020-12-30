/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull					unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define pb					push_back
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define all(c)				(c).begin(), (c).end()
#define sz(x)				(int)(x).size()
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int n, m;
	cin >> n >> m;

	vi pieces(m);

	FOR(i, m) {
		cin >> pieces[i];
	}

	sort(all(pieces));

	int minDiff = INT_MAX;

	for (int i = n - 1; i < m; ++i) {
		int currDiff = pieces[i] - pieces[i - n + 1];
		minDiff = min(minDiff, currDiff);
	}

	cout << minDiff;
}


int main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {

		solve();
		cout << '\n';
	}

	return 0;
}
