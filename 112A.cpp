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

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; str1[i]; ++i) {

		if (toupper(str1[i]) != toupper(str2[i])) {

			if (toupper(str1[i]) < toupper(str2[i])) {
				cout << -1;
				return 0;
			}
			else {
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}