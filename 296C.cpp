/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define int                 long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
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
#define FORALL(i, a)         for (auto& (i) : (a))
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

const int MAXN = 1e5 + 5;

int arr[MAXN];
int segCache[4 * MAXN];
int lazy[4 * MAXN];
int opCount[MAXN];

void buildSegCache(int idx, int l, int r) {

	if (l == r) {
		segCache[idx] = arr[l];
		return;
	}

	int mid = (l + r) / 2;

	buildSegCache(2 * idx, l, mid);
	buildSegCache(2 * idx + 1, mid + 1, r);

	segCache[idx] = segCache[2 * idx] + segCache[2 * idx + 1];
}

void rangeUpdate(int idx, int curr_l, int curr_r, int l, int r, int val) {

	if (lazy[idx] != 0) {
		segCache[idx] += (curr_r - curr_l + 1) * lazy[idx];

		if (curr_l != curr_r) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}

		lazy[idx] = 0;
	}

	if (curr_l > r || curr_r < l || curr_l > curr_r)
		return;

	if (curr_l >= l && curr_r <= r) {
		segCache[idx] += (curr_r - curr_l + 1) * val;

		if (curr_l != curr_r) {
			lazy[2 * idx] += val;
			lazy[2 * idx + 1] += val;
		}

		return;
	}

	int mid = (curr_l + curr_r) / 2;

	rangeUpdate(2 * idx, curr_l, mid, l, r, val);
	rangeUpdate(2 * idx + 1, mid + 1, curr_r, l, r, val);

	segCache[idx] = segCache[2 * idx] + segCache[2 * idx + 1];
}

int querySumLazy(int idx, int curr_l, int curr_r, int l, int r) {

	if (lazy[idx] != 0) {
		segCache[idx] += (curr_r - curr_l + 1) * lazy[idx];

		if (curr_l != curr_r) {
			lazy[2 * idx] += lazy[idx];
			lazy[2 * idx + 1] += lazy[idx];
		}

		lazy[idx] = 0;
	}

	if (curr_l > r || curr_r < l || curr_l > curr_r)
		return 0;

	if (curr_l >= l && curr_r <= r)
		return segCache[idx];

	int mid = (curr_l + curr_r) / 2;

	return querySumLazy(2 * idx, curr_l, mid, l, r) +
	       querySumLazy(2 * idx + 1, mid + 1, curr_r, l, r);
}

void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	FOR (i, 0, n) {
		cin >> arr[i + 1];
	}

	vvi operation(m + 1, vi (3, 0));

	FOR (i, 0, m) {
		int l, r, d;
		cin >> l >> r >> d;

		operation[i + 1][0] = l;
		operation[i + 1][1] = r;
		operation[i + 1][2] = d;
	}

	FOR (i, 0, k) {
		int l, r;
		cin >> l >> r;

		++opCount[l];
		--opCount[r + 1];
	}

	FOR (i, 1, MAXN) {
		opCount[i] += opCount[i - 1];
	}

	buildSegCache(1, 1, n);

	FOR (i, 1, MAXN) {
		if (opCount[i] > 0) {
			int l = operation[i][0];
			int r = operation[i][1];
			int val = operation[i][2] * opCount[i];

			rangeUpdate(1, 1, n, l, r, val);
		}
	}

	FOR (i, 0, n) {
		cout << querySumLazy(1, 1, n, i + 1, i + 1) << ' ';
	}
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
