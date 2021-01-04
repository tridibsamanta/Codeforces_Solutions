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

	int n;
	cin >> n;

	int oneCnt = 0, twoCnt = 0;

	FOR (i, n) {
		int x;
		cin >> x;

		if (x == 1)
			++oneCnt;
		else
			++twoCnt;
	}

	if (oneCnt & 1) {
		cout << "NO";
		return;
	}

	int sum = (oneCnt * 1) + (twoCnt * 2);

	if (sum & 1) {
		cout << "NO";
		return;
	}

	if (((sum / 2) & 1) && oneCnt == 0) {
		cout << "NO";
		return;
	}

	if (oneCnt == 0) {
		if (twoCnt & 1)
			cout << "NO";
		else
			cout << "YES";
		return;
	}

	if (twoCnt == 0) {
		if (oneCnt & 1)
			cout << "NO";
		else
			cout << "YES";
		return;
	}

	if ((oneCnt % 2 == 0) && (twoCnt % 2 == 0)) {
		cout << "YES";
		return;
	}

	int share1 = sum / 2;
	int share2 = share1;

	while (share1 > 1 && twoCnt > 0) {
		share1 -= 2;
		--twoCnt;
	}

	while (share1 > 0 && oneCnt > 0) {
		share1 -= 1;
		--oneCnt;
	}

	if (share1 > 0) {
		cout << "NO";
		return;
	}

	while (share2 > 1 && twoCnt > 0) {
		share2 -= 2;
		--twoCnt;
	}

	while (share2 > 0 && oneCnt > 0) {
		share2 -= 1;
		--oneCnt;
	}

	if (share2 > 0) {
		cout << "NO";
		return;
	}

	if (twoCnt != 0 || oneCnt != 0) {
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
