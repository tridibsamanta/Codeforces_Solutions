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


static int dp[21][21];

int lcsubstr(string a, string b, int m, int n) {

	FOR (i, 0, m) {
		dp[i][0] = 0;
	}

	FOR (i, 0, n) {
		dp[0][i] = 0;
	}

	int maxLen = 0;

	FOR (i, 1, m + 1) {
		FOR (j, 1, n + 1) {

			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				maxLen = max(maxLen, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	return maxLen;
}

void solve() {

	string a, b;
	cin >> a >> b;

	if (a.compare(b) == 0) {
		cout << 0;
		return;
	}

	int m = sz(a), n = sz(b);

	int commonStrLen = lcsubstr(a, b, m, n);

	cout << (m - commonStrLen) + (n - commonStrLen);
}


int main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}