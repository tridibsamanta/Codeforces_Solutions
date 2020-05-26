/*
~ Author    : @tridib_2003
~ Title     : 282A. Bit++
~ Link      : https://codeforces.com/contest/282/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int res = 0;

	while (n--) {

		string s;
		cin >> s;

		if (s[0] == '+' || s[1] == '+')
			++res;
		if (s[0] == '-' || s[1] == '-')
			--res;

	}

	cout << res << '\n';

	return 0;
}