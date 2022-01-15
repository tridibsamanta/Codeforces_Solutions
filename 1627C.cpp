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


int n;
vector<vector<pii > > adj;
vb visited;

void dfs(int u, int prevVal) {
	visited[u] = true;

	FOR (i, 0, sz(adj[u])) {
		int v = adj[u][i].first;

		if (visited[v])
			continue;

		if (prevVal == 2) {
			adj[u][i].second = 3;

			FOR (k, 0, sz(adj[v])) {
				if (adj[v][k].first == u) {
					adj[v][k].second = 3;
					break;
				}
			}

			dfs(v, 3);
		}
		else {
			adj[u][i].second = 2;

			FOR (k, 0, sz(adj[v])) {
				if (adj[v][k].first == u) {
					adj[v][k].second = 2;
					break;
				}
			}

			dfs(v, 2);
		}
	}
}

void solve() {
	cin >> n;

	adj.clear();
	adj.resize(n + 1);

	visited.clear();
	visited.resize(n + 1, false);

	vvi edges(n - 1);
	bool isPossible = true;

	FOR (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;

		edges[i].eb(u);
		edges[i].eb(v);

		adj[u].pb({v, 0});
		adj[v].pb({u, 0});

		if (sz(adj[u]) > 2 || sz(adj[v]) > 2)
			isPossible = false;
	}

	if (!isPossible) {
		cout << -1;
		return;
	}

	FOR (i, 1, n + 1) {
		if (sz(adj[i]) == 1) {
			dfs(i, 3);
			break;
		}
	}

	FOR (i, 0, n - 1) {
		int u = edges[i][0], v = edges[i][1];

		FOR (i, 0, sz(adj[u])) {
			if (adj[u][i].first == v) {
				cout << adj[u][i].second << ' ';
				break;
			}
		}
	}
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
