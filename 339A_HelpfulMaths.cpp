/*
 ~ Author    : @tridib_2003
 ~ Title     : 339A. Helpful Maths
 ~ Link      : https://codeforces.com/contest/339/problem/A
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

	string s;
	cin >> s;

	string ss;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '+')
			ss += s[i];
	}

	sort(ss.begin(), ss.end());

	int pos = -1;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '+')
			s[i] = ss[++pos];
	}

	cout << s << '\n';

	return 0;
}