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


void solve() {

	int n;
	cin >> n;

	vi arr(n);

	bool desc = false, incr = false;

	FOR (i, 0, n) {
		cin >> arr[i];

		if (i > 0) {
			if (arr[i] < arr[i - 1])
				desc = true;
			else
				incr = true;
		}
	}

	if (!desc) { // array is already sorted in increasing order
		cout << "yes" << '\n' << 1 << ' ' << 1;
		return;
	}

	if (!incr) { // array is already sorted in non-increasing order
		cout << "yes" << '\n' << 1 << ' ' << n;
		return;
	}

	desc = incr = false;
	bool curr_desc = false;

	FOR (i, 1, n) {
		if (arr[i] < arr[i - 1]) {
			if (desc) {
				cout << "no";
				return;
			}
			curr_desc = true;
		}
		else {
			if (curr_desc)
				desc = true;
			incr = true;
		}
	}

	int startPos = -1, endPos = -1;

	FOR (i, 1, n) {

		if (arr[i] < arr[i - 1]) {
			if (startPos == -1)
				startPos = i;
			endPos = i + 1;
		}
		else {
			if (startPos != -1) {
				break;
			}
		}
	}

	if (endPos != n) {
		int maxVal = *max_element(arr.begin() + (startPos - 1), arr.begin() + endPos);

		if (maxVal > arr[endPos]) {
			cout << "no";
			return;
		}
	}

	if (startPos != 1) {
		int minVal = *min_element(arr.begin() + (startPos - 1), arr.begin() + endPos);

		if (minVal < arr[startPos - 2]) {
			cout << "no";
			return;
		}
	}

	cout << "yes" << '\n' << startPos << ' ' << endPos;
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
