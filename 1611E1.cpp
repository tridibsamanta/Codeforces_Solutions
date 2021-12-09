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


int n, k;
vi location, entryTime;
vvi adj;

void init() {
	adj.clear();
	adj.resize(n + 1);

	location.clear();
	location.resize(n + 1, 0);

	entryTime.clear();
	entryTime.resize(n + 1, 0);
}

void friends_bfs() {
	vb visited(n + 1, false);

	queue<int> todo;

	FOR (i, 1, k + 1) {
		todo.push(location[i]);
		visited[location[i]] = true;
	}

	while (!todo.empty()) {
		int m = sz(todo);

		FOR (i, 0, m) {
			int u = todo.front();
			todo.pop();

			FOR (k, 0, sz(adj[u])) {
				int v = adj[u][k];

				if (visited[v])
					continue;

				entryTime[v] = entryTime[u] + 1;
				todo.push(v);
				visited[v] = true;
			}
		}
	}
}

bool vald_bfs() {
	vb visited(n + 1, false);

	queue<int> todo;
	todo.push(1);
	visited[1] = true;

	int currTime = 1;
	bool flag = false;

	while (!todo.empty()) {
		int m = sz(todo);

		FOR (i, 0, m) {
			int u = todo.front();
			todo.pop();

			FOR (k, 0, sz(adj[u])) {
				int v = adj[u][k];

				if (visited[v])
					continue;

				if ((sz(adj[v]) == 1) && (entryTime[v] > currTime))
					return true;

				todo.push(v);
				visited[v] = true;
			}
		}

		++currTime;
	}

	return false;
}

void solve() {
	cin >> n >> k;

	init();

	FOR (i, 1, k + 1) {
		cin >> location[i];
	}

	FOR (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;

		adj[u].eb(v);
		adj[v].eb(u);
	}

	friends_bfs();

	if (vald_bfs())
		cout << "YES";
	else
		cout << "NO";
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
