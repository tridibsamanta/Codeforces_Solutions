/*
~ Author    : @tridib_2003
~ Title     : 1326A. Bad Ugly Numbers
~ Link      : https://codeforces.com/contest/1326/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		if (n == 1)
			cout << "-1\n";
		else {
			cout << "2";
			for (int i = 0; i < n - 1; ++i)
				cout << "3";
			cout << '\n';
		}

	}

	return 0;
}