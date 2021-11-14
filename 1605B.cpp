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


void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt_a = 0;
	vi aPos, freq_b(n + 1, 0), freq_c(n + 1, 0);

	FOR (i, 0, n) {
		if (s[i] == 'a') {
			++cnt_a;
			aPos.eb(i + 1);
			freq_b[i + 1] = freq_b[i];
			freq_c[i + 1] = freq_c[i];
		}
		else if (s[i] == 'b') {
			freq_b[i + 1] = 1 + freq_b[i];
			freq_c[i + 1] = freq_c[i];
		}
		else {
			freq_b[i + 1] = freq_b[i];
			freq_c[i + 1] = 1 + freq_c[i];
		}
	}

	if (cnt_a < 2) {
		cout << -1;
		return;
	}

	int ans = n + 1;

	FOR (i, 1, sz(aPos)) {
		int l = aPos[i - 1], r = aPos[i];
		int currFreq_b = freq_b[r] - freq_b[l];
		int currFreq_c = freq_c[r] - freq_c[l];

		if (2 > currFreq_b && 2 > currFreq_c)
			ans = min(ans, r - l + 1);
	}

	if (ans == n + 1)
		cout << -1;
	else
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
