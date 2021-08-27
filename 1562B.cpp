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


vector<bool> prime;
set<int> primes;

void sieve(int maximum = 100) {
	maximum = max(maximum, 1);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes.clear();

	for (int p = 2; p <= maximum; ++p) {
		if (prime[p]) {
			primes.insert(p);

			for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
				prime[i] = false;
		}
	}
}

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	vi freq(10, 0);

	FOR (i, 0, n) {
		++freq[s[i] - '0'];
	}

	if (freq[1] != 0 || freq[4] != 0 || freq[6] != 0 || freq[8] != 0 || freq[9] != 0) {
		cout << 1 << '\n';

		if (freq[1] != 0)
			cout << 1;
		else if (freq[4] != 0)
			cout << 4;
		else if (freq[6] != 0)
			cout << 6;
		else if (freq[8] != 0)
			cout << 8;
		else if (freq[9] != 0)
			cout << 9;

		return;
	}

	// now the result must have > 1 digits

	if (n == 2) {
		cout << 2 << '\n';
		cout << s;
		return;
	}

	FOR (i, 0, n - 1) {
		FOR (j, i + 1, n) {
			string curr = "";
			curr += s[i];
			curr += s[j];
			int num = stoi(curr);

			if (primes.find(num) == primes.end()) {
				cout << 2 << '\n';
				cout << num;
				return;
			}
		}
	}
}

int32_t main() {

	FIO;

	sieve();

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
		cout << '\n';
	}

	return 0;
}
