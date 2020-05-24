/*
~ Author    : @tridib_2003
~ Title     : 1327B. Princesses and Princes
~ Link      : https://codeforces.com/contest/1327/problem/B
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

		vector<bool> prince(n + 1, 0);
		int unmarried = 0;

		for (int i = 1; i <= n; ++i) {

			int k;
			cin >> k;

			int married = 0;

			for (int j = 1; j <= k; ++j) {

				int p;
				cin >> p;

				if (married)
					continue;

				if (prince[p])
					continue;

				prince[p] = 1;
				married = 1;

			}

			if (!married)
				unmarried = i;


		}

		if (!unmarried)
			cout << "OPTIMAL\n";
		else {
			cout << "IMPROVE\n";
			cout << unmarried << ' ';

			for (int i = 1; i <= n; ++i)
				if (!prince[i]) {
					cout << i << '\n';
					break;
				}
		}

	}

	return 0;
}