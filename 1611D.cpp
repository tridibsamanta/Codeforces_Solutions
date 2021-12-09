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
#define MOD                 998244353 // 1000000007
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
vi b, p, pos;
vb visited;
vvi adj;

void init() {
	b.clear();
	p.clear();

	b.resize(n);
	p.resize(n);

	pos.clear();
	pos.resize(n + 1);

	visited.clear();
	visited.resize(n + 1, false);

	adj.clear();
	adj.resize(n + 1);
}

bool dfs(int u, int parent) {
	visited[u] = true;

	if ((parent != u) && (pos[parent] > pos[u]))
		return false;

	FOR (i, 0, sz(adj[u])) {
		int v = adj[u][i];

		if (visited[v])
			continue;

		if (!dfs(v, u))
			return false;
	}

	return true;
}

void solve() {
	cin >> n;

	init();

	int rootVertex;

	FOR (i, 1, n + 1) {
		cin >> b[i];

		if (b[i] == i) {
			rootVertex = i;
			continue;
		}

		adj[b[i]].eb(i);
		adj[i].eb(b[i]);
	}

	FOR (i, 0, n) {
		cin >> p[i];
		pos[p[i]] = i + 1;
	}

	if (!dfs(rootVertex, rootVertex)) {
		cout << -1;
		return;
	}

	vi dist(n + 1, 0);
	vi weights(n + 1, 0);

	FOR (i, 1, n) {
		int v = p[i], u = p[i - 1];

		weights[v] = dist[u] + 1 - dist[b[v]];
		dist[v] = dist[b[v]] + weights[v];
	}

	FOR (i, 1, n + 1) {
		cout << weights[i] << ' ';
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
