/*
~ Author    : @tridib_2003
~ Title     : 535B. Tavas and SaDDas
~ Link      : https://codeforces.com/problemset/problem/535/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int len = 0, ans = 0;

	while (n) {
		if (n % 10 == 7)
			ans += (1 << len);
		n /= 10;
		++len;
	}

	for (int i = 1; i < len; ++i)
		ans += (1 << i);

	cout << ans + 1 << '\n';

	return 0;
}