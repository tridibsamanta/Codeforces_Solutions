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

	int four = 0, one = 0;

	while (n > 0) {

		int d = n % 10;
		n /= 10;

		if (d != 1 && d != 4) {
			cout << "NO" << '\n';
			return 0;
		}

		if (d == 4) {
			if (++four > 2) {
				cout << "NO" << '\n';
				return 0;
			}
		}
		else {
			four = 0;
		}
	}

	if (four)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';

	return 0;
}