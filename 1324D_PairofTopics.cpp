/*
~ Author    : @tridib_2003
~ Title     : 1324D. Pair of Topics
~ Link      : https://codeforces.com/contest/1324/problem/D
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		c[i] = a[i] - b[i];
	}

	sort(c.begin(), c.end());

	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		if (c[i] <= 0)
			continue;
		int pos = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
		ans += i - pos;
	}

	cout << ans << "\n";

	return 0;
}