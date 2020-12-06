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

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		vector<int> count(n + 1, 0);
		vector<int> index(n + 1, -1);

		for (int i = 0; i < n; ++i) {

			int num;
			cin >> num;

			count[num]++;
			index[num] = i + 1;
		}

		int res = -1;

		for (int i = 1; i <= n; ++i) {
			if (count[i] == 1) {
				res = index[i];
				break;
			}
		}

		cout << res << '\n';

	}

	return 0;
}
