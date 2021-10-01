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


int n, m, k;
vector<string> grid;

void markTick(int i, int j) {

	vpii leftUpIndex, rightUpIndex;
	int leftUp = 0, rightUp = 0, r = i, c = j;

	while (i > 0 && j > 0) {
		if (grid[i - 1][j - 1] == '*' || grid[i - 1][j - 1] == '#') {
			++leftUp;
			--i; --j;
			leftUpIndex.pb({i, j});
		}
		else
			break;
	}

	i = r; j = c;

	while (i > 0 && j < m - 1) {
		if (grid[i - 1][j + 1] == '*' || grid[i - 1][j + 1] == '#') {
			++rightUp;
			--i; ++j;
			rightUpIndex.pb({i, j});
		}
		else
			break;
	}

	int curr_k = min(leftUp, rightUp);

	if (curr_k < k)
		return;

	grid[r][c] = '#';

	FOR (i, 0, curr_k) {
		r = leftUpIndex[i].first;
		c = leftUpIndex[i].second;
		grid[r][c] = '#';

		r = rightUpIndex[i].first;
		c = rightUpIndex[i].second;
		grid[r][c] = '#';
	}
}

void solve() {

	grid.clear();

	cin >> n >> m >> k;

	FOR (i, 0, n) {
		string s;
		cin >> s;

		grid.eb(s);
	}

	if (m == 3 && grid[0][1] == '*') {
		cout << "NO";
		return;
	}
	else if (grid[n - 1][0] == '*' || grid[n - 1][m - 1] == '*') {
		cout << "NO";
		return;
	}

	FOR (i, 1, n) {
		FOR (j, 0, m) {
			if (grid[i][j] == '*')
				markTick(i, j);
		}
	}

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] == '*') {
				cout << "NO";
				return;
			}
		}
	}

	cout << "YES";
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
