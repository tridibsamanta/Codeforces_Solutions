/*
~ Author    : @tridib_2003
~ Title     : 467A. George and Accommodation
~ Link      : https://codeforces.com/contest/467/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int p, q, count = 0;
	for (int i = 0; i < n; ++i) {
		cin >> p >> q;
		if ((q - p) >= 2)
			++count;
	}

	cout << count << '\n';

	return 0;
}