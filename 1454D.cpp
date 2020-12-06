/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;

	w (tc) {

		ll n;
		cin >> n;

		vector<pair<int, ll> > factCount;

		for (ll i = 2; i * i <= n; ++i) {

			int freq = 0;

			while (n % i == 0) {
				++freq;
				n /= i;
			}

			if (freq > 0)
				factCount.emplace_back(make_pair(freq, i));
		}

		if (n > 1)
			factCount.emplace_back(make_pair(1, n));

		sort(factCount.rbegin(), factCount.rend());

		vector<ll> res(factCount[0].first, factCount[0].second);

		for (int i = 1; i < factCount.size(); ++i) {
			for (int j = 0; j < factCount[i].first; ++j) {
				res.back() *= factCount[i].second;
			}
		}

		cout << res.size() << '\n';

		for (auto it : res) {
			cout << it << ' ';
		}

		cout << '\n';
	}

	return 0;
}