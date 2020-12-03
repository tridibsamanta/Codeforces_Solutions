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

	vector<int> height(n);

	int minHeight = INT_MAX, minHeightIdx = -1;
	int maxHeight = INT_MIN, maxHeightIdx = -1;

	for (int i = 0; i < n; ++i) {
		cin >> height[i];

		if (height[i] <= minHeight) {
			minHeight = height[i];
			minHeightIdx = i;
		}

		if (height[i] > maxHeight) {
			maxHeight = height[i];
			maxHeightIdx = i;
		}
	}

	if (maxHeightIdx > minHeightIdx)
		minHeightIdx++;

	int res = ((n - 1) - minHeightIdx) + (maxHeightIdx - 0);
	cout << res;

	return 0;
}