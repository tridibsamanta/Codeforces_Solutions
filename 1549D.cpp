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
#define MOD                 998244353 // 1000000007
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


const int INF = 1e9 + 7;

const int MAXN = 2 * 1e5 + 5;
const int EXP = 18;

int st[MAXN][EXP];
int logTable[MAXN];

int n;
int diff[MAXN];

long long gcd(long long _a, long long _b) {
	return (_b == 0) ? _a : gcd(_b, _a % _b);
}

void precomputeLog() {
	logTable[1] = 0;

	for (int i = 2; i <= MAXN; ++i)
		logTable[i] = logTable[i / 2] + 1;
}

void precompute() {
	for (int i = 0; i < n; ++i)
		st[i][0] = diff[i];

	for (int j = 1; j <= EXP; ++j) {
		for (int i = 0; i + (1 << j) <= n; ++i)
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
}

int query(int l, int r) {
	int j = logTable[r - l + 1];
	int range_gcd = gcd(st[l][j], st[r - (1 << j) + 1][j]);
	return range_gcd;
}

void solve() {

	cin >> n;

	vi arr(n);

	FOR (i, 0, n) {
		cin >> arr[i];
	}

	memset(diff, 0, sizeof(diff));

	FOR (i, 0, n - 1) {
		diff[i] = abs(arr[i + 1] - arr[i]);
	}

	precompute();

	int maxLen = 1, r_idx = 0;

	FOR (i, 0, n - 1) {

		r_idx = max(i, r_idx);

		while (r_idx < n - 1 && query(i, r_idx) >= 2)
			++r_idx;

		maxLen = max(maxLen, r_idx - i + 1);
	}

	cout << maxLen;
}

int32_t main() {

	FIO;

	precomputeLog();

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
