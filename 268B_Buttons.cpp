/*
~ Author    : @tridib_2003
~ Title     : 268B. Buttons
~ Link      : https://codeforces.com/contest/268/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	ll pushes = n;

	for (int i = 1; i < n; ++i)
		pushes += i * (n - i);

	cout << pushes;

	return 0;
}