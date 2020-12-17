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

	vi front(n);

	FOR(i, n) {
		cin >> front[i];
	}

	int m;
	cin >> m;

	vi rear(m);

	FOR(i, m) {
		cin >> rear[i];
	}

	sort(front.begin(), front.end());
	sort(rear.begin(), rear.end(), greater<int>());

	int ratio = 0, cnt = 0;

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < m; ++j) {

			if (rear[j] % front[i] == 0) {

				int curr_ratio = rear[j] / front[i];

				if (curr_ratio > ratio) {
					cnt = 1;
					ratio = curr_ratio;
				}
				else if (curr_ratio == ratio)
					++cnt;

				break;
			}
		}
	}

	cout << cnt;

	return 0;
}