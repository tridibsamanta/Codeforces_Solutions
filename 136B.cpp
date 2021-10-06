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


int pow3[20];

void precompute() {
	pow3[0] = 1;
	FOR (i, 1, 20) {
		pow3[i] = pow3[i - 1] * 3;
	}
}

string changeBase(int n, int b) {
	string res = "";

	while (n > 0) {
		if (n % b == 0)
			res += '0';
		else
			res += to_string(n % b);

		n /= b;
	}

	reverse(res.begin(), res.end());
	return res;
}

int changeBaseToDecimal(string s) {
	int num = 0;
	int m = sz(s);

	RFOR (i, m, 0) {
		if (s[i] != '0') {
			num += pow3[m - i - 1];

			if (s[i] == '2')
				num += pow3[m - i - 1];
		}
	}

	return num;
}

char getTernaryValue(char c1, char c2) {
	if (c1 == '0' && c2 == '0')
		return '0';
	if (c1 == '0' && c2 == '1')
		return '1';
	if (c1 == '1' && c2 == '0')
		return '2';
	if (c1 == '0' && c2 == '2')
		return '2';
	if (c1 == '2' && c2 == '0')
		return '1';
	if (c1 == '1' && c2 == '1')
		return '0';
	if (c1 == '2' && c2 == '2')
		return '0';
	if (c1 == '1' && c2 == '2')
		return '1';
	if (c1 == '2' && c2 == '1')
		return '2';
}

void solve() {
	int a, c;
	cin >> a >> c;

	string s1 = changeBase(a, 3);
	string s2 = changeBase(c, 3);

	if (sz(s1) < sz(s2)) {
		string t((sz(s2) - sz(s1)), '0');
		s1 = t.append(s1);
	}
	if (sz(s2) < sz(s1)) {
		string t((sz(s1) - sz(s2)), '0');
		s2 = t.append(s2);
	}

	// print(s1); print(s2);

	string b = "";

	RFOR (i, sz(s1), 0) {
		b += getTernaryValue(s1[i], s2[i]);
	}

	reverse(all(b));

	cout << changeBaseToDecimal(b);
}

int32_t main() {

	FIO;

	precompute();

	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
