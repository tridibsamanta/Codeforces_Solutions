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

#define int                 long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007 // 998244353
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


const int MAXN = 1e4 + 1;

void solve() {
	int n;
	cin >> n;

	int sum = 0, sq_sum = 0;
	vi arr1(n);

	FOR (i, 0, n) {
		cin >> arr1[i];

		sum += arr1[i];
		sq_sum += (arr1[i] * arr1[i]);
	}

	vi arr2(n);

	FOR (i, 0, n) {
		cin >> arr2[i];

		sum += arr2[i];
		sq_sum += (arr2[i] * arr2[i]);
	}

	vector<vb> dp(n + 1, vb(MAXN, false));

	dp[0][0] = 1;

	FOR (i, 1, n + 1) {
		FOR (j, 1, MAXN) {
			dp[i][j] = (dp[i][j]) | ((j - arr1[i - 1] >= 0) ? dp[i - 1][j - arr1[i - 1]] : false);
			dp[i][j] = (dp[i][j]) | ((j - arr2[i - 1] >= 0) ? dp[i - 1][j - arr2[i - 1]] : false);
		}
	}

	int min_total = 2 * (MAXN * MAXN);

	FOR (j, 1, MAXN) {
		if (dp[n][j]) {
			int s1 = j;
			int s2 = sum - j;

			int total = (s1 * s1) + (s2 * s2);

			min_total = min(min_total, total);
		}
	}

	cout << ((n - 2) * sq_sum + min_total);
}

int32_t main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
