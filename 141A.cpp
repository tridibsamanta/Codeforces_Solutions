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

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	if (str1.length() + str2.length() != str3.length()) {
		cout << "NO" << '\n';
		return 0;
	}

	unordered_map<char, int> freq;

	for (int i = 0; str1[i]; ++i)
		++freq[str1[i]];
	for (int i = 0; str2[i]; ++i)
		++freq[str2[i]];

	for (int i = 0; str3[i]; ++i) {
		if (--freq[str3[i]] < 0) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}