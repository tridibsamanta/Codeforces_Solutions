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

	int x = 0, y = 0, z = 0;

	while (n--) {

		int val;
		cin >> val;

		x += val;

		cin >> val;
		y += val;

		cin >> val;
		z += val;

	}

	if (x != 0 || y != 0 || z != 0)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';

	return 0;
}