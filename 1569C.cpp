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


const int MAXN = 2e5 + 5;

int fact[MAXN];
int invFact[MAXN];
int ans;

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
	for (; i < MAXN; ++i)
		fact[i] = (i * 1LL * fact[i - 1]) % MOD;
	--i;
	invFact[i] = mod_exp(fact[i], MOD - 2, MOD);
	for (--i; i >= 0; --i)
		invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % MOD;
}

int ncr(int n, int r) {
	if (r > n || n < 0 || r < 0)
		return 0;
	return (((fact[n] * 1LL * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void removeNotNicePermuations(int n, int sFreq) {

	FOR (i, 1, n + 1) {
		if (i - 1 < sFreq)
			continue;

		int cnt = (((ncr(i - 1, sFreq) * fact[sFreq]) % MOD) * fact[n - sFreq - 1]) % MOD;
		ans -= cnt;

		if (ans < 0)
			ans += MOD;
	}
}

void solve() {

	int n;
	cin >> n;

	vi arr(n);

	int maxEle = -1, secondMaxEle = -1;
	int maxFreq = 0, secondMaxFreq = 0;

	FORALL (i, arr) {
		cin >> i;

		if (i > maxEle) {
			secondMaxEle = maxEle;
			maxEle = i;
		}
		else if (i > secondMaxEle)
			secondMaxEle = i;
	}

	FORALL (i, arr) {
		if (i == maxEle)
			++maxFreq;
		else if (i == secondMaxEle)
			++secondMaxFreq;
	}

	if (maxFreq >= 2) {
		cout << fact[n];
		return;
	}

	if (maxEle - secondMaxEle > 1) {
		cout << 0;
		return;
	}

	ans = fact[n];

	removeNotNicePermuations(n, secondMaxFreq);

	cout << ans;
}

int32_t main() {

	FIO;

	compute();

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
