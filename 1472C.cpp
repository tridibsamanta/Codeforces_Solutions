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

	vi nums(n);

	FOR (i, n) {
		cin >> nums[i];
	}

	vi dp(n);

	FORREV (i, n) {

		dp[i] = nums[i];

		if ((i + nums[i]) < n) {
			dp[i] += dp[(i + nums[i])];
		}
	}

	cout << mx_all(dp);

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
