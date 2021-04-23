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


static bool dp[105][200005];

bool checkSubsetSum(vi& arr, int n, int sum) {

	FOR (i, 1, sum + 1)
	dp[0][i] = false;
	FOR (i, 0, n + 1)
	dp[i][0] = true;

	FOR (i, 1, n + 1) {
		FOR (j, 1, sum + 1) {

			if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][sum];
}

void solve() {

	int n;
	cin >> n;

	vi arr(n);

	int sum = 0, oddIdx = -1;

	FOR (i, 0, n) {
		cin >> arr[i];

		sum += arr[i];

		if ((arr[i] & 1) && (oddIdx == -1))
			oddIdx = i;
	}

	if (sum & 1) {
		cout << 0;
		return;
	}

	if (!checkSubsetSum(arr, n, sum / 2)) {
		cout << 0;
		return;
	}

	if (oddIdx != -1) {
		cout << 1 << '\n' << oddIdx + 1;
		return;
	}

	while (1) {
		FOR (i, 0, n) {
			arr[i] /= 2;

			if (arr[i] & 1) {
				cout << 1 << '\n' << i + 1;
				return;
			}
		}
	}
}

int main() {

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
