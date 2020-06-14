/*
~ Author    : @tridib_2003
~ Title     : 588B. Duff in Love
~ Link      : https://codeforces.com/contest/588/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	ll x = n, res = 1;

	for (ll i = 2; i <= sqrt(n); ++i) {
		if (x % i == 0) {
			res *= i;
			while (x % i == 0)
				x /= i;
		}
	}

	if (x > 1)
		res *= x;

	cout << res;

	return 0;
}