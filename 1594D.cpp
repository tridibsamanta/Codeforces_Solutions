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


/*
Approach:

Case 1:	(When a person says that the other person is a crewmate)
		Both the persons are either Crewmates or Imposters,
		i.e. both nodes are having the same color.

Case 2: (When a person says that the other person is an imposter)
		One person is a crewmate and the other one is an imposter,
		i.e. the nodes are having different color.

As a person can be a crewmate or an imposter, we can represent them
easily using 2 colors. For each connected component we perform
2-coloring that satisfy the 2 types of edges stated above.
As we need to maximize the number of imposters, we would consider
the color occurring more number of times in each component and
the total number of imposters will be the sum of all counts
we get from each of these components.

While coloring a component using 2-colors, if for a node we find
a contradiction of colors then solution doesn't exist.
*/

vector<vector<pii> > adj;

void solve() {

	int n, q;
	cin >> n >> q;

	adj.clear();
	adj.resize(n + 1);

	int i, j;
	string c;

	while (q--) {

		cin >> i >> j >> c;

		if (c == "crewmate") { // Case 1
			adj[i].pb({j, 1});
			adj[j].pb({i, 1});
		}
		else { // Case 2
			adj[i].pb({j, 2});
			adj[j].pb({i, 2});
		}
	}

	int ans = 0;

	vi isColored(n + 1, 0);
	bool isPossible = true;

	FOR (j, 1, n + 1) {

		if (isColored[j] == 0) {

			vi color_cnt(3, 0);

			queue<int> q;
			q.push(j);
			isColored[j] = 1;
			++color_cnt[isColored[j]];

			while (!q.empty()) {

				int u = q.front();
				q.pop();

				for (int i = 0; i < sz(adj[u]); ++i) {

					pii curr = adj[u][i];

					int v = curr.first;
					int t = curr.second;

					if (!isColored[v]) {
						if (t == 1) { // Case 1
							isColored[v] = isColored[u];
							++color_cnt[isColored[v]];
						}
						else { // Case 2
							isColored[v] = 3 - isColored[u];
							++color_cnt[isColored[v]];
						}

						q.push(v);
					}
					else {
						if (t == 1 && (isColored[v] != isColored[u]))
							isPossible = false;
						else if (t == 2 && (isColored[v] != 3 - isColored[u]))
							isPossible = false;
					}

					if (!isPossible) {
						cout << -1;
						return;
					}
				}
			}

			ans += max(color_cnt[1], color_cnt[2]);
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
