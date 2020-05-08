/*
~ Author    : @tridib_2003
~ Title     : 1325B. CopyCopyCopyCopyCopy
~ Link      : https://codeforces.com/contest/1325/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		unordered_set<int> uset;

		int a[n];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			uset.insert(a[i]);
		}

		cout << uset.size() << '\n';

	}

	return 0;
}