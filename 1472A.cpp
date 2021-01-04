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
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define FORREV(a, c)        for (int(a) = ((c) - 1); (a) >= 0; (a)--)
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int w, h, n;
	cin >> w >> h >> n;

	if (n == 1) {
		cout << "YES";
		return;
	}

	if ((w & 1) && (h & 1)) {
		cout << "NO";
		return;
	}

	int cnt = 0;

	while (w % 2 == 0) {
		++cnt;
		w /= 2;
	}

	while (h % 2 == 0) {
		++cnt;
		h /= 2;
	}

	int total = pow(2, cnt);

	if (total >= n)
		cout << "YES";
	else
		cout << "NO";
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
