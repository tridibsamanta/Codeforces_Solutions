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


const int MAXN = 1e5 + 5;

vector<bool> prime;
vector<int> primes;

void sieve(int maximum = MAXN) {
	maximum = max(maximum, 1);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes = {};

	for (int p = 2; p <= maximum; ++p) {
		if (prime[p]) {
			primes.push_back(p);

			for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
				prime[i] = false;
		}
	}
}

void solve() {

	sieve();

	int n, m;
	cin >> n >> m;

	vvi grid(n, vi (m));

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cin >> grid[i][j];
		}
	}

	int ans = INT_MAX;

	FOR (i, 0, n) {
		bool allPrime = true;
		int moves = 0;

		FOR (j, 0, m) {
			int p = *(lower_bound(all(primes), grid[i][j]));

			if (grid[i][j] != p)
				allPrime = false;

			moves += p - grid[i][j];
		}

		if (allPrime) {
			cout << 0;
			return;
		}

		ans = min(ans, moves);
	}

	FOR (i, 0, m) {
		bool allPrime = true;
		int moves = 0;

		FOR (j, 0, n) {
			int p = *(lower_bound(all(primes), grid[j][i]));

			if (grid[j][i] != p)
				allPrime = false;

			moves += p - grid[j][i];
		}

		if (allPrime) {
			cout << 0;
			return;
		}

		ans = min(ans, moves);
	}

	cout << ans;
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
