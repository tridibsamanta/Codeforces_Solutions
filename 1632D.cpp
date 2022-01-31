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


const int MAXN = 2e5 + 5;
const int EXP = 31;

int n;
vi arr;

int st[MAXN][EXP];
int logTable[MAXN];

void precomputeLog() {
	logTable[1] = 0;

	for (int i = 2; i < MAXN; i++)
		logTable[i] = logTable[i / 2] + 1;
}

int sparse_func(int a, int b) {
	return __gcd(a, b);
}

void precompute() {
	for (int i = 0; i < n; ++i)
		st[i][0] = arr[i];

	for (int j = 1; j < EXP; ++j) {
		for (int i = 0; i + (1 << j) <= n; ++i)
			st[i][j] = sparse_func(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
}

int query(int l, int r) {
	int j = logTable[r - l + 1];
	int gcdVal = __gcd(st[l][j], st[r - (1 << j) + 1][j]);
	return gcdVal;
}

void solve() {
	cin >> n;

	arr.clear();
	arr.resize(n);

	FOR (i, 0, n) {
		cin >> arr[i];
	}

	precompute();
	precomputeLog();

	vi ans;
	int lastChangeIdx = -1, cnt = 0;

	FOR (i, 0, n) {
		bool changeRequired = false;

		if (arr[i] == 1) {
			arr[i] = 1e9 + 7;
			changeRequired = true;
			lastChangeIdx = i;
			ans.eb(++cnt);
			continue;
		}
		else {
			int lo = lastChangeIdx + 1, hi = i;

			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;

				int subArrGcd = query(mid, i);
				int subArrLen = i - mid + 1;

				if (subArrGcd == subArrLen) {
					arr[i] = 1e9 + 7;
					changeRequired = true;
					lastChangeIdx = i;
					ans.eb(++cnt);
					break;
				}
				else {
					if (subArrGcd < subArrLen)
						lo = mid + 1;
					else if (subArrGcd > subArrLen)
						hi = mid - 1;
				}
			}
		}

		if (!changeRequired)
			ans.eb(cnt);
	}

	printall(ans);
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
