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

void solve() {

	int k;
	cin >> k;

	string s;
	cin >> s;

	map<char, int> mp;

	for (int i = 0; s[i]; ++i) {
		mp[s[i]]++;
	}

	string str = "";

	for (auto i : mp) {
		if (i.second % k != 0) {
			cout << -1;
			return;
		}
		else {
			str.append(i.second / k, i.first);
		}
	}

	FOR (i, k) {
		cout << str;
	}
}

int main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {

		solve();
		// cout << '\n';
	}

	return 0;
}
