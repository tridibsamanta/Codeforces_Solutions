/*
~ Author    : @tridib_2003
~ Title     : 474B. Worms
~ Link      : https://codeforces.com/contest/474/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> worm_pile;

	int a;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		while (a--) {
			worm_pile.push_back(i);
		}
	}

	int m;
	cin >> m;

	int q;
	for (int i = 0; i < m; ++i) {
		cin >> q;
		cout << worm_pile[q - 1] << '\n';
	}

	return 0;
}