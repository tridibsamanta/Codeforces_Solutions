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

	ll n;
	cin >> n;

	vector<ll> arr(n);
	unordered_map<ll, ll> hm;

	FOR(i, n) {
		cin >> arr[i];
		hm[arr[i]] = i;
	}

	ll v_cnt = 0, p_cnt = 0;

	ll m;
	cin >> m;

	FOR(i, m) {

		ll num;
		cin >> num;

		v_cnt += hm[num] + 1;
		p_cnt += n - hm[num];

	}

	cout << v_cnt << ' ' << p_cnt;

	return 0;
}