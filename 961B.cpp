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

int n, k;
int theorem[MAXN];
int isAwake[MAXN];
int prefAll[MAXN];
int pref[MAXN];

void computePref() {

	FOR (i, 1, n + 1) {
		prefAll[i] = theorem[i] + prefAll[i - 1];
	}

	FOR (i, 1, n + 1) {
		if (isAwake[i]) {
			pref[i] = theorem[i] + pref[i - 1];
		}
		else
			pref[i] = pref[i - 1];
	}
}

void solve() {

	memset(theorem, 0, sizeof(theorem));
	memset(isAwake, 0, sizeof(isAwake));

	cin >> n >> k;

	FOR (i, 1, n + 1) {
		cin >> theorem[i];
	}

	FOR (i, 1, n + 1) {
		cin >> isAwake[i];
	}

	computePref();

	int res = INT_MIN;

	FOR (i, k, n + 1) {
		int l = pref[i - k] - pref[0];
		int mid = prefAll[i] - prefAll[i - k];
		int r = pref[n] - pref[i];

		res = max(res, l + mid + r);
	}

	cout << res;
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
