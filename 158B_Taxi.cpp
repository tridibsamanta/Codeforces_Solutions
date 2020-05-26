/*
~ Author    : @tridib_2003
~ Title     : 158B. Taxi
~ Link      : https://codeforces.com/contest/158/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int ans = 0, count1 = 0, count2 = 0, count3 = 0;

	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] == 4)
			++ans;
		else if (arr[i] == 3)
			++count3;
		else if (arr[i] == 2)
			++count2;
		else
			++count1;
	}

	if (count3 >= count1) {
		ans += count3;
		count1 = 0;
	}
	if (count3 < count1) {
		ans += count3;
		count1 -= count3;
	}

	if (count2 & 1) {
		ans += count2 / 2;
		count2 = 1;
	}
	else {
		ans += count2 / 2;
		count2 = 0;
	}

	ans += count1 / 4;
	count1 %= 4;

	if (count2) {
		if (count1 <= 2) {
			++ans;
			count1 = 0;
		}
		else
			++ans;
	}

	if (count1)
		++ans;

	cout << ans << '\n';

	return 0;
}