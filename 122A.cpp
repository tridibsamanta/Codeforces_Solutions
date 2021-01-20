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

	int n;
	cin >> n;

	if (n % 4 == 0 || n == 4) {
		cout << "YES";
	}
	else if (n % 7 == 0 || n == 7) {
		cout << "YES";
	}
	else if (n % 47 == 0 || n == 47) {
		cout << "YES";
	}
	else if (n % 74 == 0 || n == 74) {
		cout << "YES";
	}
	else if (n % 447 == 0 || n == 447) {
		cout << "YES";
	}
	else if (n % 474 == 0 || n == 474) {
		cout << "YES";
	}
	else if (n % 477 == 0 || n == 477) {
		cout << "YES";
	}
	else if (n % 744 == 0 || n == 744) {
		cout << "YES";
	}
	else if (n % 747 == 0 || n == 747) {
		cout << "YES";
	}
	else if (n % 777 == 0 || n == 777) {
		cout << "YES";
	}
	else
		cout << "NO";

	cout << '\n';
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
