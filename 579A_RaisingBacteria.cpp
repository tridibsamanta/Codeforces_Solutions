/*
~ Author    : @tridib_2003
~ Title     : 579A. Raising Bacteria
~ Link      : https://codeforces.com/problemset/problem/579/A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x;
	cin >> x;

	int count = 0;

	while (x) {
		x = x & (x - 1);
		++count;
	}

	cout << count << '\n';

	return 0;
}