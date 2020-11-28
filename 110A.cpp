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

	ll n;
	cin >> n;

	int luckyCount = 0;

	while (n != 0) {
		int digit = n % 10;
		if (digit == 4 || digit == 7)
			++luckyCount;
		n /= 10;
	}

	if (luckyCount == 4 || luckyCount == 7)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}