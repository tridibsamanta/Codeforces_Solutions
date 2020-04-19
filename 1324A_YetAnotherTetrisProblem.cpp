/*
~ Author    : @tridib_2003
~ Title     : 1324A. Yet Another Tetris Problem
~ Link      : https://codeforces.com/contest/1324/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		//No. of columns
		int n;
		cin >> n;

		int even_count = 0, odd_count = 0;

		//Array which stores height of each column
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] % 2 == 0)
				++even_count;
			else
				++odd_count;
		}

		((even_count > 0 && odd_count == 0) || (odd_count > 0 && even_count == 0)) ? cout << "YES\n" : cout << "NO\n";

	}
	return 0;
}