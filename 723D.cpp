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


static int row4D[] = { -1, 0, 1, 0};
static int col4D[] = {0, 1, 0, -1};

int n, m, k;
vector<string> grid;
vector<vb> visited;
int cell_cnt;

void eliminateEdgeWaterbody(int r, int c) {
	grid[r][c] = '#';

	FOR (i, 0, 4) {
		int adj_r = r + row4D[i];
		int adj_c = c + col4D[i];

		if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < m) && (grid[adj_r][adj_c] == '.')) {
			eliminateEdgeWaterbody(adj_r, adj_c);
		}
	}
}

void findAllLakeSize(int r, int c) {
	visited[r][c] = true;
	++cell_cnt;

	FOR (i, 0, 4) {
		int adj_r = r + row4D[i];
		int adj_c = c + col4D[i];

		if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < m) && !visited[adj_r][adj_c] && (grid[adj_r][adj_c] == '.')) {
			findAllLakeSize(adj_r, adj_c);
		}
	}
}

void fillLake(int r, int c) {
	grid[r][c] = '*';
	visited[r][c] = true;

	FOR (i, 0, 4) {
		int adj_r = r + row4D[i];
		int adj_c = c + col4D[i];

		if ((adj_r >= 0 && adj_r < n) && (adj_c >= 0 && adj_c < m) && !visited[adj_r][adj_c] && (grid[adj_r][adj_c] == '.')) {
			fillLake(adj_r, adj_c);
		}
	}
}

void solve() {
	cin >> n >> m >> k;

	grid.resize(n);

	FOR (i, 0, n) {
		cin >> grid[i];
	}

	visited.resize(n, vb (m, false));

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (grid[i][j] == '.') {
					eliminateEdgeWaterbody(i, j);
				}
			}
		}
	}

	set<pair<int, pii>> lakeArea;

	visited.clear();
	visited.resize(n, vb (m, false));

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] == '.' && !visited[i][j]) {
				cell_cnt = 0;
				findAllLakeSize(i, j);

				lakeArea.insert({cell_cnt, {i, j}});
			}
		}
	}

	int fill_lake_cnt = sz(lakeArea) - k;
	int ans = 0;

	while (fill_lake_cnt--) {
		pair<int, pii> curr = *(lakeArea.begin());
		lakeArea.erase(lakeArea.begin());

		int curr_lake_area = curr.first;
		int r = curr.second.first;
		int c = curr.second.second;

		ans += curr_lake_area;

		visited.assign(n, vb (m, false));

		fillLake(r, c);
	}

	cout << ans << '\n';

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout << ((grid[i][j] == '#') ? '.' : grid[i][j]);
		}
		cout << '\n';
	}
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
