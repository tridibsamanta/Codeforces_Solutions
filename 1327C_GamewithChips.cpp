/*
~ Author    : @tridib_2003
~ Title     : 1327C. Game with Chips
~ Link      : https://codeforces.com/contest/1327/problem/C
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	k *= 2;

	while (k--) {
		int x, y;
		cin >> x >> y;
	}

	int moves = (n * m) + n + m - 3;
	cout << moves << '\n';

	for (int i = 1; i < n; ++i)
		cout << 'U';
	for (int i = 1; i < m; ++i)
		cout << 'L';

	for (int i = 0; i < n; ++i) {
		if (i & 1)
			for (int i = 1; i < m; ++i)
				cout << 'L';
		else
			for (int i = 1; i < m; ++i)
				cout << 'R';
		if (i < n - 1)
			cout << 'D';
	}

	cout << '\n';

	return 0;
}