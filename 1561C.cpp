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


const int MAXN = 1e9 + 7;

int n;
vpii minPower;

// checks whether it is possible to defeat monsters in all the caves
// if we start with some given initital power
bool isPossible(int power) {
	int currPower = power;

	FOR (i, 0, n) {
		if (currPower < minPower[i].first)
			return false;
		else
			currPower += minPower[i].second;
	}

	return true;
}

void solve() {

	cin >> n;

	minPower.clear();
	minPower.resize(n);

	int maxPower = 0; // helps to optimize the upper-bound in b.s.

	FOR (i, 0, n) {
		int k;
		cin >> k;

		minPower[i].second = k;

		int currMinPower = 0;

		FOR (j, 0, k) {
			int val;
			cin >> val;

			maxPower = max(maxPower, val);

			// find the min starting power to defeat the current monster
			if (currMinPower == 0)
				currMinPower = val + 1;
			else {
				if ((currMinPower + j) <= val) {
					int powerDeficit = val - (currMinPower + j);
					currMinPower += powerDeficit + 1;
				}
			}
		}

		minPower[i].first = currMinPower;
	}

	sort(all(minPower));

	// Apply b.s. to find the minimum starting power of hero
	int lo = 1, hi = maxPower + 1;
	int ans = 0;

	while (lo <= hi) {
		int mid = lo + ((hi - lo) / 2);

		if (isPossible(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << ans;
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
