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

	w (tc) {

		int n;
		cin >> n;

		vi arr(n);

		FOR (i, n) {
			cin >> arr[i];
		}

		int new_size = unique(arr.begin(), arr.end()) - arr.begin();

		//arr.resize(new_size);

		vi freq(n + 1, 1);

		FOR (i, new_size) {
			freq[arr[i]]++;
		}

		freq[arr[0]]--;
		freq[arr[new_size - 1]]--;

		int res = INT_MAX;

		FOR (i, new_size) {
			res = min(res, freq[arr[i]]);
		}

		cout << res << '\n';
	}

	return 0;
}
