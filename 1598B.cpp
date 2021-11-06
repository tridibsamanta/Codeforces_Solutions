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
Let's assume we want to assign students of group 1 to day a and
students of group 2 to day b.

not_cnt_ab 	= count of students not available on day a as well as day b.
cnt_ab 		= count of students available on day a as well as day b.
cnt_a		= count of students available only on day a.
cnt_b		= count of students available only on day b.

1. 	not_cnt_ab > 0

	As we need to place each of n students in one of the 2 groups.
	Hence if we see that if a student is not available in day a as well as day b.
	Then we cannot place that particular student in any of the 2 selected days,
	so answer will be NO.

2.	cnt_a or cnt_b > (n / 2)

	Assume we have cnt_a > (n / 2). We can assign exactly half of the students
	for day a, but the surplus students i.e. cnt_a - (n / 2), cannot be assigned
	to day b because they are only available on day a, so answer will be NO.

3.	Else the answer is always YES, because we can place cnt_a + (n / 2 - cnt_a)
	students in group 1. The (n / 2 - cnt_a) students are taken from that set of
	students who are available both on day a and day b, i.e. cnt_ab.
	Similarly, for group 2 we place cnt_b students and (n / 2 - cnt_b) students
	from that set of students who are available both on day a and day b,
	i.e. cnt_ab.

Example:

		a       b
M	T	W	T	F

0	0	1	0	1
0	0	1	0	1
0	0	1	0	1
0	0	1	0	0
0	0	1	0	0
0	0	0	0	1

not_cnt_ab	= 0
cnt_ab 		= 3
cnt_a		= 2
cnt_b		= 1

Group 1: cnt_a + (n / 2 - cnt_a) = 2 + (3 - 2) = 3
Group 2: cnt_b + (n / 2 - cnt_b) = 1 + (3 - 1) = 3
*/

void solve() {

	int n;
	cin >> n;

	vector<vector<bool> > grid(n, vb (5, false));

	bool isAvailable;
	FOR (i, 0, n) {
		FOR (j, 0, 5) {
			cin >> isAvailable;

			grid[i][j] = isAvailable;
		}
	}

	int group_size = n / 2;

	FOR (i, 0, 4) {
		FOR (j, i + 1, 5) {

			int cnt_ab = 0, cnt_a = 0, cnt_b = 0;

			FOR (k, 0, n) {
				bool day_a = grid[k][i], day_b = grid[k][j];

				if (!day_a && !day_b)
					break;

				cnt_ab += (day_a && day_b);
				cnt_a += (day_a && !day_b);
				cnt_b += (day_b && !day_a);
			}

			if (cnt_a > group_size || cnt_b > group_size)
				continue;

			if (cnt_a + cnt_b + cnt_ab == n) {
				cout << "YES";
				return;
			}
		}
	}

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
