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

	vector<int> count(7);

	int total = 0, last = -1;

	FOR(i, 7) {
		cin >> count[i];
		total += count[i];

		if (count[i] > 0)
			last = i + 1;
	}

	n %= total;

	if (n == 0) {
		cout << last;
		return 0;
	}

	FOR(i, 7) {
		if (count[i] >= n) {
			cout << i + 1;
			break;
		}
		n -= count[i];
	}

	return 0;
}