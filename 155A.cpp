/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;

	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	int first;
	cin >> first;

	int min_points = first, max_points = first, cnt = 0;

	--n;
	FOR(i, n) {

		int point;
		cin >> point;

		if (point < min_points) {
			++cnt;
			min_points = point;
		}
		else if (point > max_points) {
			++cnt;
			max_points = point;
		}
	}

	cout << cnt << '\n';

	return 0;
}