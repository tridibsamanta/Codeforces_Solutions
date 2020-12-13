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

	int n;
	cin >> n;

	vector<int> heights(n);
	FOR(i, n) {
		cin >> heights[i];
	}

	int minDiff = INT_MAX, idx1 = -1, idx2 = -1;

	for (int i = 1; i < n; ++i) {
		if (abs(heights[i] - heights[i - 1]) < minDiff) {
			minDiff = abs(heights[i] - heights[i - 1]);
			idx1 = i;
			idx2 = i + 1;
		}
	}

	if (abs(heights[0] - heights[n - 1]) < minDiff) {
		idx1 = n;
		idx2 = 1;
	}

	cout << idx1 << ' ' << idx2;

	return 0;
}