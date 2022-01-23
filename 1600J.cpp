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

int n, m, currArea;
vector<vb> visited;
vector<vector<vi> > grid;

void floodFill(int r, int c) {
	visited[r][c] = true;
	++currArea;

	FOR (k, 0, 4) {
		int adjR = r + row4D[k];
		int adjC = c + col4D[k];

		if ((adjR >= 0 && adjR < n) && (adjC >= 0 && adjC < m) && !visited[adjR][adjC]) {
			// North
			if (k == 0) {
				if (!grid[r][c][k] && !grid[adjR][adjC][2])
					floodFill(adjR, adjC);
			}
			// East
			else if (k == 1) {
				if (!grid[r][c][k] && !grid[adjR][adjC][3])
					floodFill(adjR, adjC);
			}
			// South
			else if (k == 2) {
				if (!grid[r][c][k] && !grid[adjR][adjC][0])
					floodFill(adjR, adjC);
			}
			// West
			else if (k == 3) {
				if (!grid[r][c][k] && !grid[adjR][adjC][1])
					floodFill(adjR, adjC);
			}
		}
	}
}

void solve() {
	cin >> n >> m;

	visited.clear();
	visited.resize(n, vb (m, false));

	grid.clear();
	grid.resize(n, vvi (m, vi (4, 0)));

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			int x;
			cin >> x;

			// North
			if (x & (1 << 3)) {
				grid[i][j][0] = 1;

				if (i - 1 >= 0)
					grid[i - 1][j][2] = 1;
			}

			// East
			if (x & (1 << 2)) {
				grid[i][j][1] = 1;

				if (j + 1 < m)
					grid[i][j + 1][3] = 1;
			}

			// South
			if (x & (1 << 1)) {
				grid[i][j][2] = 1;

				if (i + 1 < n)
					grid[i + 1][j][0] = 1;
			}

			// West
			if (x & (1 << 0)) {
				grid[i][j][3] = 1;

				if (j - 1 >= 0)
					grid[i][j - 1][1] = 1;
			}
		}
	}

	vi area;

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (!visited[i][j]) {
				currArea = 0;
				floodFill(i, j);
				area.eb(currArea);
			}
		}
	}

	rsort(area);

	printall(area);
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
