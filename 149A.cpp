/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {

	int k;
	cin >> k;

	if (k == 0) {
		cout << 0;
		return;
	}

	int arr[12];

	FOR (i, 12) {
		cin >> arr[i];
	}

	sort(arr, arr + 12, greater<int>());

	int height = 0;

	FOR (i, 12) {
		height += arr[i];

		if (height >= k) {
			cout << i + 1;
			return;
		}
	}

	cout << -1;
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
