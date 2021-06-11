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


vi smallest_factor;
vb prime;
vi primes;

void sieve(int maximum) {
	maximum = max(maximum, 1);
	smallest_factor.assign(maximum + 1, 0);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes = {};

	for (int p = 2; p <= maximum; p++)
		if (prime[p]) {
			smallest_factor[p] = p;
			primes.push_back(p);

			for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
				if (prime[i]) {
					prime[i] = false;
					smallest_factor[i] = p;
				}
		}
}

vector<pair<int64_t, int>> prime_factorize(int64_t n) {
	int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
	// assert(1 <= n && n <= sieve_max * sieve_max);
	vector<pair<int64_t, int>> result;

	if (n <= sieve_max) {
		while (n != 1) {
			int64_t p = smallest_factor[n];
			int exponent = 0;

			do {
				n /= p;
				exponent++;
			} while (n % p == 0);

			result.emplace_back(p, exponent);
		}

		return result;
	}

	for (int64_t p : primes) {
		if (p * p > n)
			break;

		if (n % p == 0) {
			result.emplace_back(p, 0);

			do {
				n /= p;
				result.back().second++;
			} while (n % p == 0);
		}
	}

	if (n > 1)
		result.emplace_back(n, 1);

	return result;
}

int getPrimeExponentCount(int n) {
	vector<pair<int64_t, int>> prime_factors = prime_factorize(n);
	int sum = 0;

	for (auto &pf : prime_factors)
		sum += pf.second;

	return sum;
}

void solve() {

	int a, b, k;
	cin >> a >> b >> k;

	if (a == b && k == 1) {
		cout << "NO";
		return;
	}

	int G = __gcd(a, b);
	int mn_ops = (a > G) + (b > G);

	if (k < mn_ops) {
		cout << "NO";
		return;
	}

	int a_cnt = getPrimeExponentCount(a);
	int b_cnt = getPrimeExponentCount(b);
	int mx_ops = a_cnt + b_cnt;

	cout << ((mx_ops >= k) ? "YES" : "NO");
}

int32_t main() {

	FIO;

	sieve(int(1e5));

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
