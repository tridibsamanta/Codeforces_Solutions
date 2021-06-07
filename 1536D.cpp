/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
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
#define FORALL(i, a)         for (auto& (i) : (a))
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
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


const int INF = 1e9 + 7;

void solve() {

	int n;
	cin >> n;

	vi b(n);

	FOR (i, 0, n) {
		cin >> b[i];
	}

	if (n == 1) {
		cout << "YES";
		return;
	}

	indexed_set s;

	s.insert(b[0]);
	int sz_s = 1;

	int last = INF, first = -INF;

	FOR (i, 1, n) {

		int mid = sz_s / 2;
		int median = *s.find_by_order(mid);
		int prev = -INF, next = INF;

		if (i > 1) {
			prev = *s.find_by_order(mid - 1);
			next = *s.find_by_order(mid + 1);
		}

		if (b[i] == next) {
			s.insert(last++);
			s.insert(last++);
		}
		else if (b[i] == prev) {
			s.insert(first--);
			s.insert(first--);
		}
		else if (b[i] == median) {
			s.insert(first--);
			s.insert(last++);
		}
		else if (b[i] > prev &&  b[i] < median) {
			s.insert(b[i]);
			s.insert(first--);
		}
		else if (b[i] > median &&  b[i] < next) {
			s.insert(b[i]);
			s.insert(last++);
		}
		else {
			cout << "NO";
			return;
		}

		sz_s += 2;
	}

	cout << "YES";
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
