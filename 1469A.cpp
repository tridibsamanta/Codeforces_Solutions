/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull					unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define pb					push_back
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define all(c)				(c).begin(), (c).end()
#define sz(x)				(int)(x).size()
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	string s;
	cin >> s;

	if (s.length() & 1 || s[0] == ')' || s[s.length() - 1] == '(') {
		cout << "NO";
		return;
	}

	cout << "YES";
}

int main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {

		solve();
		cout << '\n';
	}

	return 0;
}
