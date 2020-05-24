/*
~ Author    : @tridib_2003
~ Title     : 467B. Fedor and New Game
~ Link      : https://codeforces.com/problemset/problem/467/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> army(m + 1);

	for (int i = 0; i < m + 1; ++i)
		cin >> army[i];

	int count = 0;

	for (int i = 0; i < m; ++i) {
		int diff = army[i] ^ army[m];
		if (__builtin_popcount(diff) <= k)
			++count;
	}

	cout << count << '\n';

	return 0;
}