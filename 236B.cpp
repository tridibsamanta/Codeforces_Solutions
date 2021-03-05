/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1073741824
#define vi                  vector<int>
#define vvi                 vector<vector<int> >
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
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
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int divCount[1000005];

int getDivisorCount (int n) {

	int cnt = 0;

	for (int i = 1; i * i <= n; ++i) {

		if (n % i == 0) {

			if (i * i == n)
				++cnt;
			else
				cnt += 2;

		}
	}

	return cnt;
}

void solve() {

	int a, b, c;
	cin >> a >> b >> c;

	ll divSum = 0;

	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			for (int k = 1; k <= c; ++k) {

				int d = i * j * k;

				if (divCount[d] == 0)
					divCount[d] = getDivisorCount(d);

				divSum += divCount[d];
			}
		}
	}

	cout << divSum;
}



int main() {

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}
