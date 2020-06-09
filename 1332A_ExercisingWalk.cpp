/*
~ Author    : @tridib_2003
~ Title     : 1332A. Exercising Walk
~ Link      : https://codeforces.com/contest/1332/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int l, r, d, u;
		cin >> l >> r >> d >> u;

		int x, y, xl, yd, xr, yu;
		cin >> x >> y >> xl >> yd >> xr >> yu;

		if (r - l > xr - x || l - r > x - xl)
			cout << "No\n";
		else if (u - d > yu - y || d - u > y - yd)
			cout << "No\n";
		else if ((xl == xr) && (l + r) > 0)
			cout << "No\n";
		else if ((yd == yu) && (d + u) > 0)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}