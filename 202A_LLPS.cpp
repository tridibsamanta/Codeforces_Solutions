/*
~ Author    : @tridib_2003
~ Title     : 202A. LLPS
~ Link      : https://codeforces.com/problemset/problem/202/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	char greatest = 'a';

	for (int i = 0; i < s.length(); ++i)
		if (s[i] > greatest)
			greatest = s[i];

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == greatest)
			cout << s[i];
	}

	return 0;
}