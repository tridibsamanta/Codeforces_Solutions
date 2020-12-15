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

		int x;
		cin >> x;

		if (x < 10)
			cout << x << '\n';
		else {

			stack<int> num;

			for (int i = 9; i >= 1; --i) {

				if (x / i > 0) {
					num.push(i);
					x -= i;
				}

			}

			if (x != 0)
				cout << -1;
			else {
				while (!num.empty()) {
					cout << num.top();
					num.pop();
				}
			}

			cout << '\n';
		}
	}

	return 0;
}