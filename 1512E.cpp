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
#define vvi                 vector<vector<int> >
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(a,x)         for (auto& a : x)
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

	int n, l, r, s;
	cin >> n >> l >> r >> s;

	int k = r - l + 1;

	int minSum = (k * (k + 1)) / 2;
	int maxSum = (k * ((2 * n) + 1 - k)) / 2;

	if (s > maxSum || s < minSum) {
		cout << -1;
		return;
	}

	vi nums(k);

	FOR (i, 0, k) {
		nums[i] = i + 1;
	}

	int rem = s - minSum, maxVal = n;

	for (int j = k - 1; j >= 0; --j) {

		if (maxVal - nums[j] < rem) {
			rem -= (maxVal - nums[j]);
			nums[j] = maxVal;
			--maxVal;
		}
		else {
			nums[j] += rem;
			rem = 0;
			break;
		}
	}

	set<int> st;

	FOR(i, 0, k) {
		st.insert(nums[i]);
	}

	vi res(n);

	int idx = l - 1;

	for (auto i : st) {
		res[idx++] = i;
	}

	int val = 1;

	FOR (i, 0, l - 1) {
		while (st.find(val) != st.end()) {
			++val;
		}
		res[i] = val;
		++val;
	}

	FOR (i, r, n) {
		while (st.find(val) != st.end()) {
			++val;
		}
		res[i] = val;
		++val;
	}

	FOR (i, 0, n) {
		cout << res[i] << ' ';
	}
}

int main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}