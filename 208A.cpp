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

	string str;
	cin >> str;

	int n = str.length();

	if (n <= 3) {
		cout << str;
		return;
	}

	string res = "";
	int i = 0;

	while (i < n) {

		if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') {
			res += '#';
			i += 3;
		}
		else {
			res += str[i];
			++i;
		}
	}

	i = 0;
	int m = res.length();
	string song = "";

	while (i < m) {

		if (res[i] != '#') {
			song += res[i];
			++i;
		}
		else {
			while (res[i] == '#' && i < m) {
				++i;
			}

			if (song.size() != 0)
				song += ' ';
		}
	}

	if (song[song.size() - 1] == ' ')
		song.pop_back();

	cout << song;
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
