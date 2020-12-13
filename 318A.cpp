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

	ll n, k;
	cin >> n >> k;

	ll even_pos = (n / 2) + 1;

	if (n & 1)
		++even_pos;

	if (k < even_pos) {
		ll num = -1;
		while (k--) {
			num += 2;
		}
		cout << num;
	}
	else {
		ll num = 0;
		k -= (even_pos - 1);
		while (k--) {
			num += 2;
		}
		cout << num;
	}

	return 0;
}