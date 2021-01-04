/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull					unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define pb					push_back
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define all(c)				(c).begin(), (c).end()
#define sz(x)				(int)(x).size()
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pqmx				priority_queue<int>
#define pqmn				priority_queue<int, vector<int>, greater<int> >


void solve() {

	int n;
	cin >> n;

	vi nums(n);

	FOR (i, n) {
		cin >> nums[i];
	}

	sort(nums.rbegin(), nums.rend());

	ll score = 0;

	FOR (i, n) {

		if (i % 2 == 0) {
			if (nums[i] % 2 == 0)
				score += nums[i];
		}
		else {
			if (nums[i] % 2 == 1)
				score -= nums[i];
		}
	}

	if (score == 0)
		cout << "Tie";
	else if (score > 0)
		cout << "Alice";
	else
		cout << "Bob";
}

int main() {

	FIO;

	int tc = 1;
	cin >> tc;
	while (tc--) {

		solve();
		cout << '\n';
	}

	return 0;
}
