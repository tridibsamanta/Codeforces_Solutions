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

	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() != s2.length()) {
		cout << "NO" << '\n';
		return 0;
	}

	reverse(s1.begin(), s1.end());

	if (s1.compare(s2) != 0)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}