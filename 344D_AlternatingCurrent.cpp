/*
~ Author    : @tridib_2003
~ Title     : 344D. Alternating Current
~ Link      : https://codeforces.com/problemset/problem/344/D
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	stack<char> check;

	for (int i = 0; i < s.length(); ++i) {
		if (check.empty())
			check.push(s[i]);
		else {
			if (s[i] == check.top())
				check.pop();
			else
				check.push(s[i]);
		}
	}

	cout << (check.empty() ? "Yes" : "No") << '\n';

	return 0;
}