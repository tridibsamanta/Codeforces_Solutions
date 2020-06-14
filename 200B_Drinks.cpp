/*
~ Author    : @tridib_2003
~ Title     : 200B. Drinks
~ Link      : https://codeforces.com/contest/200/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	double pi, total_pi = 0;

	for (int i = 0; i < n; ++i) {
		cin >> pi;
		total_pi += pi;
	}

	double res = total_pi / n;

	cout << res;

	return 0;
}