/*
 ~ Author    : @tridib_2003
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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


int n, m;
vector<vpii> adj;
vb visited;
int currOr, vertexCnt, excluded_bits;

void dfs(int u, int bit) {
	visited[u] = true;
	++vertexCnt;

	FOR (i, 0, sz(adj[u])) {

		int v = adj[u][i].first;
		int wt = adj[u][i].second;

		if (visited[v])
			continue;

		if (!(wt & (1 << bit)) && !(wt & excluded_bits)) {
			currOr = currOr | wt;
			dfs(v, bit);
		}
	}
}

void solve() {
	cin >> n >> m;

	adj.clear();
	adj.resize(n + 1);

	FOR (i, 0, m) {
		int u, v, wt;
		cin >> u >> v >> wt;

		adj[u].pb({v, wt});
		adj[v].pb({u, wt});
	}

	int ans = (1LL << 30);
	excluded_bits = 0;

	RFOR (k, 31, 0) {
		visited.assign(n + 1, false);
		vertexCnt = currOr = 0;

		// Don't consider the edges having the k'th bit set in their weight
		dfs(1, k);

		// if the graph still has a single component
		if (vertexCnt == n) {
			excluded_bits += (1 << k);
			ans = min(ans, currOr);
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
