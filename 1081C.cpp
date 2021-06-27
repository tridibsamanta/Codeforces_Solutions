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


const int MAXN = 2002;

int fact[MAXN];
int invFact[MAXN];

int mod_exp(int a, int p, int m = MOD) {
	int res = 1;
	while (p > 0) {
		if (p & 1)
			res = (a * 1LL * res) % m;
		a = (a * 1LL * a) % m;
		p >>= 1;
	}
	return res;
}

void compute() {
	fact[0] = 1;

	int i = 1;
	for (; i < MAXN; ++i) {
		fact[i] = (i * 1LL * fact[i - 1]) % MOD;
	}

	--i;

	invFact[i] = mod_exp(fact[i], MOD - 2, MOD);

	for (--i; i >= 0; --i) {
		invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % MOD;
	}
}

int ncr(int n, int r) {
	if (r > n || n < 0 || r < 0)
		return 0;

	return (((fact[n] * 1LL * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	compute();

	// no. of ways we can place k bars
	int cnt1 = ncr(n - 1, k);

	// no. of ways to fill colors in k+1 segments
	int cnt2 = (m * 1LL * mod_exp(m - 1, k)) % MOD;

	int res = (cnt1 * 1LL * cnt2) % MOD;
	cout << res;
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
