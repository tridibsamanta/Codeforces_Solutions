/*
~ Author    : @tridib_2003
~ Title     : 1337B. Kana and Dragon Quest game
~ Link      : https://codeforces.com/contest/1337/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int x, n, m;
		cin >> x >> n >> m;

		int flag = 0;

		if (n == 0) {
			double rem = x / 10.0;
			(rem <= m) ? cout << "YES\n" : cout << "NO\n";
		}
		else if (m == 0)
			cout << "NO\n";
		else {
			for (int i = 1; i <= n; ++i) {

				double rem = x / 10.0;
				if (rem <= m) {
					++flag;
					break;
				}
				x = (x / 2) + 10;
				rem = x / 10.0;
				if (rem <= m) {
					++flag;
					break;
				}
			}
			(flag == 0) ? cout << "NO\n" : cout << "YES\n";
		}
	}
	return 0;
}