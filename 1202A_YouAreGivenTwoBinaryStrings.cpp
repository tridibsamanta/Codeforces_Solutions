/*
~ Author    : @tridib_2003
~ Title     : 1202A. You Are Given Two Binary Strings
~ Link      : https://codeforces.com/problemset/problem/1202/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		string x, y;
		cin >> x >> y;

		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());

		int idx_y = y.find_first_of('1', 0);
		int idx_x = x.find_first_of('1', idx_y);

		cout << idx_x - idx_y << '\n';

	}

	return 0;
}