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

	int n, m;
	cin >> n >> m;

	int cnt = 0, mn = min(n, m);

	for (int a = 0; a <= mn; ++a) {
		for (int b = 0; b <= mn; ++b) {

			int aa = a * a, bb = b * b;

			if ((aa + b == n) && (a + bb == m))
				++cnt;
		}
	}

	cout << cnt;
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
