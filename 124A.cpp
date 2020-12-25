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

	int n, a, b;
	cin >> n >> a >> b;

	int pos = n - max(a + 1, n - b) + 1;
	cout << pos;
}

int main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {

		solve();
		// cout << '\n';
	}

	return 0;
}
