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
#define pb                  push_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void solve() {

	int n = 5;
	int mat[5][5];

	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			cin >> mat[i][j];
		}
	}

	int p[5], ans = 0, score;

	for (int i = 0 ; i < n ; ++i) {
		p[i] = i;
	}

	do {
		score = mat[p[0]][p[1]] + mat[p[1]][p[0]];
		score += mat[p[2]][p[3]] + mat[p[3]][p[2]];

		score += mat[p[1]][p[2]] + mat[p[2]][p[1]];
		score += mat[p[3]][p[4]] + mat[p[4]][p[3]];

		score += mat[p[2]][p[3]] + mat[p[3]][p[2]];

		score += mat[p[3]][p[4]] + mat[p[4]][p[3]];

		if (score > ans)
			ans = score;
	}
	while (next_permutation(p, p + n));

	cout << ans << '\n';
}


int main() {

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
