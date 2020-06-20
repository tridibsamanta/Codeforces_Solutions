/*
 ~ Author    : @tridib_2003
 ~ Title     : 266A. Stones on the Table
 ~ Link      : https://codeforces.com/contest/266/problem/A
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

	int tc = 1;
	//cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		string s;
		cin >> s;

		int moves = 0;

		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == s[i + 1])
				++moves;
		}

		cout << moves << '\n';

	}

	return 0;
}