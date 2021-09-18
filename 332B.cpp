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

/*
Intuition:

1.	We need to find two windows each having exactly 'k' elements,
	such that the sum of the elements present in both the
	windows is maximum.
	Let's call them - left window and right window.

2.	We traverse the array from right to left. Why ?
	This will help us to keep the right window sum maximum.

3. 	At each iteration we try to find a right window having
	greater sum than the currently stored right window sum,
	and update if we find such a window.

4.	Also we keep considering every possible left window,
	and keep checking that the sum of left and right window
	is greater than the maximum sum we have got till now.

	T.C. - O(n)
*/

const int MAXN = 2e5 + 5;

vi pSum;

int range_sum(int l, int r) {
	return (pSum[r] - pSum[l - 1]);
}

void solve() {

	int n, k;
	cin >> n >> k;

	vi arr(n);
	pSum.resize(n + 1, 0);

	FOR (i, 0, n) {
		cin >> arr[i];

		pSum[i + 1] = pSum[i] + arr[i];
	}

	// Initially we consider that the given array has exactly 2*k elements
	int ans_sum = range_sum(n - 2 * k + 1, n - k) + range_sum(n - k + 1, n);
	pii ans_idx = mp(n - 2 * k + 1, n - k + 1);

	// maxRightWindow = {start position, sum}
	pii maxRightWindow = mp(n - k + 1, range_sum(n - k + 1, n));

	for (int i = n - 2 * k; i > 0; --i) {
		// Trying to maximize right window sum
		int rightWindowSum = range_sum(i + k, i + 2 * k - 1);

		if (rightWindowSum >= maxRightWindow.second)
			maxRightWindow = mp(i + k, rightWindowSum);

		// Trying to maximize (left window + right window) sum
		int twoWindowSum = range_sum(i, i + k - 1) + maxRightWindow.second;

		if (twoWindowSum >= ans_sum) {
			ans_sum = twoWindowSum;
			ans_idx = mp(i, maxRightWindow.first);
		}
	}

	cout << ans_idx.first << ' ' << ans_idx.second;
}

int32_t main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
