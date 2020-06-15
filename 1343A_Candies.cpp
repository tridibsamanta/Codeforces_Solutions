/*
 ~ Author    : @tridib_2003
 ~ Title     : 1343A. Candies
 ~ Link      : https://codeforces.com/contest/1343/problem/A
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

		for (int k = 2; k < 30; ++k) {

			int d = (1 << k) - 1;

			if (n % d == 0) {
				cout << n / d << '\n';
				break;
			}
		}
	}

	return 0;
}