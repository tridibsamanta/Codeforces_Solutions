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


void solve() {

	int n;
	cin >> n;

	vi arr(n, 0);
	vi arr2(n, 0);

	int oddCnt = 0, evenCnt = 0;

	FOR (i, 0, n) {
		int val;
		cin >> val;

		if (val & 1) {
			arr[i] = arr2[i] = 1;
			++oddCnt;
		}
		else {
			arr[i] = arr2[i] = 0;
			++evenCnt;
		}
	}

	// If |#odd - #even| > 1, then it is impossible to get an answer
	if (abs(oddCnt - evenCnt) > 1) {
		cout << -1;
		return;
	}

	// Case 1: E 0 E O E O E O ...

	int parity = 0; // 0 -> Even, 1 -> Odd
	int oddPos = 1, evenPos = 1, ans1 = 0;

	FOR (i, 0, n) {
		if (arr[i] != parity) {

			// expecting an odd number
			if (parity == 1) {

				oddPos = max(i, oddPos);

				while (arr[oddPos] == 0 && oddPos < n) {
					++oddPos;
				}

				if (oddPos == n) {
					ans1 = INT_MAX;
					break;
				}

				ans1 += (oddPos - i);

				arr[i] = 1;

				if (oddPos != i)
					arr[oddPos] = 0;

				++oddPos;
			}
			// expecting an even number
			else {

				evenPos = max(i, evenPos);

				while (arr[evenPos] == 1 && evenPos < n) {
					++evenPos;
				}

				if (evenPos == n) {
					ans1 = INT_MAX;
					break;
				}

				ans1 += (evenPos - i);

				arr[i] = 0;

				if (evenPos != i)
					arr[evenPos] = 1;

				++evenPos;
			}
		}

		parity ^= 1;
	}

	// Case 2: O E O E O E O E ...

	parity = 1;
	oddPos = 1, evenPos = 1;
	int ans2 = 0;

	FOR (i, 0, n) {
		if (arr2[i] != parity) {

			// expecting an odd number
			if (parity == 1) {

				oddPos = max(i, oddPos);

				while (arr2[oddPos] == 0 && oddPos < n) {
					++oddPos;
				}

				if (oddPos == n) {
					ans2 = INT_MAX;
					break;
				}

				ans2 += (oddPos - i);

				arr2[i] = 1;

				if (oddPos != i)
					arr2[oddPos] = 0;

				++oddPos;
			}
			// expecting an even number
			else {

				evenPos = max(i, evenPos);

				while (arr2[evenPos] == 1 && evenPos < n) {
					++evenPos;
				}

				if (evenPos == n) {
					ans2 = INT_MAX;
					break;
				}

				ans2 += (evenPos - i);

				arr2[i] = 0;

				if (evenPos != i)
					arr2[evenPos] = 1;

				++evenPos;
			}
		}

		parity ^= 1;
	}

	if ((ans1 == INT_MAX) && (ans2 == INT_MAX)) {
		cout << -1;
		return;
	}

	cout << min(ans1, ans2);
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
