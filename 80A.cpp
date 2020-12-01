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

	int n, m;
	cin >> n >> m;

	n = n + 1;

	while (n <= m) {

		bool isPrime = true;

		for (int i = 2; i <= sqrt(n); ++i) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			if (n == m) {
				cout << "YES";
				return 0;
			}
			else {
				cout << "NO";
				return 0;
			}
		}

		++n;
	}

	cout << "NO";

	return 0;
}