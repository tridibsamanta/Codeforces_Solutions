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

int arr[200005];

int main() {

	FIO;

	w (tc) {

		int n;
		cin >> n;

		FOR(i, n) {
			cin >> arr[i];
		}

		ll ops = 0;

		for (int i = 1; i < n; ++i) {
			ops += abs(arr[i] - arr[i - 1]);
		}

		int max_ops = max(abs(arr[1] - arr[0]), abs(arr[n - 2] - arr[n - 1]));

		for (int i = 1; i < n - 1; ++i)
			max_ops = max(max_ops, abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i]) - abs(arr[i + 1] - arr[i - 1]));

		cout << ops - max_ops << '\n';
	}

	return 0;
}