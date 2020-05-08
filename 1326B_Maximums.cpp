/*
~ Author    : @tridib_2003
~ Title     : 1326B. Maximums
~ Link      : https://codeforces.com/contest/1326/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int b, x = 0;

	for (int i = 0; i < n; ++i) {
		cin >> b;
		b += x;
		cout << b << ' ';
		x = max(x, b);
	}

	return 0;
}