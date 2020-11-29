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

	for (int i = 0; i < n; ++i) {

		int rem = n - (i * 4);

		if (rem % 7 == 0 && rem >= 0) {

			for (int j = 0; j < i; ++j)
				cout << 4;

			for (int j = 0; j < rem / 7; ++j)
				cout << 7;

			return 0;
		}
	}

	cout << -1;

	return 0;
}