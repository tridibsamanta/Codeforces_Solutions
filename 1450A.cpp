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

		string a;
		cin >> a;

		int count = 0;

		for (int i = 0; a[i]; ++i) {
			if (a[i] == 't')
				++count;
		}

		if (count == 0)
			cout << a << '\n';
		else {
			string res = "";
			for (int i = 0; a[i]; ++i) {
				if (a[i] != 't')
					res += a[i];
			}
			while (count--) {
				res += 't';
			}
			cout << res << '\n';
		}
	}

	return 0;
}