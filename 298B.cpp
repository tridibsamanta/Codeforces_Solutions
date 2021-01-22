/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define pb                  push_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int t;
	cin >> t;

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;

	string s;
	cin >> s;

	char dir1, dir2;
	int cnt1 = 0, cnt2 = 0;

	if (ex - sx >= 0) {
		dir1 = 'E';
		cnt1 = ex - sx;
	}
	else {
		dir1 = 'W';
		cnt1 = abs(ex - sx);
	}

	if (ey - sy >= 0) {
		dir2 = 'N';
		cnt2 = ey - sy;
	}
	else {
		dir2 = 'S';
		cnt2 = abs(ey - sy);
	}

	int i = 0;

	while (i < t && (cnt1 > 0 || cnt2 > 0)) {

		if (s[i] == dir1 && cnt1 > 0)
			--cnt1;
		else if (s[i] == dir2 && cnt2 > 0)
			--cnt2;

		++i;
	}

	if (cnt1 == 0 && cnt2 == 0)
		cout << i;
	else
		cout << -1;
}

int main() {

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
