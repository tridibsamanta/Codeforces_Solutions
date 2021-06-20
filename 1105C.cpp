/*
 ~ Author    : @tridib_2003
*/

#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define vb                  vector<bool>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)        for (auto& (i) : (a))
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
#define print(a)            cout << a << '\n'
#define rsort(a)            sort((a).rbegin(), (a).rend())
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define max3(a, b, c)       max((a), max((b), (c)))
#define min3(a, b, c)       min((a), min((b), (c)))
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


const int MAXN = 2 * 1e5 + 5;

// dp[i][j] denotes the number of ways to restore array of size i
// such that (sum of i elements) % 3 is equal to j
ll dp[MAXN][3];

void solve() {

	int n, l, r;
	cin >> n >> l >> r;

	int total = r - l + 1;
	int n0, n1, n2;

	n0 = n1 = n2 = (total / 3);

	if (total % 3 == 1) {
		if (r % 3 == 0)
			++n0;
		else if (r % 3 == 1)
			++n1;
		else
			++n2;
	}
	else if (total % 3 == 2) {
		if (r % 3 == 0)
			++n0;
		else if (r % 3 == 1)
			++n1;
		else
			++n2;

		if ((r - 1) % 3 == 0)
			++n0;
		else if ((r - 1) % 3 == 1)
			++n1;
		else
			++n2;
	}

	memset(dp, 0, sizeof(dp));

	dp[1][0] = n0;
	dp[1][1] = n1;
	dp[1][2] = n2;

	FOR (i, 2, n + 1) {
		dp[i][0] = (((dp[i - 1][0] * n0) % MOD) +
		            ((dp[i - 1][1] * n2) % MOD) +
		            ((dp[i - 1][2] * n1) % MOD)) % MOD;

		dp[i][1] = (((dp[i - 1][0] * n1) % MOD) +
		            ((dp[i - 1][1] * n0) % MOD) +
		            ((dp[i - 1][2] * n2) % MOD)) % MOD;

		dp[i][2] = (((dp[i - 1][0] * n2) % MOD) +
		            ((dp[i - 1][1] * n1) % MOD) +
		            ((dp[i - 1][2] * n0) % MOD)) % MOD;
	}

	cout << dp[n][0];
}

int32_t main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
