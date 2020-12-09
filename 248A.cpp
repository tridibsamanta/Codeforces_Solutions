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

	int l_open = 0, l_close = 0, r_open = 0, r_close = 0;

	FOR(i, n) {
		int l, r;
		cin >> l >> r;

		l == 1 ? ++l_open : ++l_close;
		r == 1 ? ++r_open : ++r_close;
	}


	int time = min(l_close, l_open) + min(r_close, r_open);
	cout << time << '\n';

	return 0;
}