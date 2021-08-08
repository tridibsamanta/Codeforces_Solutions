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


vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
	int n = A.size(), m = A[0].size(), k = B[0].size();
	vector<vector<int> > res(n, vector<int>(k, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			long long curr = 0;
			for (int l = 0; l < m; l++) {
				curr += (A[i][l] * 1LL * B[l][j]) % MOD;
			}
			res[i][j] = curr % MOD;
		}

	return res;
}

vector<vector<int> > power(vector<vector<int> >& A, int k) {
	int n = A.size();

	vector<vector<int> > ret(n, vector<int>(n)), B = A;
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;

	while (k) {
		if (k & 1)
			ret = multiply(ret, B);
		k >>= 1;
		B = multiply(B, B);
	}
	return ret;
}

void solve() {

	int n;
	cin >> n;

	vector<vector<int> > T_mat({
		{0, 1, 1, 1},
		{1, 0, 1, 1},
		{1, 1, 0, 1},
		{1, 1, 1, 0}
	});

	vector<vector<int> > base_mat({
		{0},
		{0},
		{0},
		{1}
	});

	// (T_mat ^ n) * base_mat
	vector<vector<int> > result = power(T_mat, n);
	result = multiply(result, base_mat);

	cout << result[3][0];
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
