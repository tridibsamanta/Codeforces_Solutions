/*
~ Author    : @tridib_2003
~ Title     : 96A. Football
~ Link      : https://codeforces.com/contest/96/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int len = s.length();

	int prev = s[0] - '0', chain = 1;

	for (int i = 1; i < len; ++i) {

		if (s[i] - '0' == prev)
			++chain;
		else
			chain = 1;

		if (chain == 7)
			break;

		prev = s[i] - '0';
	}

	cout << (chain == 7 ? "YES" : "NO") << '\n';

	return 0;
}