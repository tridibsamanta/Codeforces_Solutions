/*
~ Author    : @tridib_2003
~ Title     : 1327A. Sum of Odd Integers
~ Link      : https://codeforces.com/contest/1327/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		ll n, k;
		cin >> n >> k;

		if (n >= k * k && (n & 1) == (k & 1))
			cout << "YES\n";

		else
			cout << "NO\n";

	}

	return 0;
}