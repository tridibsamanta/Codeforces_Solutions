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

	int n, m;
	cin >> n >> m;

	vi seats(m);

	pqmx desc;
	pqmn asc;

	FOR (i, m) {
		cin >> seats[i];
		desc.push(seats[i]);
		asc.push(seats[i]);
	}

	int maxSum = 0, minSum = 0, flag = n;

	while (flag--) {

		int currMax = desc.top();
		maxSum += currMax;

		desc.pop();
		if (--currMax > 0)
			desc.push(currMax);
	}

	flag = n;

	while (flag--) {

		int currMin = asc.top();
		minSum += currMin;

		asc.pop();
		if (--currMin > 0)
			asc.push(currMin);
	}

	cout << maxSum << ' ' << minSum;
}

int main() {

	FIO;

	int tc = 1;
	// cin >> tc;
	while (tc--) {

		solve();
		cout << '\n';
	}

	return 0;
}
