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

		bool check[101];
		memset(check, false, sizeof(check));

		int count = 0;

		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			int no;
			cin >> no;

			check[no] = true;
		}

		for (int i = 0; i < m; ++i) {
			int no;
			cin >> no;

			if (check[no])
				++count;
		}

		cout << count << '\n';

	}

	return 0;
}