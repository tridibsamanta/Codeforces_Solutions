/*
~ Author    : @tridib_2003
~ Title     : 1097B. Petr and a Combination Lock
~ Link      : https://codeforces.com/problemset/problem/1097/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int cnb = (1 << n) - 1;
	for (int i = 0; i < cnb; ++i) {

		int leftOver = 0;

		for (int j = 0; j < n; ++j) {
			if ((1 << j) & i)
				leftOver += arr[j];
			else
				leftOver -= arr[j];
		}

		if (leftOver % 360 == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}