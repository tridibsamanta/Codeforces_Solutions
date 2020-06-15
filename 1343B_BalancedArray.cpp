/*
 ~ Author    : @tridib_2003
 ~ Title     : 1343B. Balanced Array
 ~ Link      : https://codeforces.com/contest/1343/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		if ((n / 2) & 1) {
			cout << "NO\n";
			continue;
		}
		else {
			cout << "YES\n";
			for (int i = 1; i <= n / 2; ++i)
				cout << i * 2 << ' ';
			for (int i = 1; i < n / 2; ++i)
				cout << i * 2 - 1 << ' ';
		}
		cout << 2 * (n / 2) - 1 + (n / 2) << '\n';
	}

	return 0;
}