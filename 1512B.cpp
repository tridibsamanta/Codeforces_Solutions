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
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(a,x)         for (auto& a : x)
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


void solve() {

	int n;
	cin >> n;

	vector<vector<char> > grid(n, vector<char> (n));

	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

	FOR (i, 0, n) {
		FOR (j, 0, n) {
			cin >> grid[i][j];

			if (grid[i][j] == '*') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	if (x1 == x2) {
		if (x1 > 0) {
			grid[x1 - 1][y1] = '*';
			grid[x2 - 1][y2] = '*';
		}
		else {
			grid[x1 + 1][y1] = '*';
			grid[x2 + 1][y2] = '*';
		}
	}
	else if (y1 == y2) {
		if (y1 > 0) {
			grid[x1][y1 - 1] = '*';
			grid[x2][y2 - 1] = '*';
		}
		else {
			grid[x1][y1 + 1] = '*';
			grid[x2][y2 + 1] = '*';
		}
	}
	else {
		grid[x1][y2] = '*';
		grid[x2][y1] = '*';
	}

	FOR (i, 0, n) {
		FOR (j, 0, n) {
			cout << grid[i][j];
		}
		cout << '\n';
	}

}

int main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}