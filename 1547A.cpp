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


void solve() {

	int xA, yA, xB, yB, xF, yF;
	cin >> xA >> yA >> xB >> yB >> xF >> yF;

	int minMoves = 0;

	// A and B lies in the same col
	if (xA == xB) {

		// F also lies in the same col
		if (xF == xA) {

			// A lies above B
			if (yA > yB) {

				// F lies in between A & B
				if (yF > yB && yF < yA)
					minMoves = yA - yB + 2;
				// F dosen't lie in between A & B
				else
					minMoves = yA - yB;
			}
			// A lies below B
			else {

				// F lies in between A & B
				if (yF < yB && yF > yA)
					minMoves = yB - yA + 2;
				// F dosen't lie in between A & B
				else
					minMoves = yB - yA;
			}
		}
		// F doesn't lie in the same col
		else {
			minMoves = abs(yB - yA);
		}
	}
	// A and B lies in the same row
	else if (yA == yB) {

		// F also lies in the same row
		if (yF == yA) {

			// A lies to the right of B
			if (xA > xB) {

				// F lies in between A & B
				if (xF > xB && xF < xA)
					minMoves = xA - xB + 2;
				// F dosen't lie in between A & B
				else
					minMoves = xA - xB;
			}
			// A lies to the left of B
			else {

				// F lies in between A & B
				if (xF < xB && xF > xA)
					minMoves = xB - xA + 2;
				// F dosen't lie in between A & B
				else
					minMoves = xB - xA;
			}
		}
		// F doesn't lie in the same row
		else {
			minMoves = abs(xB - xA);
		}
	}
	// A & B dosen't lie in the same row or col
	else {
		minMoves = abs(yB - yA) + abs(xB - xA);
	}

	cout << minMoves;
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
