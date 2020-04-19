/*
~ Author    : @tridib_2003
~ Title     : 1324B. Yet Another Palindrome Problem
~ Link      : https://codeforces.com/contest/1324/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int first_occ_index[5001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		memset(first_occ_index, -1, sizeof(first_occ_index) + 4);
		bool check = false;

		for (int i = 0, a; i < n; ++i) {
			cin >> a;

			if (first_occ_index[a] < 0)
				first_occ_index[a] = i;
			else {
				if (first_occ_index[a] < i - 1)
					check = true;
			}
		}
		cout << (check ? "YES" : "NO") << '\n';

	}
	return 0;
}