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

		string str;
		cin >> str;

		bool is2020 = false;

		if (str[0] == '2') {

			if (str[1] == '0' && str[2] == '2' && str[3] == '0')
				is2020 = true;
			else if (str[1] == '0' && str[2] == '2' && str[n - 1] == '0')
				is2020 = true;
			else if (str[1] == '0' && str[n - 2] == '2' && str[n - 1] == '0')
				is2020 = true;
			else if (str[n - 3] == '0' && str[n - 2] == '2' && str[n - 1] == '0')
				is2020 = true;
		}
		else if (str[n - 4] == '2' && str[n - 3] == '0' && str[n - 2] == '2' && str[n - 1] == '0')
			is2020 = true;

		if (is2020)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}